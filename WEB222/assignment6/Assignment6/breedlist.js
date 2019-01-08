
window.onload = function() {
    var url = "https://dog.ceo/api/breeds/list/all";
    var xhr = new XMLHttpRequest();

    xhr.onload = function() {
        // Given a breed name "beagle", return an <option value="beagle>beagle</option> 
        function createBreedOption(name) {
            var option = document.createElement("option");
            option.value = name;
            option.innerHTML = name;

            return option;
        }

        var response = JSON.parse(this.responseText);
        var breedList = extractBreedList(response);
        //updateBreedList(breedList);
        
        var select = document.querySelector("#breeds");
        breedList.forEach(function(breed) {
            var breedOption = createBreedOption(breed);
            select.appendChild(breedOption);
        });
    };
    xhr.open("GET", url);
    xhr.send();
};



var btnLoad = document.querySelector("#btn-load");

btnLoad.onclick = function(e) {
    var breed = document.querySelector("#breeds").value; 客户实际选择的品种
    //loadBreedImages(breed);

    var imageCount = document.querySelector("#image-count").value; 客户实际选择了多少张图片
    var url = `https://dog.ceo/api/breed/${breed}/images/random/${imageCount}`;
    var xhr = new XMLHttpRequest();

    xhr.onload = function() {
        try {
            // Turn a url String into an <img src="url"> element
            function createImgElement(url) {
                var img = document.createElement("img");
                img.src = url;
                return img;
            }

            var response = JSON.parse(this.responseText);
            var breedImageList = extractBreedImageList(response);
            updateBreedImages(breedImageList);

            
            var imagesContainer = document.querySelector("#images-container");
            imagesContainer.innerHTML = "";
            breedImageList.forEach(function(url) {
                var img = createImgElement(url);
                imagesContainer.appendChild(img);
            });

        } catch(e) {
            showError("Unable to load dog breeds");
        }
    };

    xhr.open("GET", url);
    xhr.send();
};