<?php
/**
 * @file
 * Theme and preprocess functions for breadcrumbs, messages, tabs..etc
 */

/**
 * Implements theme_status_messages().
 *
 * Override to fix Add to Cart confirmation in Radix.
 */
function radix_commerce_status_messages($variables) {
  $display = $variables['display'];
  $output = '';

  $status_heading = array(
    'status' => t('Status message'),
    'error' => t('Error message'),
    'warning' => t('Warning message'),
  );

  foreach (drupal_get_messages($display) as $type => $messages) {
    // Add Bootstrap classes.
    $type = ($type == 'status') ? 'success' : $type;
    $type = ($type == 'error') ? 'danger' : $type;

    $output .= "<div class=\"alert alert-$type messages $type alert-dismissable\">\n";

    // Add a close button.
    $output .= '<button type="button" class="close" data-dismiss="alert" aria-hidden="true">&times;</button>';

    if (!empty($status_heading[$type])) {
      $output .= '<h2 class="element-invisible">' . $status_heading[$type] . "</h2>\n";
    }
    if (count($messages) > 1) {
      $output .= " <ul>\n";
      foreach ($messages as $message) {
        $output .= '  <li>' . $message . "</li>\n";
      }
      $output .= " </ul>\n";
    }
    else {
      $output .= $messages[0];
    }
    $output .= "</div>\n";
  }
  return $output;
}

/**
 * Theme function to render the confirmation message.
 */
function radix_commerce_commerce_add_to_cart_confirmation_message($variables) {
  // Build the message output.
  // @todo Switch this to use a template.
  $message = '<div class="added-product-title clearfix">' . t('Item successfully added to your cart') . '</div>';
  $message .= '<div class="button-wrapper">';
  $message .= '<div class="btn button checkout">' . l(t('Go to checkout'), 'cart') . '</div>';
  $message .= '<div class="btn button continue"><span class="commerce-add-to-cart-confirmation-close">' . t('Continue shopping') . '</span></div>';
  $message .= '</div>';
  $message .= $variables['view'];

  return '<div class="message-inner">' . $message . '<a class="commerce-add-to-cart-confirmation-close" href="#"><span class="element-invisible">' . t('Close') . '</span></a></div>';
}
