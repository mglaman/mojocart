<?php
/**
 * @file
 * The main Behat context.
 */

use Drupal\DrupalExtension\Context\RawDrupalContext;
use Behat\Behat\Context\SnippetAcceptingContext;

/**
 * Define application features from the specific context.
 */
class FeatureContext extends RawDrupalContext implements SnippetAcceptingContext {
  /**
   * @AfterStep
   *
   * Take a screen shot after failed steps for Selenium drivers (e.g.
   * PhantomJs).
   */
  public function takeScreenshotAfterFailedStep(\Behat\Behat\Hook\Scope\AfterStepScope $event) {
    if ($event->getTestResult()->isPassed()) {
      // Not a failed step.
      return;
    }
    if ($this->getSession()->getDriver() instanceof \Behat\Mink\Driver\Selenium2Driver) {
      $file_name = 'behat-failed-step.png';
      $screenshot = $this->getSession()->getDriver()->getScreenshot();
      file_put_contents($file_name, $screenshot);
      print "Screenshot for failed step created in $file_name";
    }
  }

  /**
   * Take screenshot when step fails.
   *
   * @param \Behat\Behat\Hook\Scope\AfterStepScope $event
   *
   * @AfterStep
   */
  public function saveHTMLAfterFailedStep(\Behat\Behat\Hook\Scope\AfterStepScope $event)
  {
    if (!$event->getTestResult()->isPassed()) {
      /** @var GuzzleHttp\Stream\Stream $output */
      $output = $this->getSession()->getDriver()->getContent();
      file_put_contents('behat-step-failed.html', $output);
    }
  }
}
