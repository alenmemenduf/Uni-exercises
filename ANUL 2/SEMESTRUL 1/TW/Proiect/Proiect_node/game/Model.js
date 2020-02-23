class Entity{
    constructor (x,y,img)
    {
    this.x = x;
    this.y = y;
    this.image = new Image();
    if(img)
        this.image.src = img;
    this.dead = false;
    this.scale = 1;
    this.FACE_LEFT = false;
    this.FACE_Right = true;
    }
    checkMarginsOverlap(obiect)
    {
        if(this.x <= obiect.x + obiect.image.width * obiect.scale &&
            this.x + this.image.width * this.scale >= obiect.x &&
            this.y <= obiect.y + obiect.image.height * obiect.scale &&
            this.y + this.image.height * this.scale >= obiect.y)
                return true;
        return false;
    }
    destroy()
    {  
        this.dead = true;
    }
    drawMe()
    {
        document.getElementById("gc").getContext("2d").drawImage(this.image,0,0,this.image.width,this.image.height,this.x,this.y,this.image.width*this.scale,this.image.height*this.scale);
    }
}

class Player extends Entity{
    constructor (x,y)
    {
    super(x,y);
    this.gravity = 4;
    this.speed = 3.5;
    this.falling = true;
    this.jumping = false;
    this.velocity = {x:0,y:0};
    this.bullets = [];
    this.StaPeObstacol = false;
    }
    LeftCollision(obiect)
    {
        if(this.checkMarginsOverlap(obiect) && obiect.dead != true)
        {
            if(this.x >= obiect.x + obiect.image.width * obiect.scale + this.velocity.x - 2)
            {
                
                    return true;
            }
        }
        return false;
    }
    RightCollision(obiect)
    {
        if(this.checkMarginsOverlap(obiect) && obiect.dead != true)
        {
            if(this.x + this.image.width * this.scale <= obiect.x + this.velocity.x + 2)
               {
                    return true;
               }
        }
        return false;
    }
    TopCollision(obiect) // TOP OF PLAYER !!!!!!!
    {
        if(this.checkMarginsOverlap(obiect)&& obiect.dead != true)
        {
            if(this.y > obiect.y + obiect.image.height * obiect.scale + this.velocity.y+2)
            {
                console.log("ph")
                return true;
            }
        }
        return false;
    }
    BottomCollision(obiect) // BOTTOM OF PLAYER !!!!!!!!
    {
        if(this.checkMarginsOverlap(obiect) && obiect.dead != true){
            if(this.y + this.image.height * this.scale < obiect.y + this.velocity.y+2)
            {
                return true;
            }
        }   
        return false;
    }
    Animate()
    {  
        
        if(this.jumping || this.falling)
        {
            this.image.src = "game/imagini/player/jump.gif";

        }
        else{
            this.image.src = "game/imagini/player/stand.png";
        }
    }
    destroy()
    {  
        this.dead = true;
    }
    impusca()
    {
        if(this.FACE_RIGHT)
            this.bullets.push(new Bullet(this.x + this.image.width * this.scale,
                                         this.y + this.image.height * this.scale/2,
                                         this));
        else
            this.bullets.push(new Bullet(this.x,
                                         this.y + this.image.height * this.scale/2,
                                         this))

    }
    drawMe()
    {
        var ctx = document.getElementById("gc").getContext("2d");

        if(this.FACE_LEFT){
            ctx.scale(-1, 1);                      // flip hor.
            ctx.drawImage(this.image,0,0,
                        this.image.width,this.image.height,
                        -this.x - (this.scale)*this.image.width, this.y,
                        this.image.width * this.scale, this.image.height * this.scale); // aici se da flip la context, se deseneaza imagine 
            ctx.scale(-1, 1);                                                                          // in forma ei originala si se da flip inapoi, desenandu-se "pe dos" imaginea
        }

        else{
            ctx.drawImage(this.image, 0, 0, 
                        this.image.width ,this.image.height,
                        this.x, this.y,
                        this.image.width * this.scale,  this.image.height * this.scale); 
        }
    }
    Update(){
        
    }
}

