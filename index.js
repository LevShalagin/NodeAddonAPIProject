var addon = require('bindings')('myAddon.node');


//////////////////////////////////////////////////
console.log("------------Test------------");
console.log("JS: " + addon.get_date("01/01/2025", "Happy new year!"));
console.log("------------Test------------");
//////////////////////////////////////////////////

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