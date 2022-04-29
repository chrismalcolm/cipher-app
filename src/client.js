const express = require('express');
const path = require('path');

const config = require('../config.json')["client"];
const host = config.host;
const port = config.port;
const uri = config.uri;

const app = express();

app.get(uri, (req, res) => {
    res.sendFile(path.join(__dirname + '/../templates/affine.html'));
});

app.listen(port, host, () => console.log(`Started server ${host} on port ${port}`));
