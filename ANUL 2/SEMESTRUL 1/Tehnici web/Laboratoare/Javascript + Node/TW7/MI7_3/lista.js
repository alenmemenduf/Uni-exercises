window.onload = function(){
var lst = document.getElementById("lista");
for(li of lst.children)
{
    li.onclick = function(){
        this.style.color = "green";
        li_parcurgere = this;

        while(li_parcurgere){
            li_parcurgere = li_parcurgere.previousElementSibling;
            if(li_parcurgere)
                li_parcurgere.style.color = "red";
        }

        li_parcurgere = this;
        while(li_parcurgere){
            li_parcurgere = li_parcurgere.nextElementSibling;
            if(li_parcurgere)
                li_parcurgere.style.color = "blue";
        }
    }
}

}