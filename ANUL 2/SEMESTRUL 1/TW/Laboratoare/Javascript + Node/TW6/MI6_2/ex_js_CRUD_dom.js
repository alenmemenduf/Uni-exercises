function randInt(a,b){
	return Math.trunc(a+(b-a)*Math.random());
}


var vPrenume=["Costica", "Gigel", "Dorel", "Maricica", "Dorica", "Gigileana", "Crinisoara", "Zoe", "Gogu", "Bob"];
var vPrefixeNume=["Bubul", "Bondar", "Dudul", "Gogul", "Zumzul"];
var vSufixeNume=["ache", "escu", "esteanu","eanu", "eschi"];
var grupe=["A", "B", "C", "D"];
nrLog=0;

function noteRandom(){
	var nrNote=randInt(1,5);
	var note=[];
	for(let i=0;i<nrNote;i++)
	{
		note.push(randInt(1,11));
	}
	return note;
}

function elevRandom(){
	return{
		prenume: vPrenume[randInt(0, vPrenume.length)],
		nume: vPrefixeNume[randInt(0, vPrefixeNume.length)]+vSufixeNume[randInt(0, vSufixeNume.length)],
		grupa: grupe[randInt(0, grupe.length)],
		note: noteRandom()
	};
}
function genereazaElevi(n){
	var elevi=[];
	for(let i=0;i<n;i++){
		elevi.push(elevRandom());
	}
	console.log(elevi);
	return elevi;
}

function creeazaRand(tipCelula, vector){
	var tr=document.createElement("tr"); //TO DO sa se creeze un rand
	for(x of vector){
		var celula=document.createElement(tipCelula);
		celula.innerHTML = x; //TO DO continutul celulei trebuie sa fie valoarea din vector
		tr.appendChild(celula);// TO DO adaugati celula in rand
	}
	tr.onclick=function(){
		//TO DO corectati
	if(event.ctrlKey){
		this.remove();
		printLog(" am sters un elev");
	} // DACA CONTROL E APASAT
	else{
		this.classList.toggle("selectat");
		if(this.classList.contains("selectat"))
			printLog("elev selectat")
		else printLog("elev deselectat");
		}
	}
	return tr;
}

