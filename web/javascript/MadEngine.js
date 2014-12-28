function NewWindow(){


  var window = document.createElement("div");

  window.className = "window";
  document.body.appendChild(window);

         $(function () {
            $(".window").draggable();
        });
    
}