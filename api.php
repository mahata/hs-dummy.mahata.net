<?php

require_once(dirname(__FILE__) . "/lib/part4/TwitterData.class.inc");
require_once(dirname(__FILE__) . "/lib/part4/YahooRssData.class.inc");

function expr($a) { return $a; }

$json = "";
switch ($_GET["service"]) {
case "twitter":
  $json = expr(new TwitterData())->getJson();
  break;
case "yahoo":
  $json = expr(new YahooRssData())->getJson();
  break;
default:
  $json = "{\"result\": \"error\"}";
}

header("X-Content-Type-Options: nosniff");
header("Content-type: application/json");
echo $json;
