<?php
/**
 * @file
 * mojocart_products.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function mojocart_products_defaultconfig_features() {
  return array(
    'mojocart_products' => array(
      'user_default_permissions' => 'user_default_permissions',
    ),
  );
}

/**
 * Implements hook_defaultconfig_user_default_permissions().
 */
function mojocart_products_defaultconfig_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer panelizer node product_display breadcrumbs'.
  $permissions['administer panelizer node product_display breadcrumbs'] = array(
    'name' => 'administer panelizer node product_display breadcrumbs',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node product_display content'.
  $permissions['administer panelizer node product_display content'] = array(
    'name' => 'administer panelizer node product_display content',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node product_display context'.
  $permissions['administer panelizer node product_display context'] = array(
    'name' => 'administer panelizer node product_display context',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node product_display defaults'.
  $permissions['administer panelizer node product_display defaults'] = array(
    'name' => 'administer panelizer node product_display defaults',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node product_display layout'.
  $permissions['administer panelizer node product_display layout'] = array(
    'name' => 'administer panelizer node product_display layout',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node product_display overview'.
  $permissions['administer panelizer node product_display overview'] = array(
    'name' => 'administer panelizer node product_display overview',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node product_display settings'.
  $permissions['administer panelizer node product_display settings'] = array(
    'name' => 'administer panelizer node product_display settings',
    'roles' => array(),
    'module' => 'panelizer',
  );

  return $permissions;
}
