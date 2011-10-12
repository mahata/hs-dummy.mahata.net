<?php

require_once(dirname(__FILE__) . "/BaseData.class.inc");
require_once(dirname(__FILE__) . "/../twitter/Twitter.class.inc");

class TwitterData extends BaseData
{
  private $twitter;

  public function __construct() {
    $this->twitter = new Twitter();
  }

  public function getJson() {
    // data is fetched from Twitter (@_yasunari: dummy account)

    $json_array = array();
    $xml_obj = simplexml_load_string($this->twitter->read());
    foreach ($xml_obj as $status) {
      $json_array[] = array("desc" => (string)$status->text, "time" => (string)$status->created_at);
    }

    return json_encode($json_array, JSON_HEX_TAG | JSON_HEX_APOS | JSON_HEX_QUOT | JSON_HEX_AMP);
  }

  // I can write codes to post data to Twitter by overriding postData()
  public function postData() {}
}

