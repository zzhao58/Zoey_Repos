// All you JavaScript code for assignment 4 should be in this file

window.addEventListener(
    'load',
    function(){
        var language = "English";
        
        listCountry("menu1");

        document.querySelector("#menu_1").onclick  = function() { listCountry('menu1');  };
        document.querySelector("#menu_21").onclick = function() { listCountry('menu21'); };
        document.querySelector("#menu_22").onclick = function() { listCountry('menu22'); };
        document.querySelector("#menu_31").onclick = function() { listCountry('menu31'); };
        document.querySelector("#menu_32").onclick = function() { listCountry('menu32'); };
        document.querySelector("#menu_41").onclick = function() { listCountry('menu41'); };
        document.querySelector("#menu_42").onclick = function() { listCountry('menu42'); };
        document.querySelector("#menu_43").onclick = function() { listCountry('menu43'); };
        document.querySelector("#menu_44").onclick = function() { listCountry('menu44'); };
        document.querySelector("#menu_45").onclick = function() { listCountry('menu45'); };
        document.querySelector("#menu_46").onclick = function() { listCountry('menu46'); };
        document.querySelector("#menu_47").onclick = function() { listCountry('menu47'); };
        document.querySelector("#menu_48").onclick = function() { listCountry('menu48'); };

        function insertCells(elm, newRow, language){
           //insert new cell for flag
           var cellFlag=newRow.insertCell(0);
           var elmFlag = document.createElement('img');
           elmFlag.src = "flags/" + elm.Code + ".png";
           cellFlag.appendChild(elmFlag);
        
           //insert new cell for code
           var cellCode=newRow.insertCell(1);
           var elmCode = document.createTextNode(elm.Code);
           cellCode.appendChild(elmCode);
            
           //insert new cell for name
           var cellName=newRow.insertCell(2);
           var elmName = document.createTextNode(elm.Name[language]);
           cellName.appendChild(elmName);
        
           //insert new cell for continent
           var cellContinent=newRow.insertCell(3);
           var elmContinent = document.createTextNode(elm.Continent);
           cellContinent.appendChild(elmContinent);
        
           //insert new cell for areainkm2
           var cellAreaInKm2=newRow.insertCell(4);
           var elmAreaInKm2 = document.createTextNode(elm.AreaInKm2);
           cellAreaInKm2.appendChild(elmAreaInKm2);
        
           //insert new cell for population
           var cellPopulation=newRow.insertCell(5);
           var elmPopulation = document.createTextNode(elm.Population);
           cellPopulation.appendChild(elmPopulation);
        
           //insert new cell for capital
           var cellCapital=newRow.insertCell(6);
           var elmCapital = document.createTextNode(elm.Capital);
           cellCapital.appendChild(elmCapital);
        }

        function listCountry(menuOption){
            
            //get reference of outputTable
            var tableRef = document.querySelector('#outputTable');
            var subtitleRef = document.querySelector('#subtitle');
            
            //remove old tbody and append a new tbody obj.
            var OldtbodyRef = document.querySelector('#outputBody');
            if(OldtbodyRef) tableRef.removeChild(OldtbodyRef);
            var tbodyRef=document.createElement('tbody');
            tbodyRef.id="outputBody";           
            tableRef.appendChild(tbodyRef);         
            
            switch(menuOption){
                case 'menu1' :                                         
                    language = "English";
                    subtitleRef.innerHTML="List of Countries and Dependencies"; 
                    break;
                case 'menu21':
                    language = "English";
                    subtitleRef.innerHTML="List of Countries and Dependencies - Population greater than 100 million"; 
                    break;
                case 'menu22':
                    language = "English";
                    subtitleRef.innerHTML="List of Countries and Dependencies - Population between 1 and 2 million"; 
                    break;
                case 'menu31':
                    language = "English";
                    subtitleRef.innerHTML="List of Countries and Dependencies - Area greater than 1 million Km², Americas"; 
                    break;
                case 'menu32':
                    language = "English";
                    subtitleRef.innerHTML="List of Countries and Dependencies - All countries in Asia"; 
                    break;
                case 'menu41':
                    language = "English";
                    subtitleRef.innerHTML="List of Countries and Dependencies - Country/Dep. Name in English"; 
                    break;    
                case 'menu42':
                    language = "Arabic";
                    subtitleRef.innerHTML="List of Countries and Dependencies - Country/Dep. Name in Arabic"; 
                    break;
                case 'menu43':
                    language = "Chinese";
                    subtitleRef.innerHTML="List of Countries and Dependencies - Country/Dep. Name in Chinese (中文)"; 
                    break;
                case 'menu44':
                    language = "Franch";
                    subtitleRef.innerHTML="List of Countries and Dependencies - Country/Dep. Name in Franch"; 
                    break;
                case 'menu45':
                    language = "Hindi";
                    subtitleRef.innerHTML="List of Countries and Dependencies - Country/Dep. Name in Hindi"; 
                    break;
                case 'menu46':
                    language = "Korean";
                    subtitleRef.innerHTML="List of Countries and Dependencies - Country/Dep. Name in Korean"; 
                    break;
                case 'menu47':
                    language = "Japanese";
                    subtitleRef.innerHTML="List of Countries and Dependencies - Country/Dep. Name in Japanese"; 
                    break;
                case 'menu48': 
                    language = "Russian";
                    subtitleRef.innerHTML="List of Countries and Dependencies - Country/Dep. Name in Russian"; 
                    break;
                default:
                    language = "English";
                    subtitleRef.innerHTML="List of Countries and Dependencies - Country/Dep. Name in English";                     
            }
            
            //loop for each country [OK]
            countries.forEach(
                function(elm){
                    //insert a new row in tbody
                    var newRow = tbodyRef.insertRow();            
                    
                    switch(menuOption){
                        case 'menu1' : 
                            insertCells(elm, newRow, language);
                            break;
                        case 'menu21':
                            if(elm.Population>100000000){
                                insertCells(elm, newRow, language);        
                            }
                            break;
                        case 'menu22':
                            if(elm.Population >= 1000000 && elm.Population <= 2000000){
                                insertCells(elm, newRow, language);        
                            }
                            break;
                        case 'menu31':
                            if(elm.AreaInKm2 > 1000000 && elm.Continent=="Americas" ){
                                insertCells(elm, newRow, language);
                            }
                            break;
                        case 'menu32':
                            if(elm.Continent=="Asia"){
                                insertCells(elm, newRow, language);
                            }
                            break;
                        case 'menu41':                        
                        case 'menu42':
                        case 'menu43':
                        case 'menu44':
                        case 'menu45':
                        case 'menu46':
                        case 'menu47':
                        case 'menu48':
                            insertCells(elm, newRow, language);
                            break;
                    }
                }
            );     

        }
        
    }
);


