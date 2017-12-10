const DoctorModel = require('../../models/DoctorModel')
const bcrypt = require('bcrypt')
const db = require('../db')

db.serialize(() => {
  bcrypt.hash('asdf', 10)
  .then((hash) => {
    db.run(`
      insert into 'doctors'
      ('fullName', 'password', 'speciality',
      'phoneNumber', 'username', 'email',
      'socialNetworks')
      values (?, ?, ?, ?, ?, ?, ?)`,
      ['Vasia', hash, 'motherfucker',
      '+666', 'doc1', 'doc1@yaya.ru',
      'vk.com/doc1'],
      (error) => {
        if (error) console.log(error)
      })
  })
  .catch((error) => {
    console.error(error)
  })
})
