
/*********************************************************************
* WEB222 SSA – Assignment 01
* I declare that this assignment is my own work in accordance with
* Seneca Academic Policy. No part of this assignment has been
* copied manually or electronically from any other source
* (including web sites) or distributed to other students.
*
* Name: zhi zhao Student   ID: 109079178    Date:  9/23/2018
*
*********************************************************************/


/*
  Task 1 - Format and Display Student Info
*/

function displayStudentInfo(name, program, courses, hasJob) {
  var result_str;
  if(hasJob) {
        result_str="My name is " + name + " and I’m in the "+ program +" program. I’m taking " + courses + " courses this semester, and I do have a part-time job.";
    }else{
        result_str= "My name is " + name + " and I’m in the "+ program +" program. I’m taking " + courses + " courses this semester, and I don't have a part-time job.";        
    }    
  console.log(result_str);
  return;
}

displayStudentInfo("Jane Doe", "CPA", 5);
displayStudentInfo("John Kim", "BSD", 1, false);
displayStudentInfo("Vivian Lee", "CPA", 3, true);


/*
  Task 2 - Calculate Age Statistics
*/
function calculateAgeStats(birthDate) {
    
  var weekdays=["Sun","Mon","Tue","Wed","Thu","Fri","Sat"];
    
  var dob = new Date(birthDate);  
  var weekday_name = weekdays[dob.getDay()];
  
  var current_time = Date.now();
  var elapse = Math.floor((current_time - dob)/1000/3600);
  console.log("You were born on " + weekday_name + " " + birthDate + " and have been alive for approximately " + elapse + " hours.")
}

calculateAgeStats("Dec 23, 2000");

/*
Task 3 -Convert Temperatures From/To Celsius & Fahrenheit
*/

function convertTempFrom(value, scale='c') {
  var New_Value;
  var Return_Str;
  
  switch (scale){
    case 'c':
    case 'C':
      New_Value = Math.round(value*1.8 + 32);
      Return_Str = New_Value + " F";
      break;
    
    case 'f':
    case 'F':
      New_Value = Math.round((value-32)/1.8);
      Return_Str = New_Value + " C";
      break;
    
    default:
      Return_Str="ERROR: Unknown Scale - " + scale;
      break;
  }
  
  return Return_Str; 
}

console.log(convertTempFrom(50));
console.log(convertTempFrom(50, "c")); 
console.log(convertTempFrom(50, "C")); 
console.log(convertTempFrom(10, "F")); 
console.log(convertTempFrom(56, "G")); 
console.log(convertTempFrom(56, "k")); 



/*
Task 4 - Display Odd/Even for all numbers in a range
*/

function displayOddEven(rangeStart, rangeEnd) {
    for(var i=rangeStart; i<=rangeEnd; i++){
      if(i%2==0)
        console.log(i + " is even\n");
      else
        console.log(i + " is odd\n");
    }    
}

displayOddEven(0,10)


/*
Task 5 - Find Largest Number
*/
var findLargest = function () {
    var max_value=arguments[0];
	//loop start from index=1, because arguments[0] is used to initialize max_value
    for(var i=1; i<arguments.length; i++){
        if(arguments[i]>max_value){
            max_value=arguments[i];
        }            
    }
    
    return max_value;
};

console.log(findLargest(1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
console.log(findLargest(-1, -2, -3, -4, -5, -6, -7, -8, -9, -10)); 
console.log(findLargest(200, 313, 5000, 2, -10, 9993513, 3, 2)); 


/*
Task 6 - Average Evaluator
*/

function calculateAverage() {
  
  var total = 0;
  
  for (var i = 0; i < arguments.length; i++) {
    
    total += arguments[i];
  }
  
  console.log(total / arguments.length);
  
}

calculateAverage(1, 2); 
calculateAverage(1, 2, 3, 4, 5, 6, 7, 8, 9, 10); 
calculateAverage(77.2, 89, 57.4, 100, 62, 73, 87, 90); 

/*
Task 7 - Class Grades
*/
function formatGrades() {
    var letterGrade_str="";
    
    var letterFromScore = function(score){
        var letterGrade;
        switch(true){
            case (score>=90 && score<=100): 
                letterGrade="A+";           
                break;
            case (score>=80 && score<=89) :  
                letterGrade="A";
                break;
            case (score>=75 && score<=79) :
                letterGrade="B+";
                break;
            case (score>=70 && score<=74) :
                letterGrade="B";
                break;
            case (score>=65 && score<=69) :
                letterGrade="C+";
                break;
            case (score>=60 && score<=64) :
                letterGrade="C";
                break;
            case (score>=55 && score<=59) :
                letterGrade="D+";
                break;
            case (score>=50 && score<=54) :
                letterGrade="D";
                break;
            default:
                letterGrade="F";
                break;
        }
        return  letterGrade;
    };
    
    for(var i=0; i<arguments.length; i++){
           letterGrade_str =letterGrade_str + " "+ letterFromScore(arguments[i]);
    }
    
    return letterGrade_str.trim();

}    

console.log(formatGrades(77.2, 89, 57.4, 100, 62, 73, 87, 90));






