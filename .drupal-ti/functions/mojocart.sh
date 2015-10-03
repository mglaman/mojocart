#!/bin/bash
# @file
# Common functionality for panopoly distribution.

#
# Ensures that the right drush version is installed.
#
function mojocart_ensure_drush() {
	# This function is re-entrant.
	if [ -r "$TRAVIS_BUILD_DIR/../drupal_ti-mojocart-drush-installed" ]
	then
		return
	fi

	drupal_ti_ensure_drush

	# Download addon.
	drush dl -y drupalorg_drush-7.x-1.x-dev --destination=$HOME/.drush
	drush cc drush

	touch "$TRAVIS_BUILD_DIR/../drupal_ti-mojocart-drush-installed"
}

#
# Ensures that the distribution is linked into the Drupal code base.
# @todo Move to upstream.
#
function mojocart_ensure_distribution() {
	# Ensure we are in the right directory.
	mkdir -p "$DRUPAL_TI_DRUPAL_BASE"
	cd "$DRUPAL_TI_DRUPAL_BASE"

	# This function is re-entrant.
	if [ -L "$DRUPAL_TI_DISTRIBUTION_NAME" ]
	then
		return
	fi

	# Find absolute path to module.
	MODULE_DIR=$(cd "$TRAVIS_BUILD_DIR"; pwd)

	# Point distribution into the drupal installation directory.
	ln -sf "$MODULE_DIR" "$DRUPAL_TI_DISTRIBUTION_NAME"
}

#
# Ensures that the distribution is build.
#
function mojocart_build_distribution() {
	# Ensure we are in the right directory.
	cd "$DRUPAL_TI_DRUPAL_BASE"

	# Build Codebase
	mkdir profiles
	mv mojocart profiles/
	mkdir drupal
	mv profiles drupal/

	# Build the current branch.
	mojocart_header Building MojoCart from current branch
	cd drupal
	drush make --yes profiles/mojocart/drupal-org-core.make --prepare-install
	drush make --yes profiles/mojocart/drupal-org.make --no-core --contrib-destination=profiles/mojocart
#	if [[ "$UPGRADE" != none ]]; then
#		drush dl panopoly_demo-1.x-dev
#	fi
	drush dl diff
	mkdir -p sites/default/private/files
	mkdir -p sites/default/private/temp

	# Verify that all the .make files will work on Drupal.org.
	mojocart_header Verifying .make file
	drush verify-makefile profiles/mojocart/drupal-org.make
	find profiles/mojocart/modules -name \*.make -print0 | xargs -0 -n1 drush verify-makefile

	# Download an old version to test upgrading from.
	if [[ "$UPGRADE" != none ]]; then
		(
			cd "$DRUPAL_TI_DRUPAL_BASE"
			mojocart_header Downloading MojoCart $UPGRADE
			drush dl mojocart-$UPGRADE
		)
	fi
}

#
# Overwrite functions/drupal.sh install function.
# @todo Upstream tries to check for drupal dir existing, which fails
#				this. Use a file instead.
#
function drupal_ti_ensure_drupal() {
	# This function is re-entrant.
	if [ -r "$TRAVIS_BUILD_DIR/../drupal_ti-drupal-installed" ]
	then
		return
	fi

	# HHVM env is broken: https://github.com/travis-ci/travis-ci/issues/2523.
	PHP_VERSION=`phpenv version-name`
	if [ "$PHP_VERSION" = "hhvm" ]
	then
		# Create sendmail command, which links to /bin/true for HHVM.
		BIN_DIR="$TRAVIS_BUILD_DIR/../drupal_travis/bin"
		mkdir -p "$BIN_DIR"
		ln -s $(which true) "$BIN_DIR/sendmail"
		export PATH="$BIN_DIR:$PATH"
	fi

	# Create database and install Drupal.
	mysql -e "create database $DRUPAL_TI_DB"

	mkdir -p "$DRUPAL_TI_DRUPAL_BASE"
	cd "$DRUPAL_TI_DRUPAL_BASE"

	drupal_ti_install_drupal
	touch "$TRAVIS_BUILD_DIR/../drupal_ti-drupal-installed"
}

#
# Overwrite environments/drupal-7.sh install function
#
function drupal_ti_install_drupal() {
	# Do the site install (either the current revision or old for the upgrade).
	mojocart_header Installing Drupal
	if [[ "$UPGRADE" == none ]]
	then
		cd drupal
	else
		cd mojocart-$UPGRADE
		drush dl panopoly_demo-$UPGRADE_DEMO_VERSION
		# Relax checks as drush site-install has errors for update 1.13.
		set +e
	fi
	php -d sendmail_path=$(which true) ~/.composer/vendor/bin/drush.php --yes site-install mojocart --db-url="$DRUPAL_TI_DB_URL" --account-name=admin --account-pass=admin --site-mail=admin@example.com --site-name="MojoCart"
	drush vset -y file_private_path "sites/default/private/files"
	drush vset -y file_temporary_path "sites/default/private/temp"
  drush en -y diff

	# Switch to the MojoCart platform built from Git (if we aren't there already).
	cd ../drupal

	# If we're an upgrade test, run the upgrade process.
	if [[ "$UPGRADE" != none ]]
	then
		# Use strict checking again.
		set -e

		mojocart_header Upgrading to latest version
		cp -a ../mojocart-$UPGRADE/sites/default/* sites/default/
		drush updb --yes
		drush cc all
	fi
}

#
# Use some optimized settings to make tests faster.
#
function mojocart_optimize() {
	# Enable APC
	if [[ $TRAVIS_PHP_VERSION < "5.5" ]]; then
		echo "extension=apc.so" >> ~/.phpenv/versions/$(phpenv version-name)/etc/php.ini
		echo "apc.shm_size=256M" >> ~/.phpenv/versions/$(phpenv version-name)/etc/php.ini
	fi

	# Increase the MySQL connection timeout on the PHP end.
	echo "mysql.connect_timeout=3000" >> ~/.phpenv/versions/$(phpenv version-name)/etc/php.ini
	echo "default_socket_timeout=3000" >> ~/.phpenv/versions/$(phpenv version-name)/etc/php.ini

	# Increase the MySQL server timetout and packet size.
	mysql -e "SET GLOBAL wait_timeout = 36000;"
	mysql -e "SET GLOBAL max_allowed_packet = 33554432;"
}

#
# Prints a message about the section of the script.
#
function mojocart_header() {
	echo
	echo "** $@"
	echo
}
