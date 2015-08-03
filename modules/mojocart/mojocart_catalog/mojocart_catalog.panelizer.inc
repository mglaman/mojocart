<?php
/**
 * @file
 * mojocart_catalog.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function mojocart_catalog_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'taxonomy_term:catalog:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'taxonomy_term';
  $panelizer->panelizer_key = 'catalog';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'radix_brenham';
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
  $display->title = '';
  $display->uuid = '052be1f4-b254-4b2c-bb3a-f4e16b598e59';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-7911a958-d0fc-4ca9-b599-12abf5ff5938';
  $pane->panel = 'contentmain';
  $pane->type = 'term_description';
  $pane->subtype = 'term_description';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->uuid = '7911a958-d0fc-4ca9-b599-12abf5ff5938';
  $display->content['new-7911a958-d0fc-4ca9-b599-12abf5ff5938'] = $pane;
  $display->panels['contentmain'][0] = 'new-7911a958-d0fc-4ca9-b599-12abf5ff5938';
  $pane = new stdClass();
  $pane->pid = 'new-f8d72c97-a8b5-4154-81eb-8b0af97c70f6';
  $pane->panel = 'contentmain';
  $pane->type = 'views_panes';
  $pane->subtype = 'catalog-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'use_pager' => 1,
    'pager_id' => '0',
    'items_per_page' => '12',
    'view_settings' => 'fields',
    'header_type' => 'none',
    'view_mode' => 'teaser',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'f8d72c97-a8b5-4154-81eb-8b0af97c70f6';
  $display->content['new-f8d72c97-a8b5-4154-81eb-8b0af97c70f6'] = $pane;
  $display->panels['contentmain'][1] = 'new-f8d72c97-a8b5-4154-81eb-8b0af97c70f6';
  $pane = new stdClass();
  $pane->pid = 'new-fe39e77a-af54-4bcd-8d73-60928dc15d7f';
  $pane->panel = 'header';
  $pane->type = 'entity_field';
  $pane->subtype = 'taxonomy_term:field_featured_image';
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
  $pane->uuid = 'fe39e77a-af54-4bcd-8d73-60928dc15d7f';
  $display->content['new-fe39e77a-af54-4bcd-8d73-60928dc15d7f'] = $pane;
  $display->panels['header'][0] = 'new-fe39e77a-af54-4bcd-8d73-60928dc15d7f';
  $pane = new stdClass();
  $pane->pid = 'new-6ba1ecf5-37cb-4b0b-b639-2442e49ff835';
  $pane->panel = 'sidebar';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-r9xCH9C6MPZqbHC4JMLdKIT2Nl5SJohx';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Type',
    'override_title_heading' => 'h5',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '6ba1ecf5-37cb-4b0b-b639-2442e49ff835';
  $display->content['new-6ba1ecf5-37cb-4b0b-b639-2442e49ff835'] = $pane;
  $display->panels['sidebar'][0] = 'new-6ba1ecf5-37cb-4b0b-b639-2442e49ff835';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['taxonomy_term:catalog:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'taxonomy_term:catalog:default:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'taxonomy_term';
  $panelizer->panelizer_key = 'catalog';
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
  $display->title = '';
  $display->uuid = '6de6a10b-e08f-44ed-92d1-401b327e5002';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['taxonomy_term:catalog:default:default'] = $panelizer;

  return $export;
}
