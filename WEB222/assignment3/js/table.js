// Data for the "HTML Tables" Page

var users = [
    {first_name: "Kaitlin", last_name: "Burns",   age: 23, email: "kburns99753@usermail.com"},
    {first_name: "Joshua",  last_name: "Feir",    age: 31, email: "josh319726@usermail.com"},
    {first_name: "Stephen", last_name: "Shaw",    age: 28, email: "steve.shaw47628@usermail.com"},
    {first_name: "Timothy", last_name: "McAlpine",age: 37, email: "Timbo72469@usermail.com"},
    {first_name: "Sarah",   last_name: "Connor",  age: 19, email: "SarahC6320@usermail.com"}
];

window.addEventListener(
    'load', 
    function() {
        var table3 = document.createElement('table');
        table3.style = "border:1px solid;";
        table3.border = 1;

        var titleHTML = "<tr><th>First Name</th><th>Last Name</th><th>Age</th><th>Email</th></tr>";
        var userRows = users.map( function(x) {
            var userRow = "";	
            userRow = "<tr>";
            userRow = userRow + ("<td>" + x.first_name + "</td>");
            userRow = userRow + ("<td>" + x.last_name + "</td>");
            userRow = userRow + ("<td>" + x.age + "</td>");
            userRow = userRow + ("<td><a href='mailto:" + x.email +"' target='_blank'>" + x.email + "</a></td>");
            userRow = userRow + "</td>"
            return userRow;
            } 
        );
        var bodyHTML = userRows.join("");
        var fullHTML = titleHTML + bodyHTML;								
        
        table3.innerHTML = fullHTML;				
        var divContainer = document.querySelector('#usersInfo');    
        divContainer.appendChild(table3);
    }
);	