function printLog(logtext){
	var info = document.getElementById("info");
	var p = document.createElement("p");
	p.innerHTML = "[" + (new Date()) + "]" + logtext;
	info.appendChild(p);
	nrLog++;
	info.title=nrLog;
	info.scrollTop = info.scrollHeight;
}
function creeazaTabel(elevi){
	if(!elevi || elevi.length==0) return;
	
	var tabel=document.createElement("table");
	tabel.id="tab";
	var thead=document.createElement("thead");// TO DO - creare thead
	tabel.appendChild(thead) // TO DO - adugare thead in tabel
	var rand=creeazaRand("th",Object.keys(elevi[0]));
	console.log("Proprietati:");console.log(Object.keys(elevi[0]));
	thead.appendChild(rand);
		
	
	var tbody=document.createElement("tbody");
	tabel.appendChild(tbody);
	for(elev of elevi){ //TO DO vrem ca variabila elev sa aiba pe rand ca valoare fiecare element din elevi
		rand=creeazaRand("td",Object.values(elev));
		console.log("Valori:");console.log(Object.values(elev));
		tbody.appendChild(rand);
		rand.classList.add(elev.grupa);//clasa sa fie egala cu clasa elevului
		
		
	}
	return tabel;
}
window.onload=function(){
	var v_elevi=genereazaElevi(10);
	document.getElementById("container_tabel").appendChild(creeazaTabel(v_elevi));
	document.getElementById("add_inceput").onclick = function(){
		var rand = creeazaRand("td",Object.values(elevRandom()));
		var tabel = document.getElementById("tab");
		var tbody = tabel.getElementsByTagName("tbody")[0]; // e ELEMENTS by tag name deci iti da o lista si iei primul element
		tbody.insertBefore(rand,tbody.firstChild);

	}
	
	document.getElementById("deselectare").onclick = function(){		
		var tabel = document.getElementById("tab");
		var tbody = tabel.getElementsByTagName("tbody")[0];
		var randuri = tbody.getElementsByClassName("selectat");
		while(randuri.length > 0)
			randuri[0].classList.remove("selectat");

	}
	/*
	var randuri = tbody.querySelectorAll(".selectat")
	for(let i=0;i<randuri.length;i++)
		randuri[i].classList.remove("selectat");
	}
	*/

	document.getElementById("sterge").onclick = function(){
		var tabel = document.getElementById("tab");
		var tbody = tabel.getElementsByTagName("tbody")[0];

		do{
			var rasp = prompt("Clasa ?");
	
			}while(grupe.indexOf(rasp)==-1)
			deselectare();
		
		var elevi = tabel.querySelectorAll("."+rasp);
		for(el of elevi){
			el.classList.add("selectat");
		}

		var conf = confirm("Sterge?")
		if(conf){
			for(el of elevi)
				el.remove();

		}}
	document.getElementById("sorteaza_nume").onclick = function(){
		var tabel = document.getElementById("tab");
		var tbody = tabel.getElementsByTagName("tbody")[0];
		v_tr = Array.prototype.slice.call(tbody.children); //  bagam colectia in array ca sa sortam
		v_tr.sort(function(a,b){
			return (a.children[1].innerHTML + a.children[0].innerHTML).localeCompare(b.children[1].innerHTML +b.children[0].innerHTML)
		})

		for(tr of v_tr)
			tbody.appendChild(tr);
	}

	
	document.getElementById("sorteaza_medie").onclick = function(){
		var tabel = document.getElementById("tab");
		var tbody = tabel.getElementsByTagName("tbody")[0];
		v_tr = Array.prototype.slice.call(tbody.children); //  bagam colectia in array ca sa sortam
		v_tr.sort(function(a,b){var note_a = a.children[3].innerHTML.split(",");
								var note_b = b.children[3].innerHTML.split(",");

								sum_a = note_a.reduce(function(total,num){
									return parseInt(total) + parseInt(num);});
								sum_b = note_b.reduce(function(total,num){
									return parseInt(total) + parseInt(num);});
									
								medie_a = sum_a / note_a.length;
								medie_b = sum_b / note_b.length;

								return medie_a - medie_b;				
								})

		for(tr of v_tr)
			tbody.appendChild(tr);
	}
// selecteaza elevii
/*
	this.document.getElementById("select_elevi").onclick = function(){
		var tabel = document.getElementById("tab");
		var tbody = tabel.getElementsByTagName("tbody")[0];

	}*/
//
	document.getElementById("gaseste_elev").onclick = function(){
		var tabel = document.getElementById("tab");
		var tbody = tabel.getElementsByTagName("tbody")[0];
		v_tr = Array.prototype.slice.call(tbody.children);

		var prenume = prompt("prenume =");
		indice = v_tr.findIndex(function(a){
			return	a.children[0].innerHTML == prenume;
		})

		if(indice != -1)
			alert(indice+1);
		else
			alert("NU");
	}

	document.getElementById("inverseaza").onclick = function(){
		var tabel = document.getElementById("tab");
		var tbody = tabel.getElementsByTagName("tbody")[0];
		v_tr = Array.prototype.slice.call(tbody.children);

		for(let i = v_tr.length-1; i>=0;i--)
		{
			tbody.appendChild(v_tr[i]);
		}
	}

	document.getElementById("goleste_tabel").onclick = function(){
		var tabel = document.getElementById("tab");
		var tbody = tabel.getElementsByTagName("tbody")[0];
		tbody.innerHTML = "";


	}
}

window.onkeypress = function(e){
	var tabel = document.getElementById("tab");
	var tbody = tabel.getElementsByTagName("tbody")[0];
	var cod = e.charCode ? e.charCode : e.keyCode; // citeste evenimentul si pune valoare in cod, tip ASCII
	var tasta = String.fromCharCode(cod).toUpperCase(); // conversie din ASCII in string si il face uppercase
	var ind = grupe.findIndex(function(a){return a==tasta});
	if(ind==-1)return;
			
	// "a".charCodeAt(0) conversie din sir in ASCII

	v_tr = tbody.querySelectorAll(".selectat");
	for(rand of v_tr)
	{
		for(gr of grupe)
			rand.classList.remove(gr);
		rand.classList.add(tasta);
		rand.children[2].innerHTML = tasta;
	}
}
