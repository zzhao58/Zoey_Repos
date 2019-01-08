/*********************************************************************************
* WEB322 – Assignment 1
* I declare that this assignment is my own work in accordance with Seneca Academic Policy.
* No part of this assignment has been copied manually or electronically from any other source
* (including web sites) or distributed to other students.
*
* Name: Zhi__Zhao____________________ Student ID: __109079178____________ Date: ___1/7/2019_____________
*
* Online (Heroku) URL: __https://frozen-anchorage-53217.herokuapp.com/
********************************************************************************/ 
var HTTP_PORT = process.env.PORT || 8080;
var express = require("express");
var app = express();

// setup a 'route' to listen on the default url path
app.get("/", (req, res) => {
    res.send("Zhi Zhao-109079178");
});

// setup http server to listen on HTTP_PORT
app.listen(HTTP_PORT); 