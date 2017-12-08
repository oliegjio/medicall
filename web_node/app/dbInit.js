const PatientModel = require('../models/PatientModel')
const db = require('./db')

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

  var patient1 = new PatientModel({
    username: 'test3',
    password: 'asdf',
    email: 'test3@gmail.com',
    location: 'Somewhere',
    bloodType: 'AB',
    weight: '64',
    height: '1.85',
    gender: 'male',
    birthDate: '19.02.1973',
    fullName: 'John Doe'
  })
  patient1.commit()
  .catch((error) => { console.error(error) })

  var patient2 = new PatientModel({
    username: 'test1',
    password: 'asdf',
    email: 'test1@gmail.com',
    location: 'Somewhere',
    bloodType: 'C',
    weight: '54',
    height: '1.35',
    gender: 'female',
    birthDate: '19.02.1983',
    fullName: 'Lara Sheen'
  })
  patient2.commit()
  .catch((error) => { console.error(error) })
})
