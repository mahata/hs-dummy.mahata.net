<?php

class YahooRssData extends BaseData
{
  public function getJson() {
    // data is fetched from Yahoo! Blog Search (search word is "hootsuite")

    // there should be retry
    $xml_str = file_get_contents("http://blog.search.yahoo.co.jp/rss?p=hootsuite");

    $json_array = array();
    $xml_obj = simplexml_load_string($xml_str);
    foreach ($xml_obj->channel->item as $item) {
      $json_array[] = array("desc" => (string)$item->description, "time" => (string)$item->pubDate);
    }

    return json_encode($json_array, JSON_HEX_TAG | JSON_HEX_APOS | JSON_HEX_QUOT | JSON_HEX_AMP);
  }
}
