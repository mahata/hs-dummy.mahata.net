$(function(){
      function fill_list(data) {
          $("#list").html("");
          for (var i = 0; i < data.length; i++) {
              $("#list").append("<li>" +data[i].desc + ", " + data[i].time + "</li>");
          }
      }

      $("#twitter").bind("click", function() {
                             $.get("/api.php?service=twitter", function(data) {
                                       fill_list(data);
                                   });
                         });
      $("#yahoo").bind("click", function() {
                             console.log( $(this).text() );
                             $.get("/api.php?service=yahoo", function(data) {
                                       fill_list(data);
                                   });
                         });
})

