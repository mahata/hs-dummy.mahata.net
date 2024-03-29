<?php

require_once(dirname(__FILE__) . "/BaseData.class.inc");
require_once(dirname(__FILE__) . "/../wordpress/WordPress.class.inc");

class WordPressData extends BaseData
{
  private $wp;

  public function __construct() {
    $this->wp = new WordPress();
  }

  public function getJson() {
    // data is fetched from WordPress (yasunari1234.wordpress.com: dummy account)
    $json_array = $this->wp->read();

    return json_encode($json_array, JSON_HEX_TAG | JSON_HEX_APOS | JSON_HEX_QUOT | JSON_HEX_AMP);
  }

  // I can write codes to post data to WordPress by overriding postData()
  public function postData() {}
}
