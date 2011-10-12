<?php

require_once(dirname(__FILE__) . "/twitteroauth.php");

class Twitter
{
  private $conf;
  private $to;

  public function __construct() {
    // configuration should be fetched from cache data if it is possible
    $this->conf = parse_ini_file(dirname(__FILE__) . "/../../conf/twitter.ini", true);
    $this->to = new TwitterOAuth($this->conf["auth"]["consumer_key"],
                                 $this->conf["auth"]["consumer_secret"],
                                 $this->conf["auth"]["access_token"],
                                 $this->conf["auth"]["access_token_secret"]);
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
