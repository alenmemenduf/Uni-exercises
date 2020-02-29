var express = require('express');
var app = express();
const session = require('express-session');
const fs = require('fs');
const formidable = require('formidable');



function getJson(numeFis){
	let textFis = fs.readFileSync(numeFis);//pun continutul fisierului useri.json in rawdata
	return JSON.parse(textFis);//obtin obiectul asociat json-ului
}

function saveJson(obJson, numeFis){
	let data = JSON.stringify(obJson);//transform in JSON
	fs.writeFileSync(numeFis, data);//scriu JSON-ul in fisier (inlocuind datele vechi)
}

app.set('view engine', 'ejs');
app.use(express.static(__dirname));
app.use('/fisiere_css', express.static('css'));
app.use('/uploads', express.static('uploads'));
app.use(session({
  secret: 'abcdefg',//folosit de express session pentru criptarea id-ului de sesiune
  isLogged: false,
  resave: true,
  saveUninitialized: false
}));

app.get('/', function(req, res) {

	/*afiseaza(render) pagina folosind ejs (deoarece este setat ca view engine) */
    res.render('html/index');//,{user: req.session.username});
	
});

app.get('/tarife',function(req,res){
  res.render('html/tarife', {user: req.session.username});
})
app.get('/Team_Deathmatch',function(req,res){
  res.render('html/Team_Deathmatch', {user: req.session.username});
})
app.get('/Free_for_All',function(req,res){
  res.render('html/Free_for_All', {user: req.session.username});
})
app.get('/Control_Point',function(req,res){
  res.render('html/Control_Point', {user: req.session.username});
})
app.get('/Contact',function(req,res){
  res.render('html/Contact', {user: req.session.username});
})
app.get('/inregistrare',function(req,res){
  res.render('html/inregistrare');
})
app.post('/inregistrare',function(req,res){
	  var form = new formidable.IncomingForm();
    form.parse(req, function(err, fields, files) {
      let rawdata = fs.readFileSync('useri.json');//citesc fisierul si pun tot textul in rawdata
      let jsfis = JSON.parse(rawdata);//parsez textul si obtin obiectul asocita JSON-ului
      jsfis.useri.push({id:jsfis.lastId, username:fields.username, email:fields.email,parola:fields.parola});//adaug elementul nou
      jsfis.lastId++;//incrementez id-ul ca sa nu am doi studenti cu acelasi id
      
      saveJson(jsfis,'useri.json')
      res.redirect('/Mini_Game_login');
      });
    });
app.get('/Mini_Game',function(req,res){
  if(!req.session.isLogged)
    res.redirect('/Mini_Game_login');
  else
    res.render('html/Mini_Game',{user: req.session.username});
})
app.get('/Mini_Game_login',function(req,res){
  res.render('html/Mini_Game_login',{user: req.session.username});
})
app.get('/Mini_Game_logout',function(req,res){
  req.session.destroy();
  res.render('html/Mini_Game_logout');  
})
app.post('/Mini_Game',function(req,res){
  res.redirect('/Mini_Game_logout');
})
app.post('/Mini_Game_login', function(req, res) {
  var form = new formidable.IncomingForm();
	form.parse(req, function(err, fields, files) {
    if(!req.session.isLogged){
      req.session.isLogged = true;
		jsfis=getJson('useri.json');
		//var cifru = crypto.createCipher('aes-128-cbc', 'mypassword');//creez un obiect de tip cifru cu algoritmul aes
		//var encrParola= cifru.update(fields.parola, 'utf8', 'hex');//cifrez parola
    //encrParola+=cifru.final('hex');//inchid cifrarea (altfel as fi putut adauga text nou cu update ca sa fie cifrat
    
		let user=jsfis.useri.find(function(x){//caut un user cu acelasi nume dat in formular si aceeasi cifrare a parolei
      req.session.isLogged = (x.username==fields.username&& x.parola == fields.parola )
			return  req.session.isLogged//encrParola
		});
		if(user){
			//console.log(user);
			//console.log(user.parola);
			//console.log(encrParola);
      req.session.username=user;//setez userul ca proprietate a sesiunii
		}
		
		//console.log(req.session.username);
		/*afiseaza(render) pagina folosind ejs (deoarece este setat ca view engine) */
    res.redirect('/Mini_Game');
    }
    else
    {
      res.redirect('/Mini_Game_logout');
    }
  });


});
app.get('/Capture_The_Flag',function(req,res){
  res.render('html/Capture_The_Flag',{user: req.session.username});
})

app.use(function(req,res){
  res.status(404).render('html/404');
});

app.listen(8080);
console.log("portul e 8080");