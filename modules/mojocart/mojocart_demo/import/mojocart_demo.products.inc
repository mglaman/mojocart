<?php

/**
 * @file
 * Migrations for MojoCart demo nodes
 */

class MojoCartDemoProducts extends MojoCartDemoMigrateBase {
  /**
   * {@inheritdoc}
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);
    $this->description = t('Import products.');

    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'sku' => array(
          'type' => 'varchar',
          'length' => 32,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationEntityAPI::getKeySchema('commerce_product')
    );

    $this->setCsvSource('products.csv');

    $this->destination = new MigrateDestinationEntityAPI('commerce_product', 'product');

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('sku', 'sku');
    $this->addFieldMapping('commerce_price', 'price');
    $this->addFieldMapping('status', 'status')->defaultValue(1);
    $this->addFieldMapping('uid', 'uid')->defaultValue(1);
    $this->addFieldMapping('language', 'language')->defaultValue(LANGUAGE_NONE);
  }

  /**
   * {@inheritdoc}
   */
  public function csvColumns() {
    $columns[0] = array('title', 'Title');
    $columns[1] = array('sku', 'SKU');
    $columns[2] = array('price', 'Price');
    return $columns;
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    $row->is_new = 1;
    $row->status = 1;
    $row->uid = 1;
    $row->language = LANGUAGE_NONE;
    $row->sku = trim($row->sku);
  }
}
