var db = require('./db')

db.serialize(() => {
  db.run(`drop table if exists 'users'`)
  db.run(`
    create table if not exists
    'users' 
    (
      'id' integer primary key autoincrement,
      'username' text unique not null,
      'email' text unique not null,
      'password' text not null,
      'full_name' text,
      'birth_date' text,
      'location' text,
      'gender' text,
      'weight' text,
      'height' text,
      'blood_type' text
    )
  `)

  db.run(`
    insert into
    'users'
    (
      'username',
      'password',
      'email'
    )
    values
    (
      'test1',
      'asdf',
      'test1@gmail.com'
    )
  `)
  db.run(`
    insert into
    'users'
    (
      'username',
      'password',
      'email'
    )
    values
    (
      'test2',
      'asdf',
      'test2@yandex.ru'
    )
  `)
})
