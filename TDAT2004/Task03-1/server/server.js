const express = require('express');
const app = express();
const bodyParser = require("body-parser");
const {exec} = require("child_process");
const cors = require("cors");
const fs = require("fs");
app.use(bodyParser.json());
app.use(bodyParser.json({type: '*/*'}));
app.use(cors());

app.post('/', (req, res) => {
    console.log("running");
    let code = req.body.input;
    writeAndRun(code, res);
});

function writeAndRun(code, res) {
    let result = [];
    fs.writeFileSync('./codeInput.js', code);

    let script = exec("node codeInput.js", (error, stdout, stderr) => {
        if (error) {
            result.push(error.message.toString());
            return;
        }
        if (stderr) {
            result.push(stderr.toString());
            return;
        }
        result.push(stdout);
        console.log(stdout);
    });
    script.on('close', () => {
        console.log("done");
        res.send(result);
    });
}

app.listen(8080, () => {
    console.log('Server running on port 8080');
});