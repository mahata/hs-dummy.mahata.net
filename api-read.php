<?php

function expr($a) { return $a; }

$json = "";
switch ($_GET["service"]) {
case "twitter":
  require_once(dirname(__FILE__) . "/lib/part4/TwitterData.class.inc");
  $json = expr(new TwitterData())->getJson();
  break;
case "wordpress":
  require_once(dirname(__FILE__) . "/lib/part4/WordPressData.class.inc");
  $json = expr(new WordPressData())->getJson();
  break;
case "yahoo":
  require_once(dirname(__FILE__) . "/lib/part4/YahooRssData.class.inc");
  $json = expr(new YahooRssData())->getJson();
  break;
default:
  $json = "{\"result\": \"error\"}";
}

header("X-Content-Type-Options: nosniff");
header("Content-type: application/json");
echo $json;
