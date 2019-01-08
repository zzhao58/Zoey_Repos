function calculateAgeStats(birthDate) {
    
    var weekdays=["Sun","Mon","Tue","Wed","Thu","Fri","Sat"];
      
    var dob = new Date(birthDate);  
    var weekday_name = weekdays[dob.getDay()];
    
    var current_time = Date.now();
    var elapse = Math.floor((current_time - dob)/1000/3600);
    console.log("You were born on " + weekday_name + " " + birthDate + " and have been alive for approximately " + elapse + " hours.")
  }
  
  calculateAgeStats("Dec 23, 2000");