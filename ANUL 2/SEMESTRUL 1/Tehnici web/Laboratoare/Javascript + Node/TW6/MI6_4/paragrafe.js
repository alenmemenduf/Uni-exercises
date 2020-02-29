window.onload=function(){

	document.getElementById("albastreste").onclick = albastreste /* in loc de null scriem albastreste dar fara paranteze
															 pentru ca avem nevoie de referinta nu de valoare returnata */

}

function albastreste(){
	pgfs=document.querySelectorAll("p");
	for(pg of pgfs){
		stil = getComputedStyle(pg); // getComputedStyle ia valoarea style-ului din CSS dar nu poti sa o modifici aici (creeaza o copie)
		// console.log(stil.color); afiseaza un sir "rgb . . ." deci conteaza spatiile de dupa virgule
		if(stil.color == "rgb(255, 0, 0)")
			pg.style.color = "rgb(0, 0, 255)";
	}
	//de observat si apoi de comentat
	/*alert(pgfs[0].style.color)
	pgfs[0].style.color="blue"
	alert(pgfs[0].style.color)
	*/
}