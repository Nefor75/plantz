var myVar = setInterval(function() {
  myTimer();
}, 1000);

function myTimer() {
  var d = new Date();
  document.getElementById("time-current").innerHTML = d.toLocaleTimeString()+" (Текущее время)";
}