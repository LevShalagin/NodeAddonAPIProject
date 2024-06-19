const addon = require('bindings')('myAddon.node');

////////////////////////////////////////////////////////////////////
console.log("------------Test------------");
console.log("JS: " + addon.get_date("01/01/2025", "Happy new year!"));
console.log("------------Test------------");
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
function addDate() {

    let date = prompt("Введите дату").toString();
    let event = prompt("Введите событие").toString();
    
    let table = document.getElementById("tbody");
    let row = "<tr><td>" + date + "</td><td>" + event + "</td></tr>";
    // get_date(date, event);
    console.log(row);
    console.log(table);

    table.innerHTML += row;
}

function delDate() {
    let ind = prompt("Какое событие удалить?");
    document.getElementById("tbody").deleteRow(ind - 1);
}
////////////////////////////////////////////////////////////////////





const fs = require('fs');
const http = require('http');


const port = 1217;
const server = http.createServer( function (req, res){
    fs.readFile('main.html', (err, data) => {
    if (err) throw err; 
    res.writeHead(200, {'Content-Type': 'text/html'});
    res.write(data); 
    res.end();
    });
});

server.listen(port, function(){ console.log("Сервер запущен по адресу http://localhost:" + port)});