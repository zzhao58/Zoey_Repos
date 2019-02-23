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
var multer = require("multer");
var fs = require('fs');
const bodyParser = require('body-parser');

function onHttpStart() {
    console.log("Express http server listening on: " + HTTP_PORT);
    return new Promise(
        function(reject, resolve){
            data_service.initialize()
                        .then((data)=>{console.log(data);})
                        .catch((err)=>{console.log(err) ;})
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

app.post("/images/add", upload.single("imageFile"), (req, res)=>{
    res.redirect("/images");
});

app.get("/images", (req,res)=>{
fs.readdir("./public/images/uploaded", function(err, items){    
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


app.get("/employees", ((req, res)=>{
    if(req.query.status){
        data_service.getEmployeesByStatus(req.query.status).then((data)=>{
            res.json(data);
        })
        .catch((err)=>{
            res.send(err);
        })     
    }
    else if(req.query.department) {
        data_service.getEmployeesByDepartment(req.query.department).then((data)=>{
            res.json(data);
        })
        .catch((err)=>{
            res.send(err);
        })  
    }
    else if(req.query.employeeManagerNum){
        data_service.getEmployeesByManager(req.query.employeeManagerNum).then((data)=>{
            res.json(data);
        })
        .catch((err)=>{
            res.send(err);
        })
    }
    else{
        data_service.getAllEmployees().then((data)=>{
            res.json(data);
        })
        .catch((err)=>{
            res.send(err);
        })
    }    
}));

app.get("/employees/:value", ((req, res)=>{
    data_service.getEmployeeByNum(req.params.value).then((data)=>{
        res.json(data);
    })
    .catch((err)=>{
        res.send(err);
    });
}));


app.get('/managers', function(req, res){
    data_service.getManagers().then((data)=>{
        res.json(data);
    }).catch((err)=>{
        res.send(err);
    });
})

app.get('/departments', function(req, res){
    data_service.getDepartments().then((data)=>{
        res.json(data);
    }).catch((err)=>{
        res.send(err);
    });
})

app.post("/employees/add", function(req, res) {
    data_service.addEmployee(req.body).then(()=>{
        res.redirect("/employees");
    })
    });

app.use(function(req, res){
    res.status(404).send("Page Not Found");
})

app.listen(HTTP_PORT, onHttpStart);