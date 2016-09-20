//global variables
var city = '';
var state = '';
var APIKey = '';

var loadWeather = function(jsonResponse){

	console.log(jsonResponse);

	//add an error catch before setting variables
	if(jsonResponse.response.error){
		alert(jsonResponse.response.error.description);
		return;
	};

	//set variables to elements of your response object
	var thisCity = jsonResponse.location.city;
	//use the chrome console to debug, also try look for the actual json file
	var temp = Math.round(jsonResponse.current_observation.temp_f) + '°';
	var weather = jsonResponse.current_observation.weather;
	var icon = jsonResponse.current_observation.icon_url;

	console.log('this is your city' + thisCity);
	//set text of HTML elements to your variables
	$('.temperature').html(temp);
	$('.weather').html(weather);
	$('.weatherIcon').html('<img src="' + icon + '">');

	//set value of city input to response city.
	$('.currentCity').val(thisCity);

};

var setLocation = function(){
	//set the global variable 'city' to the value of .currentCity
	city = $('.currentCity').val()

	//set the global variable 'state' to the value of .currentState
	state = $('.currentState').val()

	//if the city is null or it equals '', alert the user and
	//stop running the function.
	if(city == null || city == ''){
		alert('You need to list a city!');
		return;
	};

	console.log('You want the weather for ' + city + ', ' + state);

	//call getWeather() function now that city and state are set
	getWeather();
};

var getWeather = function(){
// look for geolookup, so you get the location easily
  var myUrl = "http://api.wunderground.com/api/" + APIKey +
  "/geolookup/conditions/q/" + state + "/" + city + ".json"

	//run the ajax call and load weather on success
	$.ajax({
		url : myUrl,
		dataType : "jsonp",
		success : function(response) {
			loadWeather(response);
		}
	});
};

//init
var init = function(){

	console.log('What\'s the weather?');

	// this is important because you don't want the page to refresh and lose your input
	$('#submit').click(function(e){
		e.preventDefault();
		setLocation();
	});
};


//document load listener
$( document ).ready(function() {
    init(); //call init() function when the page loads
});
