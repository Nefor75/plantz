function blinckTermomInImg(){
if(document.getElementById('termom_in_img').style.visibility == "hidden")
    document.getElementById('termom_in_img').style.visibility = "visible"
else
    document.getElementById('termom_in_img').style.visibility = "hidden"
}
setInterval('blinckTermomInImg()',1000);
