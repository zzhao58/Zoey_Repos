
var fs = require('fs');

var employees = [];
var departments = [];
var managers = [];

module.exports.initialize = function () 
{
    return new Promise(function(resolve, reject) {
        fs.readFile("./data/employees.json", function(err, data) {
            if (err) {
                reject("unable to read file");
            }
            else { 
                employees = JSON.parse(data);
            }
        });
        
        fs.readFile("./data/departments.json", function(err, data) {
            if (err) {
                reject("unable to read file");
            }
            else {
                departments = JSON.parse(data);
            }
        });
        resolve("operation was a success");
    });
}


module.exports.getAllEmployees = function()
{
    return new Promise(function(resolve, reject){
        if (employees == 0)
        {
            reject("no results returned");
        }
        else
        {
            resolve(employees);
        }
    })
}

module.exports.getManagers = function()
{
    
    return new Promise(function(resolve, reject){
       
        for (let i=0; i < employees.length; i++)
        {
            if(employees[i].isManager == true)
            {
                managers[i] = employees[i];
            }
        }
        
        if (managers == 0)
        {
            reject("no results returned");
        }
        else
        {
            resolve(managers);
        }
    })
}

module.exports.getDepartments = function()
{
    return new Promise(function(resolve, reject){
        if (departments == 0)
        {
            reject("no results returned");
        }
        else
        {
            resolve(departments);
        }
    })
}


