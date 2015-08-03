<?php
/**
 * @file
 * mojocart_catalog.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function mojocart_catalog_taxonomy_default_vocabularies() {
  return array(
    'catalog' => array(
      'name' => 'Catalog',
      'machine_name' => 'catalog',
      'description' => 'Products assigned to terms will appear in the catalog.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
