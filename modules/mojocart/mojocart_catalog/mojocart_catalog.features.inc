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
    $data['product_display']->options['data_alter_callbacks']['search_api_alter_add_aggregation']['settings']['fields']['search_api_aggregation_2']['description'] = 'Name property of Categories as fulltext'; /* WAS: 'Name property of Catalog as fulltext' */
    $data['product_display']->options['data_alter_callbacks']['search_api_alter_add_aggregation']['settings']['fields']['search_api_aggregation_2']['fields'][0] = 'field_featured_categories:name'; /* WAS: 'field_catalog:name' */
    $data['product_display']->options['data_alter_callbacks']['search_api_alter_add_aggregation']['settings']['fields']['search_api_aggregation_2']['name'] = 'Categories name (Fulltext)'; /* WAS: 'Catalog name (Fulltext)' */
    $data['product_display']->options['fields']['field_catalog:name']['type'] = 'text'; /* WAS: 'string' */
    $data['product_display']->options['fields']['field_catalog:tid'] = array(
      'type' => 'integer',
    ); /* WAS: '' */
    $data['product_display']->options['fields']['field_product:type'] = array(
      'type' => 'list<string>',
    ); /* WAS: '' */
    unset($data['product_display']->options['additional fields']);
    unset($data['product_display']->options['data_alter_callbacks']['search_api_alter_add_aggregation']['settings']['fields']['search_api_aggregation_3']);
    unset($data['product_display']->options['fields']['field_catalog']);
    unset($data['product_display']->options['fields']['search_api_aggregation_3']);
  }
}
