<?php
/**
 * @file
 * mojocart_catalog.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mojocart_catalog_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function mojocart_catalog_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index_alter().
 */
function mojocart_catalog_default_search_api_index_alter(&$data) {
  if (isset($data['product_display'])) {
    $data['product_display']->options['data_alter_callbacks']['search_api_alter_add_aggregation']['settings']['fields']['search_api_aggregation_2']['description'] = 'Name property of Categories as fulltext'; /* WAS: 'Name property of Catalog Section as fulltext' */
    $data['product_display']->options['data_alter_callbacks']['search_api_alter_add_aggregation']['settings']['fields']['search_api_aggregation_2']['fields'][0] = 'field_featured_categories:name'; /* WAS: 'field_catalog_section:name' */
    $data['product_display']->options['data_alter_callbacks']['search_api_alter_add_aggregation']['settings']['fields']['search_api_aggregation_2']['name'] = 'Categories name (Fulltext)'; /* WAS: 'Catalog Section name (Fulltext)' */
    $data['product_display']->options['fields']['field_product:type'] = array(
      'type' => 'list<string>',
    ); /* WAS: '' */
    unset($data['product_display']->options['additional fields']);
    unset($data['product_display']->options['data_alter_callbacks']['search_api_alter_add_aggregation']['settings']['fields']['search_api_aggregation_3']);
    unset($data['product_display']->options['fields']['search_api_aggregation_3']);
  }
}

/**
 * Implements hook_default_search_api_server_alter().
 */
function mojocart_catalog_default_search_api_server_alter(&$data) {
  if (isset($data['database_server'])) {
    $data['database_server']->options['indexes']['product_display'] = array(
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
    ); /* WAS: '' */
  }
}
