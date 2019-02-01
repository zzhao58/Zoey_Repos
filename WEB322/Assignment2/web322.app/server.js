
var express = require("express");
var app = express();
var path = require("path");
var dataService=require("./data-service.js");

var HTTP_PORT = process.env.PORT || 8080;

// call this function after the http server starts listening for requests
function onHttpStart() {
  console.log("Express http server listening on: " + HTTP_PORT);
}

app.use(express.static('public'));

// setup a 'route' to listen on the default url path (http://localhost)
app.get("/", function(req,res){
  res.send("Hello World<br /><a href='/about'>Go to the about page</a>");
});

// setup another route to listen on /about
app.get("/about", function(req,res){
  res.sendFile(path.join(__dirname, "/views/about.html"));
});

app.get("/managers", function(req, res){
  dataService.getManagers().then(function(data){
      res.json(data)
  }).catch(function(err){message:err});
  //res.send("TODO: get all employees who have isManager==true");
});

app.get("/departments", function(req, res){
  dataService.getDepartments().then(function(data){
      res.json(data)
  }).catch(function(err){message:err});

  //res.json(path.join(__dirname, "/data/departments.json"));
  
});

app.get("/employees", function(req, res){
  dataService.getAllEmployees().then(function(data){
      res.json(data)
  }).catch(function(err){message:err});
  //res.json(path.join(__dirname, "/views/employees.json"));
});

app.get("*", function(req, res){
  res.status(404).send("Page Not Found!");
});

app.use((req, res) => {
  res.status(404).send("Page Not Found");
});


dataService.initialize().then(function(){app.listen(HTTP_PORT, onHttpStart)}).catch(function(err){console.log(err)});




// setup http server to listen on HTTP_PORT
app.listen(HTTP_PORT, onHttpStart);