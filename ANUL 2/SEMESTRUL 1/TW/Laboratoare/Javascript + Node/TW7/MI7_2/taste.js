var litera = null;

window.onkeydown = function(e){
    var tasta = e.key;
    if(!litera)
    {
        litera = document.createElement("div");
        this.document.body.appendChild(litera);
        litera.style.fontSize = "10px";
        this.litera.innerHTML = tasta;
    }
    else
    {
        this.litera.style.fontSize = parseInt(litera.style.fontSize) + 1 + "px";
    }

}

window.onkeyup = function(){
    if(litera){
        litera.remove();
        litera = null;

    }

}