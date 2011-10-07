$(function(){
      function fill_list(data) {
          $("#list").html("");
          for (var i = 0; i < data.length; i++) {
              $("#list").append("<div class=\"label success\">" + data[i].desc + ", " + data[i].time + "</div>");
          }
      }

      $("#twitter").bind("click", function() {
                             $.get("/api.php?service=twitter", function(data) {
                                       fill_list(data);
                                   });
                         });
      $("#yahoo").bind("click", function() {
                             $.get("/api.php?service=yahoo", function(data) {
                                       fill_list(data);
                                   });
                         });
})

