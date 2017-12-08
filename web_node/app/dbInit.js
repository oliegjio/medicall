var db = require('./db')

db.serialize(() => {
  db.run(`drop table if exists 'users'`)
  db.run(`create table if not exists 'users' ('id' integer primary key autoincrement, 'username' text, 'password' text)`)

  db.run(`insert into 'users' ('username', 'password') values ('test1', 'asdf')`)
  db.run(`insert into 'users' ('username', 'password') values ('test2', 'asdf')`)
})
