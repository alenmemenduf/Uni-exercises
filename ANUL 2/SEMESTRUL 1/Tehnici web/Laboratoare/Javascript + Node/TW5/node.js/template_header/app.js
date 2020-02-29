var express = require('express');/*include modulul express
memorand in variabila express obiectul asociat modulului(exportat de modul)*/
var app = express();

// pentru folosirea ejs-ului 
app.set('view engine', 'ejs');


// cand se face o cerere get catre pagina de index 
app.get('/', function(req, res) {
	/*afiseaza(render) pagina folosind ejs (deoarece este setat ca view engine) */
    res.render('html/index');
});

// about page 
app.get('/stelute', function(req, res) {
    res.render('html/stelute');
});
app.get('/prajituri', function(req, res) {
    res.render('html/prajituri');
});
app.get('/pisici', function(req,res) {
	res.render('html/pisici');
});
app.use('/css', express.static('css'));
app.use('/imagini', express.static('imagini'));


app.listen(8080);
console.log('8080 is the magic port');