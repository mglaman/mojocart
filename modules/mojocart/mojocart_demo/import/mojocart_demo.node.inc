<?php

/**
 * @file
 * Migrations for MojoCart demo nodes
 */

class MojoCartDemoProductDisplays extends MojoCartDemoMigrateBase {
  /**
   * {@inheritdoc}
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);

    $this->description = t('Import product nodes.');
    $this->dependencies = array(
      'MojoCartDemoProducts',
    );

    // Create a map object for tracking the relationships between source rows.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'title' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $this->setCsvSource('nodes.csv');

    $this->destination = new MigrateDestinationNode('product_display');

    $this->addFieldMapping('uid', 'uid')->defaultValue(1);

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_featured_image', 'image');
    $this->addFieldMapping('field_featured_image:file_replace')
         ->defaultValue(FILE_EXISTS_REPLACE);
    // For now re-use Panopoly Demo images
    $this->addFieldMapping('field_featured_image:source_dir')
         ->defaultValue(drupal_get_path('module', 'panopoly_demo') . '/import/images');
    $this->addFieldMapping('body', 'description');
    $this->addFieldMapping('body:summary', 'excerpt');
    $this->addFieldMapping('field_catalog', 'category');
    $this->addFieldMapping('field_catalog:create_term')
         ->defaultValue(TRUE);
    $this->addFieldMapping('field_product', 'products');
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    entity_get_controller('commerce_product')->resetCache();

    $products = array();
    foreach (explode(', ', $row->sku) as $sku) {
      $product = commerce_product_load_by_sku($sku);
      if (!$product) {
        throw new MigrateException(t('Invalid product returned for @sku', array('@sku' => $sku)));
      }
      $products[] = $product->product_id;
    }
    $row->products = $products;
  }

  /**
   * {@inheritdoc}
   */
  function csvColumns() {
    $columns[0] = array('title', 'Title');
    $columns[1] = array('image', 'Image');
    $columns[2] = array('category', 'Category');
    $columns[3] = array('sku', 'SKU');
    $columns[4] = array('description', 'Description');
    return $columns;
  }
}
