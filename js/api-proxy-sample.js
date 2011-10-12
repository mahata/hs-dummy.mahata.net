$(function(){
      function fill_list(data) {
          $("#list").html("");
          for (var i = 0; i < data.length; i++) {
              $("#list").append('<div class="well"><strong>' + data[i].desc + "</strong> - " + data[i].time + "</div>");
          }
      }

      function request_wrapper(service) {
          $("#list").html('<div class="container"><img src="/img/loading.gif" alt="loading" /></div>');
          $.get("/api-read.php?service=" + service, function(data) {
              fill_list(data);
          });
      }

      $("#twitter").bind("click", function() { request_wrapper("Twitter"); });
      $("#yahoo").bind("click", function() { request_wrapper("YahooRss"); });
      $("#wordpress").bind("click", function() { request_wrapper("WordPress"); });
})

