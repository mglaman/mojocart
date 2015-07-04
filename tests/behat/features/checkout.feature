Feature: Access checkout
  As a customer
  I can add a product to my cart
  Which allows me to purchase the product


  @api
  Scenario: Add product to cart
    Given I am an anonymous user
    When I am viewing a "product_display" and product of "product" with the title "Behat Product"
    Then I should see "Behat Product"
      And I press "Add to cart" in the "Content" region
      Then I should see "ITEM SUCCESSFULLY ADDED TO YOUR CART"
    When I click "Go to checkout"
      Then I should see the heading "Shopping cart" in the "Content" region
      And I should see the link "Behat Product"
    When I press "Checkout"
      Then I should see "Shopping cart contents"
      And I should see "Coupons"
      And I fill in the following:
        | account[login][mail]                                                              | demo@demo.com |
        # Shipping
        | customer_profile_shipping[commerce_customer_address][und][0][name_line]           | Behat User    |
        | customer_profile_shipping[commerce_customer_address][und][0][thoroughfare]        | 1234 56th St  |
        | customer_profile_shipping[commerce_customer_address][und][0][locality]            | Kenosha       |
        | customer_profile_shipping[commerce_customer_address][und][0][administrative_area] | WI            |
        | customer_profile_shipping[commerce_customer_address][und][0][postal_code]         | 53140         |
        # Billing
        | customer_profile_billing[commerce_customer_address][und][0][name_line]            | Behat User    |
        | customer_profile_billing[commerce_customer_address][und][0][thoroughfare]         | 1234 56th St  |
        | customer_profile_billing[commerce_customer_address][und][0][locality]             | Kenosha       |
        | customer_profile_billing[commerce_customer_address][und][0][administrative_area]  | WI            |
        | customer_profile_billing[commerce_customer_address][und][0][postal_code]          | 53140         |
    When I press "Continue to next step"
      Then I should see "Shipping service"
    When I press "Continue to next step"
      Then I should see "Review your order before continuing."
    # @todo: Open ticket to change last page button to "finish"
    When I press "Continue to next step"
      Then I should see "Checkout complete"
