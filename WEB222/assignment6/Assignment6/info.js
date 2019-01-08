
window.addEventListener('load', function() {
	//find form object
	var submitRef = document.querySelector('#submitbtn');
	var resetRef  = document.querySelector('#resetbtn');

	//show error messages
	function showErrors(messages) {
		document.querySelector('#errors').innerHTML = messages;
	}
									
	//clear all error messages
	function clearError(){
		document.querySelector('#errors').innerHTML = "";
	}
	
	//Add Event listener for submit
	submitRef.addEventListener(
		'click', 
		function(e) {
				
			var formRef = document.querySelector('#infoForm');   
			var allValid = true;			
			var inputFirstName= formRef.FirstName.value.trim();
			var inputLastName = formRef.LastName.value.trim();			
			var inputAge = formRef.age.value.trim();
			var inputUser = formRef.username.value.trim();
			var inputPWD  = formRef.password.value;
			var inputPWD2 = formRef.confirmPassword.value;
			var messages = "";
					
			//validate First Name
			if(!(/[A-Z][a-zA-Z]*/.test(inputFirstName))){
				messages += "<p> * First Name: Must start with a cap and only alphabet allowed.</p>";
				allValid = false;
			}
			
			//validate Last Name
			if(!(/[A-Z][a-zA-Z]*/.test(inputLastName))){
				messages += "<p> * Last Name: Must start with a cap and only alphabet allowed.</p>";
				allValid = false;
			}
			
			//validate age
			if(inputAge < 18||inputAge > 60){
				messages += "<p> * Age: must be in between 18-60.</p>";
				allValid = false;
			}
					
			//validate username
			if(!(/[A-Za-z].{6,}/.test(inputUser))){
				messages += "<p> * User Name: must start with a letter, must have at least 6 characters.</p>";
				allValid = false;
			}

			//validate same password
			if(inputPWD != inputPWD2){
				messages += "<p> *  The password strings must match </p>";
				allValid = false;
			}
				
			//validate password
			if(!(/^(?=.*[A-Z])(?=.*\d).{6}$/.test(inputPWD))){
				messages += "<p> * password: must be 6 characters long, must start with a character, must have at least 1 digit and 1 uppercase.</p>";
				allValid = false;
			}			
					
			if(!allValid){
				showErrors(messages);
				e.preventDefault();
				return false;
			}else{
				alert("Success!");
				return true;
			}
		}
	)

	//Add Event listener for reset
	resetRef.addEventListener(
		'click', 
		function(e) {
			clearError();
		}	
	)

});

