var city = '';
var state = '';
var APIKey = 'f5004746ddb3c3d4';



var loadWeather = function(jsonResponse){
	console.log(jsonResponse);
	if (jsonResponse.response.error){
		alert(jsonResponse.response.error.description);
		return;
	}

	//set variables to elements of your response object
	var thisCity = jsonResponse.location.city;
	//use the chrome console to debug, also try look for the actual json file
	var temp = Math.round(jsonResponse.current_observation.temp_f) + '°';
	var weather = jsonResponse.current_observation.weather;
	var icon = jsonResponse.current_observation.icon_url;

	console.log("this is the city:" + thisCity);


	$('.temperature').html(temp);
	$('.weather').html(weather);
	$('.weatherIcon').html('<img src="' + icon + '">');

	$('.currentCity').val(thisCity);
}

var setLocation = function(){
	city = $('.currentCity').val();
	state = $('.currentState').val();
	console.log("city is: " + city + "state is: " + state);
	if (city == null || city == ''){
		alert('hey why you are not entering anything');
		return;
	}
	getWeather();
}

var getWeather = function(){
	var myUrl = "http://api.wunderground.com/api/" + APIKey + "/geolookup/conditions/q/" + state + "/" + city +".json";
	console.log(myUrl);

	$.ajax({
		url:myUrl,
		dataType: "jsonp",
		success: function(response){
			console.log("i got the json file parsed!");
			loadWeather(response);
		}
	});
}


//init
var init = function(){
	console.log("Hello World!");

	// this is important because you dont' want the page to refresh and lose your input
	$("#submit").click(function(event) {
		event.preventDefault();
		setLocation();
	});

}

// dom load listener
$(document).ready(function() {
	init();
});

