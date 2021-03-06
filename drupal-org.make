api = 2
core = 7.x

; The Panopoly Foundation
projects[panopoly_core][version] = 1.27
projects[panopoly_core][subdir] = panopoly

projects[panopoly_images][version] = 1.27
projects[panopoly_images][subdir] = panopoly

projects[panopoly_theme][version] = 1.27
projects[panopoly_theme][subdir] = panopoly
projects[panopoly_theme][patch][1987386] = https://www.drupal.org/files/issues/panopoly_theme-radix-1987386-22.patch

projects[panopoly_magic][version] = 1.27
projects[panopoly_magic][subdir] = panopoly


projects[panopoly_widgets][version] = 1.27
projects[panopoly_widgets][subdir] = panopoly

projects[panopoly_admin][version] = 1.27
projects[panopoly_admin][subdir] = panopoly

projects[panopoly_users][version] = 1.27
projects[panopoly_users][subdir] = panopoly

; The Panopoly Toolset

projects[panopoly_pages][version] = 1.27
projects[panopoly_pages][subdir] = panopoly

projects[panopoly_wysiwyg][version] = 1.27
projects[panopoly_wysiwyg][subdir] = panopoly

projects[panopoly_search][version] = 1.27
projects[panopoly_search][subdir] = panopoly

; For running the automated tests.

projects[panopoly_test][version] = 1.27
projects[panopoly_test][subdir] = panopoly

; Commerce Deploy

projects[commerce_deploy_core][version] = 1.0-alpha4
projects[commerce_deploy_core][subdir] = commerce_deploy

projects[commerce_deploy_shipping][version] = 1.0-alpha4
projects[commerce_deploy_shipping][subdir] = commerce_deploy

projects[commerce_deploy_promotions][version] = 1.0-alpha4
projects[commerce_deploy_promotions][subdir] = commerce_deploy

projects[commerce_deploy_product][version] = 1.0-alpha4
projects[commerce_deploy_product][subdir] = commerce_deploy

projects[commerce_deploy_customer][version] = 1.0-alpha4
projects[commerce_deploy_customer][subdir] = commerce_deploy

projects[commerce_deploy_checkout][version] = 1.0-alpha4
projects[commerce_deploy_checkout][subdir] = commerce_deploy
projects[commerce_deploy_checkout][download][type] = git
projects[commerce_deploy_checkout][download][revision] = 43236d0
projects[commerce_deploy_checkout][download][branch] = 7.x-1.x


projects[commerce_deploy_backend][version] = 1.0-alpha4
projects[commerce_deploy_backend][subdir] = commerce_deploy

; Commerce Contrib
projects[commerce_search_api][version] = 1.4
projects[commerce_search_api][subdir] = contrib

projects[commerce_migrate][version] = 1.1
projects[commerce_migrate][subdir] = contrib
projects[commerce_migrate][patch][1931302] = https://www.drupal.org/files/commerce_products_source_migration-1931302-2.patch

projects[commerce_page_manager][version] = 1.x
projects[commerce_page_manager][subdir] = contrib
projects[commerce_page_manager][download][type] = git
projects[commerce_page_manager][download][revision] = dd604e1
projects[commerce_page_manager][download][branch] = 7.x-1.x

projects[commerce_responsive_ui][version] = 1.x
projects[commerce_responsive_ui][subdir] = contrib
projects[commerce_responsive_ui][download][type] = git
projects[commerce_responsive_ui][download][revision] = 942cb3d
projects[commerce_responsive_ui][download][branch] = 7.x-1.x
; Contrib
projects[coffee][subdir] = contrib
projects[coffee][download][type] = git
projects[coffee][download][revision] = 40d33e6
projects[coffee][download][branch] = 7.x-2.x
projects[coffee][patch][2453585] = https://www.drupal.org/files/issues/local_storage_for_coffee-2453585-7.patch

; MojoCart
projects[radix_views][version] = 1.0
projects[radix_views][subdir] = contrib
