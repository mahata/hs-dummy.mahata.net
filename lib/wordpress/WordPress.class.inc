<?php

require_once("XML/RPC.php");

class WordPress
{
  private $conf;
  private $client;
  private $app_key;
  private $user;
  private $pass;
  private $blog_id;

  public function __construct() {
    // configuration should be fetched from cache data if it is possible
    $this->conf = parse_ini_file(dirname(__FILE__) . "/../../conf/wordpress.ini", true);

    $this->client = new XML_RPC_client($this->conf["auth"]["xmlrpc_path"], $this->conf["auth"]["host"], 80);
    $this->app_key = new XML_RPC_Value($this->conf["auth"]["app_key"], "string");
    $this->user = new XML_RPC_Value($this->conf["auth"]["user"], "string");
    $this->pass = new XML_RPC_Value($this->conf["auth"]["pass"], "string");
    $result = $this->client->send(new XML_RPC_Message("blogger.getUsersBlogs",
                                                      array($this->app_key, $this->user, $this->pass)));

    $blogs = XML_RPC_decode($result->value());
    $this->blog_id = new XML_RPC_Value($blogs[0]["blogid"], "string");
  }

  public function post($text) {
    $content = new XML_RPC_Value(
      array(
        "title" => new XML_RPC_Value("hs-dummy", "string"),
        "categories" => new XML_RPC_Value(array(), "array"),
        "description" => new XML_RPC_Value($text, "string"),
        "dateCreated" => new XML_RPC_Value(time(), "dateTime.iso8601")
        ),
      "struct");
    $publish = new XML_RPC_Value(1, "boolean");
    $message = new XML_RPC_Message(
      "metaWeblog.newPost",
      array($this->blog_id, $this->user, $this->pass, $content, $publish));

    $this->client->send($message);
  }
  
  public function read() {
    $message = new XML_RPC_Message(
      "metaWeblog.getRecentPosts",
      array($this->blog_id, $this->user, $this->pass,
            new XML_RPC_Value(20, "int")));
    $result = $this->client->send($message);
    $posts = XML_RPC_decode($result->value());

    $ret_array = array();
    foreach ($posts as $post) {
      $ret_array[] = array("desc" => (string)$post["description"], "time" => (string)$post["dateCreated"]);
    }

    return $ret_array;
  }
}

