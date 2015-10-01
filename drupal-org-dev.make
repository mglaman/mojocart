api = 2
core = 7.x

; The Panopoly Foundation
projects[panopoly_core][download][type] = git
projects[panopoly_core][download][branch] = 7.x-1.x
projects[panopoly_core][subdir] = panopoly


projects[panopoly_images][download][type] = git
projects[panopoly_images][download][branch] = 7.x-1.x
projects[panopoly_images][subdir] = panopoly


projects[panopoly_theme][download][type] = git
projects[panopoly_theme][download][branch] = 7.x-1.x
projects[panopoly_theme][subdir] = panopoly
projects[panopoly_theme][patch][1987386] = https://www.drupal.org/files/issues/panopoly_theme-radix-1987386-22.patch


projects[panopoly_magic][download][type] = git
projects[panopoly_magic][download][branch] = 7.x-1.x
projects[panopoly_magic][subdir] = panopoly


projects[panopoly_widgets][download][type] = git
projects[panopoly_widgets][download][branch] = 7.x-1.x
projects[panopoly_widgets][subdir] = panopoly


projects[panopoly_admin][download][type] = git
projects[panopoly_admin][download][branch] = 7.x-1.x
projects[panopoly_admin][subdir] = panopoly


projects[panopoly_users][download][type] = git
projects[panopoly_users][download][branch] = 7.x-1.x
projects[panopoly_users][subdir] = panopoly


; The Panopoly Toolset


projects[panopoly_pages][download][type] = git
projects[panopoly_pages][download][branch] = 7.x-1.x
projects[panopoly_pages][subdir] = panopoly


projects[panopoly_wysiwyg][download][type] = git
projects[panopoly_wysiwyg][download][branch] = 7.x-1.x
projects[panopoly_wysiwyg][subdir] = panopoly


projects[panopoly_search][download][type] = git
projects[panopoly_search][download][branch] = 7.x-1.x
projects[panopoly_search][subdir] = panopoly


; For running the automated tests.

projects[panopoly_test][download][type] = git
projects[panopoly_test][download][branch] = 7.x-1.x
projects[panopoly_test][subdir] = panopoly

; Commerce Deploy

projects[commerce_deploy_core][download][type] = git
projects[commerce_deploy_core][download][branch] = 7.x-1.x
projects[commerce_deploy_core][subdir] = commerce_deploy

projects[commerce_deploy_shipping][download][type] = git
projects[commerce_deploy_shipping][download][branch] = 7.x-1.x
projects[commerce_deploy_shipping][subdir] = commerce_deploy

projects[commerce_deploy_promotions][download][type] = git
projects[commerce_deploy_promotions][download][branch] = 7.x-1.x
projects[commerce_deploy_promotions][subdir] = commerce_deploy

projects[commerce_deploy_product][download][type] = git
projects[commerce_deploy_product][download][branch] = 7.x-1.x
projects[commerce_deploy_product][subdir] = commerce_deploy

projects[commerce_deploy_customer][download][type] = git
projects[commerce_deploy_customer][download][branch] = 7.x-1.x
projects[commerce_deploy_customer][subdir] = commerce_deploy

projects[commerce_deploy_checkout][download][type] = git
projects[commerce_deploy_checkout][download][branch] = 7.x-1.x
projects[commerce_deploy_checkout][subdir] = commerce_deploy

projects[commerce_deploy_backend][download][type] = git
projects[commerce_deploy_backend][download][branch] = 7.x-1.x
projects[commerce_deploy_backend][subdir] = commerce_deploy

; Commerce Contrib
projects[commerce_search_api][download][type] = git
projects[commerce_search_api][download][branch] = 7.x-1.x
projects[commerce_search_api][subdir] = contrib

projects[commerce_migrate][download][type] = git
projects[commerce_migrate][download][branch] = 7.x-1.x
projects[commerce_migrate][patch][1931302] = https://www.drupal.org/files/commerce_products_source_migration-1931302-2.patch
projects[commerce_migrate][subdir] = contrib

; MojoCart
projects[radix_views][download][type] = git
projects[radix_views][download][branch] = 7.x-1.x
projects[radix_views][subdir] = contrib
