<?php
/**
 * @file
 * mojocart_products.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function mojocart_products_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:product_display:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'product_display';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = 'page-product-display';
  $panelizer->css = '';
  $panelizer->pipeline = 'ipe';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'radix_brenham_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '442d9c46-0b00-437a-a38c-9bb4770bb4b3';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-02526013-9485-4293-ace5-671e14f4ae77';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'panelizer',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '02526013-9485-4293-ace5-671e14f4ae77';
  $display->content['new-02526013-9485-4293-ace5-671e14f4ae77'] = $pane;
  $display->panels['contentmain'][0] = 'new-02526013-9485-4293-ace5-671e14f4ae77';
  $pane = new stdClass();
  $pane->pid = 'new-56651287-24ee-4d46-a731-099fb4f32bf3';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_featured_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'panopoly_image_full',
      'image_link' => '',
    ),
    'context' => array(),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '56651287-24ee-4d46-a731-099fb4f32bf3';
  $display->content['new-56651287-24ee-4d46-a731-099fb4f32bf3'] = $pane;
  $display->panels['sidebar'][0] = 'new-56651287-24ee-4d46-a731-099fb4f32bf3';
  $pane = new stdClass();
  $pane->pid = 'new-7b76379b-aee4-4c07-82e7-9e13451edfd1';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_field_extra';
  $pane->subtype = 'node:product:title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
    'context' => 'panelizer',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '7b76379b-aee4-4c07-82e7-9e13451edfd1';
  $display->content['new-7b76379b-aee4-4c07-82e7-9e13451edfd1'] = $pane;
  $display->panels['sidebar'][1] = 'new-7b76379b-aee4-4c07-82e7-9e13451edfd1';
  $pane = new stdClass();
  $pane->pid = 'new-b900d221-687f-42f6-834f-7c0b60808efc';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_field_extra';
  $pane->subtype = 'node:product:commerce_price';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'b900d221-687f-42f6-834f-7c0b60808efc';
  $display->content['new-b900d221-687f-42f6-834f-7c0b60808efc'] = $pane;
  $display->panels['sidebar'][2] = 'new-b900d221-687f-42f6-834f-7c0b60808efc';
  $pane = new stdClass();
  $pane->pid = 'new-b8b38f83-f477-4760-9a70-38315b018737';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_product';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'commerce_cart_add_to_cart_form',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'show_quantity' => 1,
      'default_quantity' => '1',
      'combine' => 1,
      'show_single_product_attributes' => 0,
      'line_item_type' => 'product',
    ),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'b8b38f83-f477-4760-9a70-38315b018737';
  $display->content['new-b8b38f83-f477-4760-9a70-38315b018737'] = $pane;
  $display->panels['sidebar'][3] = 'new-b8b38f83-f477-4760-9a70-38315b018737';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:product_display:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:product_display:default:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'product_display';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'default';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'f346fb24-a34d-4f6f-a164-bb2d985d4c40';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ba04fb4c-0749-40af-9609-53cd2d5d901e';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'panelizer',
  );
  $pane->cache = array();
  $pane->style = array();
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'ba04fb4c-0749-40af-9609-53cd2d5d901e';
  $display->content['new-ba04fb4c-0749-40af-9609-53cd2d5d901e'] = $pane;
  $display->panels['center'][0] = 'new-ba04fb4c-0749-40af-9609-53cd2d5d901e';
  $pane = new stdClass();
  $pane->pid = 'new-68f263b7-0c94-4431-b4c1-bbd9742af46a';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_product';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'commerce_cart_add_to_cart_form',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'show_quantity' => FALSE,
      'default_quantity' => 1,
      'combine' => TRUE,
      'show_single_product_attributes' => FALSE,
      'line_item_type' => 'product',
    ),
    'context' => 'panelizer',
  );
  $pane->cache = array();
  $pane->style = array();
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '68f263b7-0c94-4431-b4c1-bbd9742af46a';
  $display->content['new-68f263b7-0c94-4431-b4c1-bbd9742af46a'] = $pane;
  $display->panels['center'][1] = 'new-68f263b7-0c94-4431-b4c1-bbd9742af46a';
  $pane = new stdClass();
  $pane->pid = 'new-9765ca32-4829-4033-a087-2ec222f14667';
  $pane->panel = 'center';
  $pane->type = 'node_links';
  $pane->subtype = 'node_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => FALSE,
    'override_title_text' => '',
    'build_mode' => 'default',
    'identifier' => '',
    'link' => TRUE,
    'context' => 'panelizer',
  );
  $pane->cache = array();
  $pane->style = array();
  $pane->css = array(
    'css_class' => 'link-wrapper',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9765ca32-4829-4033-a087-2ec222f14667';
  $display->content['new-9765ca32-4829-4033-a087-2ec222f14667'] = $pane;
  $display->panels['center'][2] = 'new-9765ca32-4829-4033-a087-2ec222f14667';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-9765ca32-4829-4033-a087-2ec222f14667';
  $panelizer->display = $display;
  $export['node:product_display:default:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:product_display:default:teaser';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'product_display';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'teaser';
  $panelizer->css_class = 'page-teaser';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'radix_brenham_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
      'header' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'c235be5d-6391-41ca-86d9-d63f164632de';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-17d0201a-b740-4822-9d8e-7e02de2aba5a';
  $pane->panel = 'contentmain';
  $pane->type = 'node_title';
  $pane->subtype = 'node_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'link' => 1,
    'markup' => 'h4',
    'id' => '',
    'class' => '',
    'context' => 'panelizer',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '17d0201a-b740-4822-9d8e-7e02de2aba5a';
  $display->content['new-17d0201a-b740-4822-9d8e-7e02de2aba5a'] = $pane;
  $display->panels['contentmain'][0] = 'new-17d0201a-b740-4822-9d8e-7e02de2aba5a';
  $pane = new stdClass();
  $pane->pid = 'new-b36ff3f6-bb8e-4b8b-8dff-1d35aa7b25c4';
  $pane->panel = 'header';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_featured_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'panopoly_image_full',
      'image_link' => 'content',
    ),
    'context' => array(),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b36ff3f6-bb8e-4b8b-8dff-1d35aa7b25c4';
  $display->content['new-b36ff3f6-bb8e-4b8b-8dff-1d35aa7b25c4'] = $pane;
  $display->panels['header'][0] = 'new-b36ff3f6-bb8e-4b8b-8dff-1d35aa7b25c4';
  $pane = new stdClass();
  $pane->pid = 'new-efd31a91-72d7-4a62-88b7-436f448daff6';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_field_extra';
  $pane->subtype = 'node:product:commerce_price';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'efd31a91-72d7-4a62-88b7-436f448daff6';
  $display->content['new-efd31a91-72d7-4a62-88b7-436f448daff6'] = $pane;
  $display->panels['sidebar'][0] = 'new-efd31a91-72d7-4a62-88b7-436f448daff6';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:product_display:default:teaser'] = $panelizer;

  return $export;
}