class Crosshair {
    constructor() {
        this.image = new Image();
        this.image.src = "game/imagini/crosshair161.png";
        this.scale = 1;
    }
    drawMe(){
        document.getElementById("gc").getContext("2d").drawImage(this.image,0,0,
            this.image.width, this.image.height,
            mouseX - this.image.width * this.scale / 2,    mouseY - this.image.height * this.scale / 2,
            this.image.width * this.scale,    this.image.height * this.scale);
    }
}

class Bullet{ // din dreapta player-ului la mijloc, spawnez un glont. glontul initial e la x,y catre x1,y1, il rotesc cu sinus //ctx.fillRect(x, y, w,h);
    constructor(x,y,cineTrage){
        this.x = x;
        this.y = y;
        this.color = "#7FFFD4";
        this.cineTrage = cineTrage;
        this.speed = 40;
        this.size = 0.8 ;
        this.dead = false;
        this.angle = (Math.atan2(mouseY - this.y - 20,mouseX - this.x + 2)/Math.PI*180);
        this.velocity = {
            x: Math.cos(this.angle/180*Math.PI)*this.speed,
            y: Math.sin(this.angle/180*Math.PI)*this.speed
        }
        sunete.push(new Sunet("game/sunete/piu.m4a"));

        }
    omoara(){
        for(x of AllPlayers)
            if(this.checkMarginsOverlap(x) &&
               (this.cineTrage instanceof(Player) && x instanceof(Enemy) ||
                this.cineTrage instanceof(Enemy) && x instanceof(Player)) &&
                this.dead == false &&
                x.dead == false)
                {
                    if(this.cineTrage instanceof(Player))
                    score+=20;
                    x.destroy();
                    this.destroy();
                }
        for(let i=1;i < obstacole.length;i++)
            if(this.checkMarginsOverlap(obstacole[i]))
            {
                this.destroy();
            }
    }
    destroy()
    {  
        this.dead = true;
    }
    Update()
    {   
        this.color = document.getElementById("select").options[document.getElementById("select").selectedIndex].value;
        if(this.dead == false)
        {
            this.omoara();
            this.x = this.x + this.velocity.x;
            this.y = this.y + this.velocity.y;
        }
    }
    checkMarginsOverlap(obiect)
    {
        if(this.x + this.velocity.x <= obiect.x + obiect.image.width * obiect.scale &&
            this.x + this.velocity.x >= obiect.x &&
            this.y + this.velocity.y <= obiect.y + obiect.image.height * obiect.scale &&
            this.y + this.velocity.y >= obiect.y)
            {
                return true;}
        return false;
    }
}


class Sunet{
    constructor(src){  
        this.sound = document.createElement("audio");
        this.sound.src = src;
        this.sound.muted = false;
        this.sound.setAttribute("preload", "auto");
        this.sound.setAttribute("controls", "none");
        this.sound.style.display = "none";  
        this.sound.volume = volume;
        this.play = function(){
            this.sound.play();
        }
        this.stop = function(){
            this.sound.pause();
        }
        this.Update = function()
        {
            if(this.sound.muted == true)
                this.sound.volume = 0;
            else
            {
                if(sunete[0] == this)
                    this.sound.volume = volume;
                else
                    this.sound.volume = volume;
            }
        }
    }
}

class Obstacol extends Entity{
    constructor(x,y,img){
        super(x,y,img);
    }
    SetPosition(x,y){
        this.x = x;
        this.y = y;
    }
}


Entity.prototype.setScale = function(scale)
{
    this.scale = scale;
};

class Enemy extends Player{
    constructor(x,y)
    {
        super(x,y);
    }
    Animate()
    {
        if(this.jumping || this.falling)
        {
            this.image.src = "game/imagini/enemy/jump.gif";

        }
        else{
            this.image.src = "game/imagini/enemy/stand.png";
        }
    }
    Update(){
        if(this.falling)
        {
            this.velocity.y += this.gravity;
            //if(!this.BottomCollision(obiect))
            this.y += this.velocity.y;
            if(this.velocity.y < 3 * this.gravity)
                this.velocity.y = 3 * this.gravity
        }
    }
}

        ///// SPRITES AND CONTROLLER /////
var volume;
var Jucator;
var Inamic;
var AllPlayers = [];

var crosshair = new Crosshair;
var bg = new Obstacol(0,0,"game/imagini/bg.png");
var podea = new Obstacol(0,0,"game/imagini/podea.png");
var controller = new Object();
sunete = [];
        ///// PHYSICS //////

