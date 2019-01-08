// Data for the "HTML Video" Page

var video = {
    controls: true, 
    width: 320,
    height: 240,
    source: [
        {src: "https://scs.senecac.on.ca/~tanvir.alam/shared/fall-2018/web222/movie.mp4", type: "video/mp4"},
        {src: "https://scs.senecac.on.ca/~tanvir.alam/shared/fall-2018/web222/movie.ogg", type: "video/ogg"}
    ]

};


window.addEventListener(
			'load', 
			function() {
				//find out the goal position
				var videoDiv = document.querySelector('#videoDiv');
							
				//constructor my object body
				var sourceArr = video.source;
				var videoArr  = sourceArr.map(
					function (x){ 
						if(video.controls)
							return "<video controls width=" + video.width + " height="+ video.height +" src='" + x.src + "'></video>";
						else
							return "<video width=" + video.width + " height="+ video.height +" src='" + x.src + "'></video>";
					}
				);
				videoDiv.innerHTML = videoArr.join("<br>");    			
		});	