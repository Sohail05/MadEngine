function Close(id){

   var find = "#"+id; 
$(find).remove();

    
    console.debug(find);
}


function Min(id){

    
   var find = document.getElementById(id); 
   var min;
   var context;
   console.debug(find);

    for (var i = 0; i < find.childNodes.length; i++) {
        
        if ( find.childNodes[i].className == "content") {
            context = find.childNodes[i];
            context.style.display = 'none';
        }    

    }
    if(find.style.zIndex > 1){
    find.style.zIndex--;
    }
}


function Max(id){

    
   var find = document.getElementById(id); 
   var min;
   var context;
   console.debug(find);

    for (var i = 0; i < find.childNodes.length; i++) {
        
        if ( find.childNodes[i].className == "content") {
            context = find.childNodes[i];
            context.style.display = 'block';
        }    

    }
    find.style.zIndex++;
    
}



var ID=0;

function NewWindow(){

    var window = document.createElement("div");
    var toolbar = document.createElement("div");
    var content = document.createElement("div");
    var title = document.createElement("span");
    
    //Toolbar Buttons
    var Closebutton = document.createElement("button");
    var Minbutton = document.createElement("button");
    var Maxbutton = document.createElement("button");
    
    //Elements Class
    window.className = "window";
    window.id = "window-"+ID; ID++;
    toolbar.className = "toolbar"; 
    content.className = "content";
    
    //Toolbar Buttons Class
    Closebutton.className = "close";  
    Minbutton.className = "min"; 
    Maxbutton.className = "max";
    
    //HTML content
    Closebutton.innerHTML = "X";  
    Minbutton.innerHTML = "-";
    Maxbutton.innerHTML = "+";
    content.innerHTML = "";
    title.innerHTML +=" Window ";
    
    
    Closebutton.onclick = function() { Close(window.id); }; 
    Minbutton.onclick = function() { Min(window.id); }; 
    Maxbutton.onclick = function() { Max(window.id); }; 
    
    toolbar.appendChild(Closebutton);
    toolbar.appendChild(Minbutton);
    toolbar.appendChild(Maxbutton);
    toolbar.appendChild(title);
   
    
    window.appendChild(toolbar);
    window.appendChild(content);
    
    document.body.appendChild(window);

         $(function () {
            $(".window").draggable({containment: "parent"});
        });
    
    
    return window.id;
}



function InjectScript() {


    var window = document.getElementById(NewWindow());

    var s = document.createElement('script');
    s.setAttribute('src', 'js/myscript.js');
    s.id = window.id+"-script";
    
    
    var inputtext = document.createElement("input");
    inputtext.nodeType="text";
    

    var label = document.createElement("label");
    label.innerHTML="Script Name:";
    
    var TextArea = document.createElement("Textarea");
    TextArea.innerHTML="ChangeColor(255,0,0)";
    //TextArea.style.width="100";
    
    
    
    var RunButton = document.createElement("button");
    RunButton.innerHTML = "Run"; 
    RunButton.onclick = function() { Run(window.id , s.id); }; 
    
    console.debug(window);
    
    //Get Child Content
    
    var content;
    for (var i = 0; i < window.childNodes.length; i++) {

        if (window.childNodes[i].className == "content") {
            content = window.childNodes[i]; 
        }

    }
    
    
    
    
    content.appendChild(label);
    content.appendChild(inputtext);
    content.appendChild(document.createElement("br"));
    content.appendChild(TextArea);
    content.appendChild(document.createElement("br"));
    content.appendChild(RunButton);
    //s.appendChild(document.createTextNode("Hello"));
    
    
    
    window.appendChild(s);

} 


function Run(windowid, scriptid) {


    var script = document.getElementById(scriptid);
    var window = document.getElementById(windowid);


    var content;
    for (var i = 0; i < window.childNodes.length; i++) {

        if (window.childNodes[i].className == "content") {
            content = window.childNodes[i];
        }


    }

    //console.debug(content);
    var textarea = content.getElementsByTagName("textarea")[0];


   // console.debug(textarea.value);
   // script.innerHTML = textarea.value;



    var functiondata = textarea.value;

    var F = new Function(functiondata);

    F();


}
  
    
    
    
    
    
    
    