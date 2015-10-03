#!/bin/bash
# @file
# Behat integration - Install step.

set -e $DRUPAL_TI_DEBUG

# Ensure drush webserver can be started for PHP 5.3 / hhvm.
drupal_ti_ensure_php_for_drush_webserver

# Ensure that drush and addons are installed.
mojocart_header Installing Drush
mojocart_ensure_drush

# Ensure the distribution is linked into the code base.
# @todo Use drupal_ti_ensure_distribution once available.
mojocart_ensure_distribution

# Build the distribution via drush make files.
mojocart_build_distribution

# Install the behat extension.
mojocart_header Installing Behat
# Decide if we are running the Panopoly or MojoCart test suite.
if [[ "$TRAVIS_BEHAT" == "mojocart" ]]; then
	cd "$DRUPAL_TI_BEHAT_DIR"

else
	cd "$DRUPAL_TI_BEHAT_PANOPOLY_DIR"
fi
composer install --no-interaction --prefer-source --dev

# Disable sendmail
# @todo Move upstream.
echo sendmail_path=`which true` >> ~/.phpenv/versions/$(phpenv version-name)/etc/php.ini

# Use some optimized PHP and mysql settings.
mojocart_optimize
