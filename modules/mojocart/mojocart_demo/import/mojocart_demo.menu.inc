<?php

/**
 * @file
 * Migrations for Menu items.
 */

class MojoCartDemoMenu extends MojoCartDemoMigrateBase {

  public function __construct(array $arguments) {
    parent::__construct($arguments);
    $this->description = t('Import menu items.');
    $this->dependencies = array('MojoCartDemoProductDisplays');

    // Create a map object for tracking the relationships between source rows.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'mlid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'ID of destination link',
        ),
      ),
      MigrateDestinationMenuLinks::getKeySchema()
    );

    $this->setCsvSource('menu.csv');

    $this->destination = new MigrateDestinationMenuLinks();

    $this->addFieldMapping('menu_name')->defaultValue('main-menu');
    $this->addFieldMapping('plid', 'ref_parent')->sourceMigration($this->getMachineName());
    $this->addFieldMapping('link_path', 'path');
    $this->addFieldMapping('router_path')->defaultValue('taxonomy/term/%');
    $this->addFieldMapping('link_title', 'title');
    $this->addFieldMapping('external')->defaultValue('0');
    $this->addFieldMapping('expanded')->defaultValue('0');
    $this->addFieldMapping('weight','weight');
    $this->addFieldMapping('customized')->defaultValue('1');
    $this->addFieldMapping('has_children')->defaultValue('0');
    $this->addFieldMapping('depth')->defaultValue('1');

    $this->addUnmigratedDestinations(array('module', 'hidden','options','p1', 'p2', 'p3', 'p4', 'p5', 'p6', 'p7', 'p8', 'p9', 'updated'));
  }

  function prepareRow($row) {
    // Convert the alias to the node path.
    $term_path = drupal_lookup_path('source', $row->path);
    if ($term_path == FALSE) {
      return FALSE;
    }

    $row->path = $term_path;
  }

  public function csvcolumns() {
    $columns[0] = array('mlid', 'Menu link ID');
    $columns[1] = array('path', 'Path');
    $columns[2] = array('title', 'Title');
    $columns[3] = array('ref_parent', 'Parent');
    $columns[4] = array('weight', 'Weight');
    return $columns;
  }

}
