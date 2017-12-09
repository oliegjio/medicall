const PatientModel = require('../models/PatientModel')
const db = require('./db')
const bcrypt = require('bcrypt')

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
      'fullName' text not null,
      'birthDate' text not null,
      'location' text not null,
      'gender' text not null,
      'weight' text not null,
      'height' text not null,
      'bloodType' text not null,
      'doctor'
    )
  `)

  bcrypt.hash('asdf', 10)
  .then((hash) => {

    var patient1 = new PatientModel({
      username: 'test3',
      password: hash,
      email: 'test3@gmail.com',
      location: 'Somewhere',
      bloodType: 'AB',
      weight: '64',
      height: '1.85',
      gender: 'Мужской',
      birthDate: '19.02.1973',
      fullName: 'John Doe'
    })
    patient1.commit()
    .catch((error) => { console.error(error) })

    var patient2 = new PatientModel({
      username: 'test1',
      password: hash,
      email: 'test1@gmail.com',
      location: 'Somewhere',
      bloodType: 'C',
      weight: '54',
      height: '1.35',
      gender: 'Женский',
      birthDate: '19.02.1983',
      fullName: 'Lara Sheen'
    })
    patient2.commit()
    .catch((error) => { console.error(error) })

  })
  .catch((error) => {
    console.error(error)
  })
})

db.serialize(() => {
  db.run(`drop table if exists 'recomendations'`)
  db.run(`
    create table if not exists
    'recomendations'
    (
      'id' integer primary key autoincrement,
      'title' text not null,
      'date' text not null,
      'content' text not null,
      'doctor' integer not null,
        foreign key (doctor) references doctors(id)
    )
  `)
})

db.serialize(() => {
  db.run(`drop table if exists 'doctors'`)
  db.run(`
    create table if not exists 'doctors'
    (
      'id' integer primary key autoincrement,
      'fullName' text not null,
      'password' text not null,
      'speciality' text not null,
      'phoneNumber' text not null,
      'email' text not null,
      'socialNetworks' text not null
    )
  `)
})
