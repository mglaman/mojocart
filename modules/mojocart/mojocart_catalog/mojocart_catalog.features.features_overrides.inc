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
  $overrides["search_api_index.product_display.options|fields|field_product:type"] = array(
    'type' => 'list<string>',
  );
  $overrides["search_api_index.product_display.options|fields|search_api_aggregation_3"]["DELETED"] = TRUE;

  // Exported overrides for: search_api_server
  $overrides["search_api_server.database_server.options|indexes|product_display"] = array(
    'nid' => array(
      'table' => 'search_api_db_product_display',
      'column' => 'nid',
      'type' => 'integer',
      'boost' => '1.0',
    ),
    'type' => array(
      'table' => 'search_api_db_product_display',
      'column' => 'type',
      'type' => 'string',
      'boost' => '1.0',
    ),
    'title' => array(
      'table' => 'search_api_db_product_display',
      'column' => 'title',
      'type' => 'string',
      'boost' => '1.0',
    ),
    'status' => array(
      'table' => 'search_api_db_product_display',
      'column' => 'status',
      'type' => 'integer',
      'boost' => '1.0',
    ),
    'created' => array(
      'table' => 'search_api_db_product_display',
      'column' => 'created',
      'type' => 'date',
      'boost' => '1.0',
    ),
    'changed' => array(
      'table' => 'search_api_db_product_display',
      'column' => 'changed',
      'type' => 'date',
      'boost' => '1.0',
    ),
    'field_product' => array(
      'table' => 'search_api_db_product_display_field_product',
      'column' => 'value',
      'type' => 'list<integer>',
      'boost' => '1.0',
    ),
    'field_featured_categories' => array(
      'table' => 'search_api_db_product_display_field_featured_categories',
      'column' => 'value',
      'type' => 'list<integer>',
      'boost' => '1.0',
    ),
    'search_api_language' => array(
      'table' => 'search_api_db_product_display',
      'column' => 'search_api_language',
      'type' => 'string',
      'boost' => '1.0',
    ),
    'search_api_aggregation_1' => array(
      'table' => 'search_api_db_product_display_text',
      'type' => 'text',
      'boost' => '1.0',
    ),
    'search_api_aggregation_2' => array(
      'table' => 'search_api_db_product_display_text',
      'type' => 'text',
      'boost' => '1.0',
    ),
    'field_featured_categories:name' => array(
      'table' => 'search_api_db_product_display_field_featured_categories_name',
      'column' => 'value',
      'type' => 'list<string>',
      'boost' => '1.0',
    ),
    'field_product:commerce_price:amount_decimal' => array(
      'table' => 'search_api_db_product_display_field_product_commerce_price_amo',
      'column' => 'value',
      'type' => 'list<decimal>',
      'boost' => '1.0',
    ),
    'field_product:type' => array(
      'table' => 'search_api_db_product_display_field_product_type',
      'column' => 'value',
      'type' => 'list<string>',
      'boost' => '1.0',
    ),
    'field_catalog_section' => array(
      'table' => 'search_api_db_product_display',
      'column' => 'field_catalog_section',
      'type' => 'integer',
      'boost' => '1.0',
    ),
    'field_catalog_section:name' => array(
      'table' => 'search_api_db_product_display',
      'column' => 'field_catalog_section_name',
      'type' => 'string',
      'boost' => '1.0',
    ),
  );

 return $overrides;
}
