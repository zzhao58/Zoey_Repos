var employees=[];
var departments=[];

module.exports.initialize=function()
{
  const fs = require('fs');

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

module.exports.addEmployee=(employeeData)=>{
  return new Promise((resolve, reject)=>{
    if(employeeData.isManager==null)
    {
      employeeData.isManager=false;
    }
    else
    {
      employeeData.isManager=true; 
   
      employeeData.employeeNum=employees.length+1;
      employees.push(employeeData);   
    }

    resolve(employees);
  });
}
  
module.exports.getEmployeesByStatus=(status)=>{ 
  var employees_status=[];

  return new Promise((resolve, reject)=>{    
    if(employees.length!=0)
     {
       employees.forEach(function(element)
        {
          if(element.status==status)
           {
             employees_status.push(element);
           }
        })
     }
    if(employees_status.length==0)
        {
          reject("no results returned");
        }  
       
          resolve(employees_status);
     });
}

module.exports.getEmployeesByDepartment=(department)=>{
  var employees_department=[];

  return new Promise((resolve, reject)=>{  
    if(employees.length!=0)
      {
        employees.forEach(function(element)
         {
           if(element.department==department)
             {
               employees_department.push(element);
             }
         })
      }
    if(employees_department.length==0)
      {
         reject("no results returned");
      }   

         resolve(employees_department);
   });
}

module.exports.getEmployeesByManager=(employeeManagerNum)=>{
  var employees_manager=[];

  return new Promise((resolve, reject)=>{       
    if(employees.length!=0)
      {
        employees.forEach(function(element)
         {
          if(element.employeeManagerNum==employeeManagerNum)
            {
              employees_manager.push(element);
            }
         })
      }
    if(employees_manager.length==0)
      {
        reject("no results returned");
      }  

        resolve(employees_manager);
    });
}

module.exports.getEmployeeByNum=(employeeNum)=>{
  var employees_employeeNum=[];

  return new Promise((resolve, reject)=>{
    if(employees.length!=0)
    {
       employees.forEach(function(element)
        {
          if(element.employeeNum==employeeNum)
           {
              employees_employeeNum.push(element);
           }
        })
    }
    if(employees_employeeNum.length==0)
     {
         reject("no results returned");
     }  
            
         resolve(employees_employeeNum);
    });
}
