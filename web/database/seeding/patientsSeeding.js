const PatientModel = require('../../models/PatientModel')
const bcrypt = require('bcrypt')
const db = require('../db')

db.serialize(() => {

  // ####
  // ## =========>
  // ####
  bcrypt.hash('asdf', 10)
  .then((hash) => {
    var patient = new PatientModel({
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
    PatientModel.commit(patient)
    .catch((error) => { console.error(error) })

    PatientModel.addDoctor(1, 1)
    .catch((error) => {
      console.error(error)
    })
  })
  .catch((error) => {
    console.error(error)
  })

  // ####
  // ## =========>
  // ####
  bcrypt.hash('asdf', 10)
  .then((hash) => {
    var patient = new PatientModel({
      username: 'test4',
      password: hash,
      email: 'test4@gmail.com',
      location: 'Somewhere',
      bloodType: 'AB',
      weight: '64',
      height: '1.85',
      gender: 'Мужской',
      birthDate: '19.02.1973',
      fullName: 'John Doe'
    })
    PatientModel.commit(patient)
    .catch((error) => { console.error(error) })

    PatientModel.addDoctor(1, 2)
    .catch((error) => {
      console.error(error)
    })

    PatientModel.getDoctors(1)
    .then((doctors) => {
      doctors.forEach((doctor) => {
        console.log(doctor.username)
      })
    })
    .catch((error) => {
      console.log(error)
    })
  })
  .catch((error) => {
    console.error(error)
  })
})
