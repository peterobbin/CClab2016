/* Create a "psychic duck" that gives out a random reply from a list of 
preset replies in an array, while changing expressions. Steps are numbered. 
*/

// -- 1
// Create variables. 
var replies = ["Yes", "No", "How should I know?", "Feed me and then I'll tell you.", "Maaaaybe."]; // list of replies, order must correspond with the right sound file
var sounds = ["yes", "no", "how", "feedme", "maybe"]; // name of sound files
var eyes = ["eyes", "eyes2", "eyes3", "eyes4", "eyes5", "eyes", "eyes7" ]; // name of image files for eyes
var randomNum = 0; // this variable will hold the current randomized number to pull from the replies array
var randomEyes = 0; // variable that holds random number to pull a new eye expression, separate variable because the amount of eyes exceed the amount of replies
var audioElement;

// -- step 11
// create function to play sound based off of random variable being passed
function playSounds(r) {
audioElement.setAttribute('src', "assets/sound/"+sounds[r]+".mp3"); // assign sound file based on random number picking from array
audioElement.play(); // .play() is a native DOM function, not jQuery
}

// -- step 6
// create a function that returns a random number within the limits of the array length. 
// function passes name of the array, so we can use one function for different arrays with different lengths
function randomNumGenerator(arrayName) { // create random number for random reply
    return Math.floor(Math.random() * arrayName.length); 
	// Math.floor returns a number representing the largest integer less than or equal to the specified number.
	// Math.random() returns a value between (0, 1).   
}


// -- step 5
// create answerQuestion function
function answerQuestion() {

	// -- step 7
	// assign a random number to 
	randomNum = randomNumGenerator(replies);
	console.log("Random reply: " + randomNum);

	// -- step 9
	// pick a reply using random number
	// vanilla js: document.getElementById("speech").textContent = replies[randomNum];
	$('#speech').text(replies[randomNum]);

	// -- step 10
	// call playSounds function
	playSounds(randomNum);

	// -- step 12
	// change eyes 
	randomEyes = randomNumGenerator(eyes); // generate random number for eyes based off of number of eyes in array
	// vanilla js format: document.getElementById(eyes).style.backgroundImage = "url('assets/img/"+ eyes[randomEyes] + ".png'";
	$('#eyes').css("background", "url('assets/img/"+ eyes[randomEyes] + ".png') no-repeat"); 
	// vanilla js format: document.getElementById(eyes).style.backgroundSize = "100% auto";
	$('#eyes').css("background-size", "100% auto");
}

// -- step 3
// init function will initialize the rest of the functions
function init() {
	console.log('Hello World'); // check to see if script is linked properly and running

	// -- step 4 
	// create audio element after everything is loaded
	// with vanilla js because in this case with jQuery it would involve more code
	audioElement = document.createElement('audio'); // create audio element
	audioElement.setAttribute('autoplay', 'autoplay'); // set audio element to autoplay
	
	// -- step 8
	// call answer function on click
	// vanilla js: 
	// var submit = document.getElementById(submit);
	// submit.addEventListener("click", function() {
	//	answerQuestion();
	// });
	$("#submit").click(function(){
		answerQuestion();
	});
}

// -- step 2
// wait until dom is loaded then run init function
$(document).ready(function(){
	init();
}); 