var max_vx = 5;
var max_vy = 10;
var friction = 0.85;
        ///// MOUSE INPUT /////

var mouseX;
var mouseY;
        ////// KEYBOARD INPUT ///////

var A_KEY = 65;
var S_KEY = 83;
var D_KEY = 68;
var W_KEY = 87;


////////////////////////////////////
/////// KEYBOARD & MOUSE INPUT ////
//////////////////////////////////


document.onkeydown = function(e){
    toggleKey(e.keyCode, true);
}

document.onkeyup = function(e){
    toggleKey(e.keyCode, false);
}

function toggleKey(keyCode, isPressed){
    if(keyCode === A_KEY)
        controller.left = isPressed;
    if(keyCode === S_KEY)
        controller.down = isPressed;
    if(keyCode === D_KEY)
        controller.right = isPressed;
    if(keyCode === W_KEY)
        controller.up = isPressed;
    
}

//////////////////////////////////
////////// PLAYER MOVEMENT //////
///////////////////////////////



function handleControls(){
/**
*   KEYBOARD
*/
    if(Jucator.falling)
        {
                    Jucator.velocity.y += Jucator.gravity;
                if(Jucator.velocity.y < Jucator.gravity * 3)
                    Jucator.velocity.y = Jucator.gravity * 3;
        }
    if(controller.up && Jucator.falling == false){ // cat timp apesi W si player-ul nu cade
            jumpHeight += 1;
            if(jumpHeight < max_vy) // cat timp jumpHeight e mai mic decat max_vy, player-ul inca sare
            {
                Jucator.falling = false;
                Jucator.jumping = true;
                Jucator.velocity.y -= 1.3*Jucator.gravity;
            }
            else    // dupa ce jumpHeight trece de max_vy, player-ul cade si jumpHeight incepe de la 0
            {   
                jumpHeight = 0;
                Jucator.falling = true;
                Jucator.jumping = false;
            }
    }
    else if(!controller.up && Jucator.jumping == true){   // daca iei degetul de pe W in timp ce sare
        jumpHeight = 0;
        Jucator.falling = true;
        Jucator.jumping = false;
    }
    if(controller.left){
                Jucator.velocity.x -= Jucator.speed;
                if(Jucator.velocity.x < -Jucator.speed * max_vx)
                    Jucator.velocity.x = -Jucator.speed * max_vx;
    }
    if(controller.right){
                Jucator.velocity.x += Jucator.speed;
                if(Jucator.velocity.x > Jucator.speed * max_vx)
                    Jucator.velocity.x = Jucator.speed * max_vx;
        }
    Jucator.velocity.x *= friction;

    let obstacoleSiPlayeri = [];

    for(let i=1;i<obstacole.length;i++)
        obstacoleSiPlayeri.push(obstacole[i]);
    for(x of AllPlayers)
        obstacoleSiPlayeri.push(x);

    for(obstacol of obstacoleSiPlayeri)
    {
        
        if(Jucator.TopCollision(obstacol) &&
        !Jucator.RightCollision(obstacol) &&
        !Jucator.LeftCollision(obstacol))
        {   
            Jucator.y = obstacol.y + obstacol.image.height * obstacol.scale;
            Jucator.velocity.y = 0;
            Jucator.jumping = false;
            Jucator.falling = true;
            
        }
        else 
        if(Jucator.BottomCollision(obstacol) &&
            !Jucator.RightCollision(obstacol) &&
            !Jucator.LeftCollision(obstacol))
            {
                    if(Jucator.falling){
                    sunete.push(new Sunet("game/sunete/ftunk.m4a"));
                }
                Jucator.StaPeObstacol = true;
                Jucator.velocity.y = 0;
                Jucator.y = obstacol.y - Jucator.image.height * Jucator.scale;
                Jucator.jumping = false;
                Jucator.falling = false;
            }
        if(Jucator.LeftCollision(obstacol))
        {
            if(Jucator.velocity.x < 0)
            {
                Jucator.x = obstacol.x + obstacol.image.width * obstacol.scale;
                Jucator.velocity.x = 0;
            }
        }
        else if(Jucator.RightCollision(obstacol))
        {
            if(Jucator.velocity.x > 0)
            {
                Jucator.x = obstacol.x - Jucator.image.width * Jucator.scale;
                Jucator.velocity.x = 0;
            }
        }
        
        
    }
    if(Jucator.StaPeObstacol == false && Jucator.jumping == false)
    {
            Jucator.falling = true;
    }
    Jucator.StaPeObstacol = false;
    Jucator.y += Jucator.velocity.y;
    if(!Jucator.LeftCollision(obstacol) && !Jucator.RightCollision(obstacol))
        Jucator.x += Jucator.velocity.x;
        
/**
*   MOUSE
*/
    if(mouseX < Jucator.x + Jucator.image.width * Jucator.scale / 2)
    {
        Jucator.FACE_LEFT = true;
        Jucator.FACE_RIGHT = false;
    }
    else
    {
        Jucator.FACE_LEFT = false;
        Jucator.FACE_RIGHT = true;
    }
    
}


