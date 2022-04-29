const express = require('express');
const bodyParser = require('body-parser');
const addon = require('../build/Release/addon.node');
var cors = require('cors')

const config = require('../config.json')["server"];
const host = config.host;
const port = config.port;
const uri = config.uri;

const app = express();

app.use(cors());

app.all('/', (req, res) => {
    res.setHeader('Access-Control-Allow-Origin', '*')
    next();
});

app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());

app.get('/', (req, res) => {
    res.send("Just a quick example.");
});

app.post(`${uri}/encrypt/affine`, (req, res) => {

    var text = req.body.text || "";
    var a = req.body.a || 1;
    var b = req.body.b || 0;

    res.send(addon.cipherAffineEncrpyt(text, a, b));

});

app.post(`${uri}/decrypt/affine`, (req, res) => {

    var text = req.body.text || "";
    var a = req.body.a || 1;
    var b = req.body.b || 0;

    res.send(addon.cipherAffineDecrpyt(text, a, b));

});

app.post(`${uri}/encrypt/caesar`, (req, res) => {

    var text = req.body.text || "";
    var shift = req.body.shift || 0;

    res.send("hello" + JSON.stringify(req.body) + addon.cipherCaesarEncrpyt(text, shift));

});

app.post(`${uri}/decrypt/caesar`, (req, res) => {

    var text = req.body.text || "";
    var shift = req.body.shift || 0;

    res.send(addon.cipherCaesarDecrpyt(text, shift));

});

app.post(`${uri}/encrypt/subsitution`, (req, res) => {

    var text = req.body.text || "";
    var keys = req.body.keys || "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    res.send(addon.cipherSubsitutionEncrpyt(text, keys));

});

app.post(`${uri}/decrypt/subsitution`, (req, res) => {

    var text = req.body.text || "";
    var keys = req.body.keys || "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    res.send(addon.cipherSubsitutionDecrpyt(text, keys));

});

app.post(`${uri}/encrypt/vigenere`, (req, res) => {

    var text = req.body.text || "";
    var keyword = req.body.keyword || "";

    res.send(addon.cipherVigenereEncrpyt(text, keyword));

});

app.post(`${uri}/decrypt/vigenere`, (req, res) => {

    var text = req.body.text || "";
    var keyword = req.body.keyword || "";

    res.send(addon.cipherVigenereDecrpyt(text, keyword));

});

app.listen(port, host, () => console.log(`Started server ${host} on port ${port}`));
