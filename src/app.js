const express = require('express');
const bodyParser = require('body-parser');
const addon = require('../build/Release/addon.node');

const app = express();
const PORT = 3001;

app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());

app.post('/encrypt/affine', (req, res) => {

    var text = req.body.text || "";
    var a = req.body.a || 1;
    var b = req.body.b || 0;

    res.send(addon.cipherAffineEncrpyt(text, a, b));

});

app.post('/decrypt/affine', (req, res) => {

    var text = req.body.text || "";
    var a = req.body.a || 1;
    var b = req.body.b || 0;

    res.send(addon.cipherAffineDecrpyt(text, a, b));

});

app.post('/encrypt/caesar', (req, res) => {

    var text = req.body.text || "";
    var shift = req.body.shift || 0;
    res.send("hello");
    //res.send(addon.cipherCaesarEncrpyt(text, shift));

});

app.post('/decrypt/caesar', (req, res) => {

    var text = req.body.text || "";
    var shift = req.body.shift || 0;

    res.send(addon.cipherCaesarDecrpyt(text, shift));

});

app.post('/encrypt/subsitution', (req, res) => {

    var text = req.body.text || "";
    var keys = req.body.keys || "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    res.send(addon.cipherSubsitutionEncrpyt(text, keys));

});

app.post('/decrypt/subsitution', (req, res) => {

    var text = req.body.text || "";
    var keys = req.body.keys || "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    res.send(addon.cipherSubsitutionDecrpyt(text, keys));

});

app.post('/encrypt/vigenere', (req, res) => {

    var text = req.body.text || "";
    var keyword = req.body.keyword || "";

    res.send(addon.cipherVigenereEncrpyt(text, keyword));

});

app.post('/decrypt/vigenere', (req, res) => {

    var text = req.body.text || "";
    var keyword = req.body.keyword || "";

    res.send(addon.cipherVigenereDecrpyt(text, keyword));

});

app.listen(PORT, () => console.log(`Started server at http://localhost:8080!`));