////////////////////////////////////
////// RECURSIVE DRAW FUNCTION ////
//////////////////////////////////


function draw(){ 
    ctx.drawImage(bg.image,0,0,bg.image.width,bg.image.height,0,0,canvas.width,canvas.height);
    
    
    for(let i = 1; i < obstacole.length; i++)
        obstacole[i].drawMe();
    for(let i = 0; i < AllPlayers.length; i++)
        if(AllPlayers[i].dead == false)
            AllPlayers[i].drawMe();

    ///////////    DIRECTIA IN CARE SE UITA JUCATORUL   /////////
    for(cineTrage of AllPlayers)
        for(bullet of cineTrage.bullets)
            {
                if(bullet.dead == false)
                {
                    ctx.beginPath();
                    ctx.lineWidth = 2;
                    ctx.strokeStyle = bullet.color;
                    ctx.moveTo(bullet.x,bullet.y);
                    ctx.lineTo(bullet.x + bullet.velocity.x * bullet.size,bullet.y + bullet.velocity.y * bullet.size);
                    ctx.stroke();
                    ctx.closePath();
                }
            }


    if(Jucator.dead == false){

    }

    if(mouseX && mouseY){
        crosshair.drawMe();
    }
}


function loop()
{
    sunete[0].sound.muted = document.getElementById("radio1").checked == true ? true : false;
    sunete[0].Update();
    document.getElementById("value_range").onchange = () => {
        volume = parseInt(document.getElementById("value_range").value)/100 * 0.05;
        for(sunet of sunete)
        {
            if(sunet)
            {
                if(sunet != sunete[0])
                    sunet.sound.volume = volume;
                else
                {
                    sunet.sound.volume = volume/4;
                }
            }
        }
    }
    
    if(game_won)
    {
            let i = scoruri.length;
            scoruri.push({Nr: i+1,nume: name, scor: score, timp: Math.ceil(secunde)});
            localStorage.scoruri = JSON.stringify(scoruri);
    }
    else
    if(game_won == false && times_up == false && Jucator.dead == false)
    {

    if(score>=20)
        game_won = true;
    if(Jucator.dead == false){
    

    for (let i = sunete.length-1; i>=0; i--)
    {
        if(sunete[i]!=null && sunete[i].played != true){
            sunete[i].played = true;
            sunete[i].play();
        }
        else
        if(sunete[i]!=null && sunete[i].ended)
            sunete[i]= null;
    }
    
    if(Jucator.x <= 0)
        Jucator.x = 0;
    if(Jucator.x >= canvas.width - Jucator.image.width * Jucator.scale)
    {
        Jucator.x = canvas.width - Jucator.image.width * Jucator.scale;
    }

    if(Jucator.y <= -10)
    {
        Jucator.y = -10;
    }


        handleControls(); // functie care ia input-ul si schimba pozitiile player-ului
}

for(x of AllPlayers)
{
    if(x.dead == false){
        for(bullet of x.bullets)
        {
            if(bullet != null)
                bullet.Update();
        }
        x.Update();
        x.Animate();

    }
}
    draw();
}
    requestAnimationFrame(loop);

}

//////////////////////////////
//////     START GAME   /////
////////////////////////////


