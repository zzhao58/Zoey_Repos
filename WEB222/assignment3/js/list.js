// Data for the "HTML Lists" Page

var fruits = [ "Apples","Oranges","Pears","Grapes","Pineapples","Mangos" ];

var directory = [
    {type: "file", name: "file1.txt"},
    {type: "file", name: "file2.txt"},
    {type: "directory", name: "HTML Files", files: [{type: "file", name: "file1.html"},{type: "file", name: "file2.html"}] },
    {type: "file", name: "file3.txt"},
    {type: "directory", name: "JavaScript Files", files: [{type: "file", name: "file1.js"},{type: "file", name: "file2.js"},{type: "file", name: "file3.js"}]}
];
             
var listHTML = "";
			
			//recursive function
			function arrtoHTML(arr){
				listHTML = listHTML + "<ul>";			
				arr.forEach(
					function(elm){
						if(elm.type=="file"){
							listHTML = listHTML + ("<li>"+ elm.name + "</li>");		
						}else{
							listHTML = listHTML + ("<li>"+ elm.name );
							arrtoHTML(elm.files);
							listHTML = listHTML + "</li>";
						}
						
					}
				);
				listHTML = listHTML + "</ul>";
			}
	
			window.addEventListener(
				'load', 
				function() {
					//FrutsList
					var fruitsList = document.createElement('ol');
	
					//concatnate each elemtns to have <li> and </li>, 
					//fruitsli = [ "<li>Apples</li>","<li>Oranges</li>","<li>Pears</li>","<li>Grapes</li>","<li>Pineapples</li>","<li>Mangos</li>" ];
					var fruitsli = fruits.map(x => "<li>"+ x +"</li>");
					
					//join all elements to one string, i.e. "<li>Apples</li><li>Oranges</li><li>Pears</li><li>Grapes</li><li>Pineapples</li><li>Mangos</li>"
					//insert this string to new created <ol></ol>
					fruitsList.innerHTML = fruitsli.join("");    
					var divContainer1 = document.querySelector('#container1');    
					divContainer1.appendChild(fruitsList);
					
					//Directory
					var divContainer2 = document.querySelector('#container2');
					arrtoHTML(directory);
					divContainer2.innerHTML = listHTML;
					
				}
			);	