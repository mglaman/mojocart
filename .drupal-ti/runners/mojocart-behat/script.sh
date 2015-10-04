#!/bin/bash
# @file
# Behat integration - Script step.

set -e $DRUPAL_TI_DEBUG

# Ensure we are in the right directory.
cd "$DRUPAL_TI_DRUPAL_DIR"

# If this isn't an upgrade, we test if any features are overridden.
if [[ "$UPGRADE" == none ]]
then
	"$TRAVIS_BUILD_DIR"/scripts/check-overridden.sh
fi

mojocart_header Running tests: $TRAVIS_BEHAT

# Decide if we are running the Panopoly or MojoCart test suite.
if [[ "$TRAVIS_BEHAT" == "mojocart" ]]; then
	cd "$DRUPAL_TI_BEHAT_DIR"

else
	cd "$DRUPAL_TI_BEHAT_PANOPOLY_DIR"
fi

# Copy into place because it doesn't come with panopoly_test.
cp -f "$TRAVIS_BUILD_DIR"/"$DRUPAL_TI_BEHAT_YML" "$DRUPAL_TI_BEHAT_YML"

# This replaces environment vars from $DRUPAL_TI_BEHAT_YML into 'behat.yml'.
drupal_ti_replace_behat_vars

ARGS=( $DRUPAL_TI_BEHAT_ARGS )

# First, run all the tests in Firefox.
./bin/behat "${ARGS[@]}"

# Then run some Chrome-only tests.
./bin/behat -p chrome "${ARGS[@]}"