function StartGame(){
    sunete.push(new Sunet("game/sunete/Megalovania.mp3"));
    var timp = setInterval(function(){
        if(secunde < timp_total && !game_won && !Jucator.dead)
            secunde+=0.1;
        else
        {
            times_up = true;
            clearInterval(timp);
        }
    },100);

    canvas = document.getElementById("gc");
    ctx = canvas.getContext("2d");
    ctx.imageSmoothingEnabled = false;
    podea.setScale(2);
    podea.SetPosition(0,canvas.height - podea.image.height * podea.scale);

    obstacole = [];
    obstacole.push(bg);
    obstacole.push(podea);
    obstacole.push(new Obstacol(400,200,"game/imagini/platforma02.png"));
    obstacole.push(new Obstacol(150,300,"game/imagini/platforma01.png"));
    obstacole.push(new Obstacol(350,400,"game/imagini/platforma01.png"));
    obstacole.push(new Obstacol(550,400,"game/imagini/platforma01.png"));
    obstacole.push(new Obstacol(750,300,"game/imagini/platforma01.png"));
    
    Jucator = new Player(300,0);
    Inamic = new Enemy(700,200);
    
    AllPlayers.push(Jucator);
    AllPlayers.push(Inamic);

    Jucator.setScale(6);
    Inamic.setScale(6);
    
    for(let i=2;i < obstacole.length;i++)
        obstacole[i].setScale(2);

    jumpHeight = 0;

    canvas.onmousemove = function(e){
        mouseX = e.offsetX;
        mouseY = e.offsetY;
    }
    canvas.onclick = function(){
        if(Jucator != null && Jucator.dead == false)
            Jucator.impusca();
    }

    loop();    
}


var secunde = 0;
var timp_total = 100;
var start = true;
var game_won = false;
var times_up = false;
var score = 0;
var scoruri = [];

/*                                    ____
 *      \    /\    /   |  |\  | |\   |    |   \    /\    /
 *       \  /  \  /    |  | \ | | |  |    |    \  /  \  / 
 *        \/    \/     |  |  \| |/   |____|     \/    \/  
 */


    window.onload = function()
    {
        name = document.getElementById("nume").innerHTML;
        var canvas = document.getElementById("gc");
        var button = document.getElementById("start");
        canvas.style.display = "none";

        DIV_setari();

        if(localStorage.scoruri != null)
            scoruri = JSON.parse(localStorage.getItem("scoruri"));
        Highscore(scoruri);
        Sorteaza_Highscore();
        button.onclick = function()
        {
            var p = document.createElement("p");
            p.id = "timp";
            document.getElementById("start").parentNode.insertBefore(p,canvas);
            p.innerHTML = " ";
            i=1;
            canvas.style.display = "block";
            if(start){
                var interv = setInterval(function(){
                    p = document.getElementById("timp");
                    p.innerHTML = " " + i;
                    i++;
                },1000)
                var tim = setTimeout(function(){
                    clearInterval(interv);
                    StartGame();
                    setTimeout(function(){Startgame();},1000);
                },3000);
            }
            start = false;
        }
        
    }

////////////////////////////////////////////







function creeazaRand(tipCelula,vector){
    const tr=document.createElement("tr");
    for(x of vector)
    {
        let celula = document.createElement(tipCelula);
        celula.innerHTML = x;
        tr.appendChild(celula);
    }
    return tr;
}
    
function Highscore(scoruri){
    if(!scoruri || scoruri.length == 0) return;

    const div = document.getElementById("tabel_Highscore");
    const tabel = document.createElement("table");  tabel.id = "table";
    const thead = document.createElement("thead");  thead.id = "thead";
    const tbody = document.createElement("tbody");  tbody.id = "tbody";
    let rand = creeazaRand("th",Object.keys(scoruri[0]));
    
    div.appendChild(tabel);
    tabel.appendChild(thead);
    tabel.appendChild(tbody);
    thead.appendChild(rand);
    
    for(scor of scoruri)
    {
        rand = creeazaRand("td",Object.values(scor));
        tbody.appendChild(rand);
    }
    while(tbody.childNodes.length > 10)
    {
        Sorteaza_Highscore();
        tbody.removeChild(tbody.childNodes[tbody.childNodes.length-1]);
    }
}

function Sterge_Highscore()
{
    localStorage.removeItem("scoruri");
}

