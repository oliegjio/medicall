var db = require('./db')

db.serialize(() => {
  db.run(`drop table if exists 'users'`)
  db.run(`create table if not exists 'users' ('id' integer primary key, 'username' text, 'password' text)`)

  db.run(`insert into 'users' values (1, 'test1', 'asdf')`)
  db.run(`insert into 'users' values (2, 'test2', 'asdf')`)
})
