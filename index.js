'use strict'

const addon = require('bindings')('myAddon')

var table = []
table.push(new addon.ToDoPlanner(0, '   date   ', '   event'))
table.push(new addon.ToDoPlanner(1, '12/17/2024', 'Happy birthday!'))
table.push(new addon.ToDoPlanner(2, '12/17/2024', 'СДнёмРождения!'))
table.push(new addon.ToDoPlanner(3, '12/17/2024', 'С Днём Рождения!'))
table.push(new addon.ToDoPlanner(4, '00/00/0000', '123456789012345'))
table.push(new addon.ToDoPlanner(5, '00/00/0000', '1234567890123456'))
// table.push(new addon.ToDoPlanner(6))



for (var i = 0; i < table.length; i++ ) {
    table[i].print()
}