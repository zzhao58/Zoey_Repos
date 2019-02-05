
var express = require("express");
var app = express();
var path = require("path");
var dataService=require("./data-service.js");

var HTTP_PORT = process.env.PORT || 8080;


function onHttpStart() {
  console.log("Express http server listening on: " + HTTP_PORT);
}

app.use(express.static('public'));//put ahead the first "app"


app.get("/", function(req,res){
  res.send("Hello World<br /><a href='/about'>Go to the about page</a>");
});


app.get("/about", function(req,res){
  res.sendFile(path.join(__dirname, "/views/about.html"));
});

app.get("/managers", function(req, res){
  dataService.getManagers().then(function(data){
      res.json(data)
  }).catch(function(err){res.send(err);});
 
});

app.get("/departments", function(req, res){
  dataService.getDepartments().then(function(data){
      res.json(data)
  }).catch(function(err){res.send(err);});
});

app.get("/employees", function(req, res){
  dataService.getAllEmployees().then(function(data){
      res.json(data);
  }).catch(function(err){res.send(err);});

});


app.use((req, res) => {
  res.status(404).send("Page Not Found");
});


dataService.initialize().then(function(){app.listen(HTTP_PORT, onHttpStart)}).catch(function(err){console.log(err)});
