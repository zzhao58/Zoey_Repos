/*********************************************************************************
* WEB322 – Assignment 02
* I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part
* of this assignment has been copied manually or electronically from any other source
* (including 3rd party web sites) or distributed to other students.
*
* Name: Zhi Zhao      Student ID: 109079178            Date: Jan 31,2019
*
* Online (Heroku) Link: __https://peaceful-harbor-69222.herokuapp.com/____
*
********************************************************************************/
var express = require('express');
var data_service = require('./data-service.js');
var HTTP_PORT = process.env.PORT || 8080;
var app = express();
var path = require("path");

function onHttpStart() {
    console.log("Express http server listening on: " + HTTP_PORT);
    return new Promise(
        function(reject, resolve){
        data_service.initialize()
                    .then((data)=>{console.log(data);})
                    .catch((err)=>{console.log(err); })
        }
      )
}

app.use(express.static('public'))

app.get('/', function (req, res) {
    res.sendFile(path.join(__dirname + '/views/home.html'));
})

app.get('/about', function (req, res) {
    res.sendFile(path.join(__dirname + '/views/about.html'));
})

app.get('/employees', function (req, res) {
    data_service.getAllEmployees().then((data)=>{
        res.json(data);
    }).catch((err)=>{
        res.json(err);
    })
})

app.get('/managers', function(req, res){
    data_service.getManagers().then((data)=>{
        res.json(data);
    }).catch((err)=>{
        res.json(err);
    });
})

app.get('/departments', function(req, res){
    data_service.getDepartments().then((data)=>{
        res.json(data);
    }).catch((err)=>{
        res.json(err);
    });
})

app.use(function(req, res){
    res.status(404).send("Page Not Found");
})

app.listen(HTTP_PORT, onHttpStart);