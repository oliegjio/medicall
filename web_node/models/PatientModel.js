const db = require('../app/db')
const bcrypt = require('bcrypt')

class PatientModel {

  constructor(patient) {
    if (!PatientModel.validate(patient)) {
      console.error("Not enought arguments for PatientModel")
      return
    }
    Object.assign(this, patient)
  }

  static validate(obj) {
    if (!obj.username || !obj.email     ||
        !obj.password || !obj.fullName  ||
        !obj.location || !obj.bloodType ||
        !obj.gender   || !obj.birthDate ||
        !obj.height   || !obj.weight)
        return false
    else
        return true
  }

  static getById(id) {
    return new Promise((resolve, reject) => {

      var callback = (error, user) => {
        if (error)  reject(error)
        resolve(user)
      }
      db.get(
        `select * from 'users' where id = ?`,
        [id],
        callback)
    })
  }

  static getFromUsername(username) {
    return new Promise((resolve, reject) => {
      var callback = (error, user) => {
        if (error) reject(error)
        resolve(user)
      }
      db.get(
        `select * from 'users' where username = ?`,
        [username],
        callback)
    })
  }

  commit() {
    return new Promise((resolve, reject) => {
      if (!PatientModel.validate(this))
        reject("Not enought argument to commit PatientModel!")

      var callback = (error) => {
        if (error) reject(error)
        resolve(this)
      }
      db.run(`
          insert into
          'users'
          (
            'username', 'email', 'password',
            'full_name', 'birth_date', 'location',
            'gender', 'weight', 'height',
            'blood_type'
          )
          values (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
        `,[
          this.username, this.email, this.password,
          this.fullName, this.birthDate, this.location,
          this.gender, this.weight, this.height,
          this.bloodType
        ],
        callback)
    })
  }
}

module.exports = PatientModel
