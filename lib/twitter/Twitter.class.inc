<?php

require_once("twitteroauth.php");

class Twitter
{
  private $conf;
  private $to;

  public function __construct() {
    // configuration should be fetched from cache data if it is possible
    $conf = parse_ini_file(dirname(__FILE__) . "/twitter.ini", true);
    $this->to = new TwitterOAuth($conf["auth"]["consumer_key"],
                           $conf["auth"]["consumer_secret"],
                           $conf["auth"]["access_token"],
                           $conf["auth"]["access_token_secret"]);
  }

  public function post($text) {
    $req = $this->to->OAuthRequest("https://twitter.com/statuses/update.xml",
                                   "POST",
                                   array("status" => "message: " . $text));
  }

  public function read() {
    // fetching xml instead of json on purpose (to cut off some data)
    // return($this->to->OAuthRequest("https://twitter.com/statuses/home_timeline.json",
    return($this->to->OAuthRequest("https://twitter.com/statuses/home_timeline.xml",
                                   "GET",
                                   array()));
  }
}
