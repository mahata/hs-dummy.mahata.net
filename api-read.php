<?php

require_once(dirname(__FILE__) . "/lib/part4/TwitterData.class.inc");
require_once(dirname(__FILE__) . "/lib/part4/WordPressData.class.inc");
require_once(dirname(__FILE__) . "/lib/part4/YahooRssData.class.inc");

function expr($a) { return $a; }
$data = $_GET["service"] . "Data";
$json = expr(new $data)->getJson();

header("X-Content-Type-Options: nosniff");
header("Content-type: application/json");
echo $json;
