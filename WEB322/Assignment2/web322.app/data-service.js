
var fs = require('fs');
var employees=[];
var departments=[];

module.exports.initialize=function()
{
  function readFile_employees(){
  return new Promise(function(resolve, reject){
    fs.readFile('./data/employees.json', (err, data)=>{
          if(err)
          {
              reject("Unable to read file");
          }
          else
          {
              employees = JSON.parse(data);
              resolve(employees);
          }
    })
  });
 }

  function readFile_departments(){
  return new Promise(function(resolve, reject){
    fs.readFile('./data/departments.json', (err, data)=>{
        if(err)
        {
          reject("Unable to read file");
        }
        else
        {
            departments = JSON.parse(data);
            resolve(departments);
        }
    })
  });
 }

 return readFile_employees()
 .then(readFile_departments);
}


module.exports.getAllEmployees=function(){
    return new Promise((resolve, reject)=>{
      if(employees.length==0)
      {
        reject("no results returned");
      }
   
        resolve(employees); 
    });
  }

  module.exports.getManagers=function(){
    var managers=[];
    
    return new Promise((resolve, reject)=>{
      if(employees.length!=0)
      {      
          employees.forEach(function(element)
          {
           if(element.isManager==true)
               managers.push(element); 
          });
  
         resolve(managers);    
      }
      else
      {
         reject("no results returned.");
      }
    });
  }

  module.exports.getDepartments=function(){
    return new Promise((resolve, reject)=>{
      if(departments.length ==0)
      {
        reject("no results returned.");
      }
      
        resolve(departments);
    });    
  }
    

