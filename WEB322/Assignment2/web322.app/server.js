
/*********************************************************************************
* WEB322 – Assignment 02
* I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part
* of this assignment has been copied manually or electronically from any other source
* (including 3rd party web sites) or distributed to other students.
*
* Name: Zhi Zhao    Student ID: 109079178   Date: Feb 1, 2019
*
* Online (Heroku) Link: https://pacific-ocean-67163.herokuapp.com/ 
*
********************************************************************************/ 
var employees = [];
var departments = [];
const fs = require("fs");

module.exports.initialize = function() {
    return new Promise(function(resolve, reject){
        try{
            fs.readFile('./data/employees.json', function(err, data){
                if(err) throw err;
                employees = JSON.parse(data);
            });
            fs.readFile('./data/departments.json', function(err, data){
                if(err) throw err;
                departments = JSON.parse(data);
            });
        } catch(ex){
            reject("unable to read file");
        }
        resolve("JSON files successfully");
    });
}


module.exports.getAllEmployees = function(){
    var _employees = [];
    return new Promise(function(reject, resolve){
        for(var i = 0; i < employees.length; i++){
            _employees.push(employees[i]);
        }
        if(_employees.length == 0){
            reject("_employees no results returned");
        }
        resolve(_employees);
    });
}


module.exports.getManagers = function(){
    var _managers = [];
    return new Promise(function(reject, resolve){
        if(employees.length == 0){
            reject("employees no results returned");
        }else{
            for(var i = 0; i < employees.length; i++){
                if(employees[i].isManager == true){
                    _managers.push(employees[i]);
                }
            }
            if(_managers.length == 0){
                reject("_managers no results returned");
            }
        }
        resolve(_managers);
    });
}

module.exports.getDepartments = function(){
    var _departments = [];
    return new Promise(function(reject, resolve){
        if(employees.length == 0){
            reject("employees no results returned");
        }else{
            for(var i = 0; i < departments.length; i++){
                _departments.push(departments[i]);
            }
            if(_departments.length == 0){
                reject("_departments no results returned");
            }
        }
        resolve(_departments);
    });
}
