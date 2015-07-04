Feature: Store Managers can access management areas
  As a store manager
  I can access the administrative toolbar
  So that I can manage the store

  @api @javascript
  Scenario: I can access the administrative toolbar
    Given I am logged in as a user with the "store manager" role
    When I am on the homepage
      Then I should see the link "Store" in the "Navbar" region
        And I click "Store" in the "Navbar" region
    Then I should see the link "Reports" in the "Navbar" region
    Then I should see the link "Coupons" in the "Navbar" region
    Then I should see the link "Discounts" in the "Navbar" region
    Then I should see the link "Orders" in the "Navbar" region
    Then I should see the link "Products" in the "Navbar" region
    Then I should see the link "Configuration" in the "Navbar" region
