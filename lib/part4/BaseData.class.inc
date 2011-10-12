<?php

require_once(dirname(__FILE__) . "/Proxy.interface.inc");

abstract Class BaseData implements Proxy
{
  public function getJson() {
    return '{"error": "cannot get JSON.  This may not a readable service."}';
  }
  public function postData() {
    return '{"error": "cannot post data.  This may not a writable service."}';
  }
}
