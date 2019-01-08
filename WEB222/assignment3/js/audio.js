// Data for the "HTML Audio" Page

var audio = {
    controls: true, 
    source: [
        {src: "https://scs.senecac.on.ca/~tanvir.alam/shared/fall-2018/web222/Track03.mp3", type: "audio/mpeg"},
        {src: "https://scs.senecac.on.ca/~tanvir.alam/shared/fall-2018/web222/Track03.ogg", type: "audio/ogg"}
    ]
};

window.addEventListener(
    'load', 
    function() {
        //find out the goal position
        var audioDiv = document.querySelector('#audioDiv');
                    
        //constructor my object body
        var sourceArr = audio.source;
        var audioArry = sourceArr.map(
            function(x){
                if(audio.controls)
                    return "<audio controls src='" + x.src + "'></audio>";
                else
                    return "<audio src='" + x.src + "'></audio>";	
            }
        );	
        //creat a full object
        audioDiv.innerHTML = audioArry.join("<br>");    			
    }
)	