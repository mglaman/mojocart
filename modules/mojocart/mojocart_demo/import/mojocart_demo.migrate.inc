<?php

/**
 * @file
 * Basic class for MojoCart demo
 */

interface MojoCartMigrationInterface {
  /**
   * Maps CSV column headers.
   *
   * @return array
   *    Array of mappings
   */
  public function csvColumns();
}

abstract class MojoCartDemoMigrateBase extends Migration implements MojoCartMigrationInterface{

  /**
   * Base import path
   * @var string
   */
  protected $import_path;

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments = array()) {

    $this->import_path = drupal_get_path('module', 'mojocart_demo') . '/import/data';

    parent::__construct($arguments);
  }


  /**
   * {@inheritdoc}
   */
  public function processImport(array $options = array()) {
    parent::processImport($options);
    // Do not force menu rebuilding. Otherwise pathauto will try to rebuild
    // in each node_insert invocation.
    variable_set('menu_rebuild_needed', FALSE);
  }

  /**
   * Sets the migration source.
   *
   * @param $file
   * @param bool|TRUE $headers
   */
  public function setCsvSource($file, $headers = TRUE) {
    $this->source = new MigrateSourceCSV($this->import_path . '/' . $file, $this->csvcolumns(), array('header_rows' => $headers));
  }
}
