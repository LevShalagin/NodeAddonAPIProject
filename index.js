'use strict'

const rowObj = require('bindings')('rowObject')
const tabEdit = require('bindings')('tabEdit')

var table = []
table.push(new rowObj.ToDoPlanner(0, '   date   ', '   event'))
table.push(new rowObj.ToDoPlanner(1, '12/17/2024', 'Happy birthday!'))
table.push(new rowObj.ToDoPlanner(2, '12/17/2024', 'СДнёмРождения!'))
table.push(new rowObj.ToDoPlanner(3, '12/17/2024', 'С Днём Рождения!'))
table.push(new rowObj.ToDoPlanner(4, '00/00/0000', '123456789012345'))
table.push(new rowObj.ToDoPlanner(5, '00/00/0000', '1234567890123456'))
// table.push(new addon.ToDoPlanner(6))

for (var i = 0; i < table.length; i++ ) {
    table[i].print()
}

tabEdit.tabEdit(table)