function Sorteaza_Highscore(){
    var tabel = document.getElementById("table");
    if(tabel){
    var tbody = tabel.getElementsByTagName("tbody")[0];
    v_tr = Array.prototype.slice.call(tbody.children); //  bagam colectia in array ca sa sortam
    v_tr.sort(function(a,b){
        if(b.children[2].innerHTML - a.children[2].innerHTML == 0)
            return (a.children[3].innerHTML - b.children[3].innerHTML)
        return (b.children[2].innerHTML - a.children[2].innerHTML);
    })

    for(tr of v_tr)
        tbody.appendChild(tr);
}
}

function DIV_setari(){
    var div = document.getElementById("setari");

    // input range
	div.innerHTML += '<pre> volum: </pre>';
	var i_range = document.createElement("input");
	i_range.type = "range";
	i_range.id = "value_range";
	i_range.min = "0";
	i_range.max = "100";
	i_range.step = "5";
    i_range.defaultValue = "50";
    i_range.style.display = "inline-block";
    var text_min = document.createTextNode("");
    text_min.nodeValue ="0";
    var text_max = document.createTextNode("");
    text_max.nodeValue = "100";
	div.appendChild(text_min);
	div.appendChild(i_range);
	div.appendChild(text_max);
    div.innerHTML += '<br/>';
    volume = parseInt(i_range.value)/100 * 0.05;

    // input checkbox
	div.innerHTML += "<pre>text checkbox </pre>";
	for(var i = 0; i < 3; i++){
        var i_checkbox = document.createElement("input");
        i_checkbox.style.display = "inline-block";
		i_checkbox.type = "checkbox";
		i_checkbox.id = "checkbox" + i;
        let newlabel = document.createElement("label");
        newlabel.style.display = "inline-block";
        newlabel.setAttribute("for", "checkbox" + i);
        if(i == 0)
		    newlabel.innerHTML = "dificultate marita";
        else
        if(i==1)
            newlabel.innerHTML = "fara timp";
        else
        if(i==2)
            newlabel.innerHTML = "nu salva progresul"
		div.appendChild(i_checkbox);
		div.appendChild(newlabel);
		div.innerHTML += '<br/>';
	}
    div.innerHTML += '<br/>';
    
    //input radio
	div.innerHTML += "<pre> mute music? </pre>";
	for(var i = 0; i < 2; i++){
		var i_radio = document.createElement("input");
        i_radio.style.display = "inline-block";
		i_radio.type = "radio";
		i_radio.name = "radio";
        i_radio.id = "radio" + i;
		let newlabel = document.createElement("label");
        newlabel.style.display = "inline-block";
        newlabel.setAttribute("for", "radio" + i);
        if(i==0)
            newlabel.innerHTML+="no";
        else
        if(i==1)
            newlabel.innerHTML+="yes";
		div.appendChild(i_radio);
		div.appendChild(newlabel);
		div.innerHTML += '<br/>';
	}
    div.innerHTML += '<br/>';
    document.getElementById("radio0").setAttribute("checked","true");
    
	div.innerHTML += "<pre> selecteaza culoarea laserului: </pre>";
	var sel = document.createElement("select");
	sel.id = "select";
    div.appendChild(sel);
    culori = ["red","blue","green"];
	for(el of culori){
		var opt = document.createElement("option");
        opt.text = el;
        if(opt.text == "red")
            opt.value = "#ff3729";
        else
        if(opt.text = "blue")
            opt.value = "#4cd5ff"
        else
        if(opt.text = "green")
            opt.value = "#7FFFD4"
		sel.appendChild(opt);
	}
	div.innerHTML += '<br/><br/>';
	
	// textarea
	div.innerHTML += "<pre>text area:</pre>";
	var newTextArea = document.createElement("textarea");
	newTextArea.name = "new_text_area";
	newTextArea.length = "5000";
	newTextArea.id = "text_area";
	newTextArea.cols = "30";
	newTextArea.rows = "5";
	div.appendChild(newTextArea);
	div.innerHTML += '</br></br>';
    
    newTextArea = document.getElementById("text_area");
    var i = 1;
    newTextArea.onkeyup = function(e)
    {
        if(e.keyCode == 13)
        {   
            var label = document.createElement("pre");
            label.innerHTML = "COMENTARIUL:" + i;
            div.appendChild(label);
            var p = document.createElement("pre");
            p.innerHTML = newTextArea.value;
            div.appendChild(p);
            newTextArea.value = "";
            i++;
        }
    }


}