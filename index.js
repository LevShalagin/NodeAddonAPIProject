'use strict'

const rowObj = require('bindings')('rowObject')
const tabEdit = require('bindings')('tabEdit')

function printTable(table) {
    console.log("---+----------+-------------------")
    for (let i = 0; i<table.length; i++) {
        table[i].print();
        console.log("---+----------+-------------------")
    }
}

function main() {
    console.clear()
    var table = []
    table.push(new rowObj.ToDoPlanner(0, '   date   ', '   event'))

    var index = 1;
    while(true) {

        printTable(table);
        switch (tabEdit.getCmd()) {

            case 'add':
                table.push(new rowObj.ToDoPlanner(index));
                index++;
                break;
        
            case 'del':
                table.pop();
                index--;
                break;

            default:
                break;

        }
        
    console.clear()
    }
}

main()
