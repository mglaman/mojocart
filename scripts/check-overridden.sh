#!/bin/bash

set -e $DRUPAL_TI_DEBUG

: ${DRUSH:=drush}
: ${DRUSH_ARGS:="--root=$DRUPAL_TI_DRUPAL_DIR --uri=$DRUPAL_TI_WEBSERVER_URL:$DRUPAL_TI_WEBSERVER_PORT"}

# Panopoly Features
PANOPOLY_FEATURES="panopoly_admin panopoly_core panopoly_demo panopoly_images panopoly_magic panopoly_pages panopoly_search panopoly_theme panopoly_users panopoly_widgets panopoly_wysiwyg"

# MojoCart Features
MOJOCART_FEATURES="mojocart_catalog mojocart_products"

# TODO: We should make sure that 'diff' is downloaded first!
$DRUSH $DRUSH_ARGS en -y diff

OVERRIDDEN=0
for panopoly_feature in $PANOPOLY_FEATURES; do
  echo "Checking $panopoly_feature..."
  if $DRUSH $DRUSH_ARGS features-diff $panopoly_feature 2>&1 | grep -v 'Feature is in its default state'; then
    OVERRIDDEN=1
  fi
done
for mojocart_feature in $MOJOCART_FEATURES; do
  echo "Checking $mojocart_feature..."
  if $DRUSH $DRUSH_ARGS features-diff $mojocart_feature 2>&1 | grep -v 'Feature is in its default state'; then
    OVERRIDDEN=1
  fi
done

exit $OVERRIDDEN
