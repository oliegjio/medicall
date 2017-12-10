const db = require('../database/db')
const bcrypt = require('bcrypt')

class PatientModel {

  constructor(patient) {
    if (!PatientModel.validate(patient)) {
      console.error('Not enought arguments for PatientModel')
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
      db.get(
        `SELECT * FROM patients WHERE id = ?`,
        [id],
        (error, user) => {
          if (error)  reject(error)
          if (!user) reject('No such user!')
          resolve(user)
        })
    })
  }

  static getByUsername(username) {
    return new Promise((resolve, reject) => {
      db.get(
        `SELECT * FROM patients WHERE username = ?`,
        [username],
        (error, user) => {
          if (error) reject(error)
          if (!user) reject('No such user!')
          resolve(user)
        })
    })
  }

  static commit(patient) {
    return new Promise((resolve, reject) => {
      db.run(`
        INSERT INTO patients
        (
          username, email, password,
          fullName, birthDate, location,
          gender, weight, height,
          bloodType
        )
        VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)`, [
        patient.username, patient.email, patient.password,
        patient.fullName, patient.birthDate, patient.location,
        patient.gender, patient.weight, patient.height,
        patient.bloodType],
        (error) => {
          if (error) reject(error)
          resolve(this)
        })
    })
  }

  static addDoctor(doctorId, userId) {
    return new Promise((resolve, reject) => {
      db.run(`
        INSERT INTO patients_doctors
        (doctor_id, patient_id)
        VALUES (?, ?)`,
        [doctorId, userId],
        (error) => {
          if (error) reject(error)
          resolve(this)
        })
    })
  }

  static getDoctors(patientId) {
    return new Promise((resolve, reject) => {
      db.all(
        `SELECT * FROM doctors
        LEFT JOIN patients_doctors
        ON patients_doctors.patient_id = doctors.id
        WHERE patients_doctors.patient_id = ?`,
        [patientId],
        (error, doctors) => {
          if (error) reject(error)
          if (doctors.length == 0)
            reject('This user does not have any doctors!')
          resolve(doctors)
        })
    })
  }
}

module.exports = PatientModel
