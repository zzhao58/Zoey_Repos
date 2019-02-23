/*********************************************************************************
* WEB322 – Assignment 03
* I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part
* of this assignment has been copied manually or electronically from any other source
* (including 3rd party web sites) or distributed to other students.
*
* Name: Zhi Zhao      Student ID: 109079178            Date: Feb 22,2019
*
* Online (Heroku) Link: _https://gentle-bayou-56650.herokuapp.com/___
*
********************************************************************************/
var express = require('express');
var data_service = require('./data-service.js');
var HTTP_PORT = process.env.PORT || 8080;
var app = express();
var path = require("path");
var multer = require("multer");
var fs = require('fs');
const bodyParser = require('body-parser');

function onHttpStart() {
    console.log("Express http server listening on: " + HTTP_PORT);
    return new Promise(
        function(reject, resolve){
            data_service.initialize()
                        .then((data)=>{console.log(data);})
                        .catch((error)=>{console.log(error) ;})
        }
    )
}

const storage = multer.diskStorage({
    destination: "./public/images/uploaded",
    filname: function(req, file, cb){
        cb(null, Date.now() + path.extname(file.originalname));
    }
});

const upload = multer({storage: storage});

app.post("/images/add", upload.single("imageFile"), function(req, res){
    res.redirect("/images");
});

app.get("/images", function(req,res){
fs.readdir("./public/images/uploaded", function(error, items){    
    res.json({"images":items});
});
})

app.use(bodyParser.urlencoded({extended:true}));

app.use(express.static('public'))

app.get('/', function (req, res) {
    res.sendFile(path.join(__dirname + '/views/home.html'));
})

app.get('/about', function (req, res) {
    res.sendFile(path.join(__dirname + '/views/about.html'));
})

app.get("/employees/add", function(req, res){
    res.sendFile(path.join(__dirname, "/views/addEmployee.html"));
});

app.get("/images/add", function(req, res){
    res.sendFile(path.join(__dirname, "/views/addImage.html"));
});


app.get("/employees", function(req, res){
    if(req.query.status){
        data_service.getEmployeesByStatus(req.query.status).then((data)=>{
            res.json(data);
        })
        .catch((error)=>{
            res.send(error);
        })     
    }
    else if(req.query.department) {
        data_service.getEmployeesByDepartment(req.query.department).then((data)=>{
            res.json(data);
        })
        .catch((error)=>{
            res.send(error);
        })  
    }
    else if(req.query.employeeManagerNum){
        data_service.getEmployeesByManager(req.query.employeeManagerNum).then((data)=>{
            res.json(data);
        })
        .catch((error)=>{
            res.send(error);
        })
    }
    else{
        data_service.getAllEmployees().then((data)=>{
            res.json(data);
        })
        .catch((error)=>{
            res.send(error);
        })
    }    
});

app.get("/employees/:value", function(req, res){
    data_service.getEmployeeByNum(req.params.value).then((data)=>{
        res.json(data);
    })
    .catch((error)=>{
        res.send(error);
    });
});


app.get('/managers', function(req, res){
    data_service.getManagers().then((data)=>{
        res.json(data);
    }).catch((error)=>{
        res.send(error);
    });
})

app.get('/departments', function(req, res){
    data_service.getDepartments().then((data)=>{
        res.json(data);
    }).catch((error)=>{
        res.send(error);
    });
})

app.post("/employees/add", function(req, res) {
    data_service.addEmployee(req.body).then(()=>{
        res.redirect("/employees");
    })
    });

app.use(function(req, res){
    res.status(404).send("Error 404: The page you request is not found!!");
})

app.listen(HTTP_PORT, onHttpStart);