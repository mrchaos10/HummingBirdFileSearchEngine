var express = require('express'); 
var fs = require('fs');
var app = express();
var path = require('path');
var bodyParser = require('body-parser');
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

var mongoose = require("mongoose");
mongoose.Promise = global.Promise;
mongoose.connect("mongodb://localhost:27017/temp");
var nameSchema = new mongoose.Schema({
     Content:String,    
});

app.get('/test', function(req, res) {
    res.sendFile(path.join(__dirname,'search.html'));
});

app.get('/result', function(req, res) {
    res.sendFile(path.join(__dirname,'result.html'));
});

var User = mongoose.model("tempstorage", nameSchema); 

app.post("/addname", (req, res) => {
    var myData = new User(req.body);
    myData.save()
        .then(item => {
            res.send("Details saved to the server");
        })
        .catch(err => {
            res.status(400).send("Unable to save to database");
        });
});


var port = process.env.PORT || 8080;
var server = app.listen(port);
console.log('Express app started on port ' + port);


