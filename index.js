var addon = require('bindings')('myAddon.node');

console.log("-----------test-----------");
console.log("Js:" + addon.get_date("133", "133"));
console.log("-----------test-----------");

function addDate() {
    let date = prompt("Введите дату");
    let event = prompt("Введите событие");
    
    let table = document.getElementById("tbody");

    table.innerHTML += "<tr><td>" + date + "</td><td>" + event + "</td></tr>";
    console.log(table);
};

function delDate() {
    let ind = prompt("Какое событие удалить?");
    document.getElementById("tbody").deleteRow(ind - 1);
}