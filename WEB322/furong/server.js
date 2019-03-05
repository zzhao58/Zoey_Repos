/********************************************************************************* 
 *  WEB322 â€“ Assignment 04 
 *  I declare that this assignment is my own work in accordance with Seneca  Academic Policy.  No part 
 *  of this assignment has been copied manually or electronically from any other source  * 
 *  (including 3rd party web sites) or distributed to other students. *  * 
 *  Name: _Qirong Fu_____________________ Student ID: _158899179_____________ Date: _Feb. 28, 2019________ * *  
 *  Online (Heroku) Link:  https://pure-reaches-85830.herokuapp.com/____________________________________ 
 * * ********************************************************************************/ 

var data_service = require("./data-service.js");

var HTTP_PORT = process.env.PORT || 8080;
var express = require("express");
var app = express();
var path = require("path");
var multer = require("multer");
var fs = require('fs');
const bodyParser = require('body-parser');
const exphbs = require('express-handlebars');

app.use(function(req,res,next){
    let route = req.baseUrl + req.path;  
    app.locals.activeRoute = (route == "/") ? "/" : route.replace(/\/$/, "");  
    next();
 }); 

function onHttpStart()
{
    console.log("Express http server listening on " + HTTP_PORT);
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
    res.render("images", {data: items});
});
})

app.use(bodyParser.urlencoded({extended:true}));

app.use(express.static('public'));

// setup a 'route' to listen on the default url path
app.get('/', function(req, res) {
    res.render('home');    
});

app.get('/about', function(req, res) {
    res.render('about');    
});

app.get('/employees/add', function(req, res){
    res.render('addEmployee');
});

app.get('/images/add', function(req, res){
    res.render('addImage');
});

app.get("/employees", ((req, res)=>{
    if(req.query.status){
        data_service.getEmployeesByStatus(req.query.status).then((data)=>{
            res.render("employees", {employees: data});
        })
        .catch((err)=>{
            res.render({message: "no results"});
        })     
    }
    else if(req.query.department){
        data_service.getEmployeesByDepartment(req.query.department).then((data)=>{
            res.render("employees", {employees: data});
        })
        .catch((err)=>{
            res.render({message: "no results"});
        })  
    }
    else if(req.query.employeeManagerNum){
        data_service.getEmployeesByManager(req.query.employeeManagerNum).then((data)=>{
            res.render("employees", {employees: data});
        })
        .catch((err)=>{
            res.render({message: "no results"});
        })
    }
    else{
        data_service.getAllEmployees().then((data)=>{
            res.render("employees", {employees: data});
        })
        .catch((err)=>{
            res.render({message: "no results"});
        })
    }    
}));

app.get("/employee/:empNum", ((req, res)=>{
    data_service.getEmployeeByNum(req.params.empNum).then((data)=>{
        res.render("employee", {employee: data});
    })
    .catch((err)=>{
        res.render("employee", {message: "no results"});
    });
}));

app.post("/employee/update", (req, res) => {  
  data_service.updateEmployee(req.body).then(()=>{
    res.redirect("/employees"); 
  }).catch(()=>{
    console.log(err);
    });
}); 

app.get("/departments", function(req, res) {
    data_service.getDepartments().then((data)=>{
        res.render("departments", {departments: data});
    })
    .catch((err)=>{
        res.render({message: "no results"});      
    }) 
});

app.post("/employees/add", function(req, res) {
data_service.addEmployee(req.body).then(()=>{
    res.redirect("/employees");
})
});

app.use((req, res) => {
    res.status(404).send("Page Not Found");
});

data_service.initialize()
.then(()=>{
    app.listen(HTTP_PORT, onHttpStart)
}).catch(()=>{
    console.log(err);
});

app.engine('.hbs', exphbs({ 
    extname: '.hbs', 
    defaultLayout: 'main',
    helpers:{
    navLink: function(url, options){  
      return '<li' +  
        ((url == app.locals.activeRoute) ? ' class="active" ' : '') +  
        '><a href="' + url + '">' + options.fn(this) + '</a></li>'; 
    },
    equal: function (lvalue, rvalue, options) { 
      if (arguments.length < 3)   
         throw new Error("Handlebars Helper equal needs 2 parameters");  
         if (lvalue != rvalue) {  
             return options.inverse(this);  
         } else {     
            return options.fn(this);    
        } 
    }    
  }
}));

app.set('view engine', '.hbs');

