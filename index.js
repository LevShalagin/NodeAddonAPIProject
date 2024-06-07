var addon = require('bindings')('myAddon.node');

console.log(addon.get_data("123", "123"));