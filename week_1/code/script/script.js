
document.addEventListener("DOMContentLoaded", function(){

	var degree = 0;
	var parentDiv = document.getElementsByClassName("parent")
	var div1 = document.getElementById('div1');
	var div2 = document.getElementById('div2');
	var div3 = document.getElementById('div3');

	div1.style.backgroundColor = "red";
	console.log('class length: ' + parentDiv.length);

	var rotateDiv = function () {
		parentDiv[0].style.transform = "rotate("+ degree + "deg)";
		degree += 0.1;
	}
	
	window.setInterval(rotateDiv, 10);

});

