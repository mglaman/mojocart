<?php
/**
 * @file
 * mojocart_catalog.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function mojocart_catalog_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: search_api_index
  $overrides["search_api_index.product_display.options|additional fields"]["DELETED"] = TRUE;
  $overrides["search_api_index.product_display.options|data_alter_callbacks|search_api_alter_add_aggregation|settings|fields|search_api_aggregation_2|description"] = 'Name property of Categories as fulltext';
  $overrides["search_api_index.product_display.options|data_alter_callbacks|search_api_alter_add_aggregation|settings|fields|search_api_aggregation_2|fields|0"] = 'field_featured_categories:name';
  $overrides["search_api_index.product_display.options|data_alter_callbacks|search_api_alter_add_aggregation|settings|fields|search_api_aggregation_2|name"] = 'Categories name (Fulltext)';
  $overrides["search_api_index.product_display.options|data_alter_callbacks|search_api_alter_add_aggregation|settings|fields|search_api_aggregation_3"]["DELETED"] = TRUE;
  $overrides["search_api_index.product_display.options|fields|field_catalog"]["DELETED"] = TRUE;
  $overrides["search_api_index.product_display.options|fields|field_catalog:name|type"] = 'text';
  $overrides["search_api_index.product_display.options|fields|field_catalog:tid"] = array(
    'type' => 'integer',
  );
  $overrides["search_api_index.product_display.options|fields|field_product:type"] = array(
    'type' => 'list<string>',
  );
  $overrides["search_api_index.product_display.options|fields|search_api_aggregation_3"]["DELETED"] = TRUE;

 return $overrides;
}
