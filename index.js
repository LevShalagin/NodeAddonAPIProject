'use strict'

const rowObj = require('bindings')('rowObject');
const tabEdit = require('bindings')('tabEdit');

function printTable(table) {
    console.log("---+----------+---------------")
    for (let i = 0; i<table.length; i++) {
        table[i].print();
        console.log("---+----------+---------------")
    }
}


function main() {
    // console.clear();
    let table = [];
    table.push(new rowObj.ToDoPlanner(0, '   date   ', 'event'));

    let INDEX = 1;
    while(true) {

        printTable(table);
        switch (tabEdit.getCmd("Write command(add/del): ")) {

            case 'add':
                table.push(new rowObj.ToDoPlanner(INDEX));
                INDEX++;
                break;
        
            case 'del':
                table.pop()
                INDEX--;
                break;

            case 'test':
                console.log("test");
                console.log(table[1].getDate());
                break;
        }
        // console.clear()
    }
}

main()
