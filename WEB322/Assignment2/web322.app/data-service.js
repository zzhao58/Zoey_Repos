
var employees = {};
var departments = [];
const fs = require("fs");

//Initialize
module.exports.initialize = function() {
    return new Promise(function(resolve, reject){
        try{
            fs.readFile('./data/employees.json', 
                        function(err, data){
                          if(err) throw err;
                          employees = JSON.parse(data);
                        }
                       );
            fs.readFile('./data/departments.json', 
                        function(err, data){
                        if(err) throw err;
                        departments = JSON.parse(data);
                        }
                       );
        } catch(ex){
            reject("unable to read file");
        }
        resolve("read file successfully");
    });
}

//getAllEmployees
module.exports.getAllEmployees = function(){
    //var allEmployees = [];
    return new Promise(function(reject, resolve){
        //  for(var i = 0; i < employees.length; i++){
        //      allEmployees.push(employees[i]);
        //  }        
        if(employees.length == 0){
            reject("allEmployees no results returned");
        }
        resolve(employees);
    });
}

//getManagers
module.exports.getManagers = function(){
    var managers = [];
    return new Promise(function(reject, resolve){
        if(employees.length == 0){
            reject("employees no results returned");
        }else{
            for(var j = 0; j < employees.length; j++){
                if(employees[j].isManager == true){
                    managers.push(employees[j]);
                }
            }
            if(managers.length == 0){
                reject("managers no results returned");
            }
        }
        resolve(managers);
    });
}

//getDepartments
module.exports.getDepartments = function(){
    var _departments = [];
    return new Promise(function(reject, resolve){
        if(employees.length == 0){
            reject("employees no results returned");
        }else{
            for(var k = 0; k < departments.length; k++){
                _departments.push(departments[k]);
            }
            if(_departments.length == 0){
                reject("_departments no results returned");
            }
        }
        resolve(_departments);
    });
}
