const sqlite = require('sqlite3')

var db = new sqlite.Database('../db.sqlite')

module.exports = db
