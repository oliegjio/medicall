const db = require('../database/db')
const bcrypt = require('bcrypt')

class DoctorModel {

  constructor(doctor) {
    if (!DoctorModel.validate(doctor)) {
      console.error('Not enought arguments for DoctorModel')
      return
    }
    Object.assign(this, doctor)
  }

  static validate(obj) {
    if (!obj.username   || !obj.email          ||
        !obj.password   || !obj.fullName       ||
        !obj.speciality || !obj.socialNetworks ||
        !obj.phoneNumber) return false
    else
        return true
  }

  static getById(id) {
    return new Promise((resolve, reject) => {
      db.get(
        `SELECT * FROM doctors WHERE id = ?`,
        [id],
        (error, doctor) => {
          if (error)  reject(error)
          if (!doctor) reject('No such doctor!')
          resolve(doctor)
        })
    })
  }

  static getByUsername(username) {
    return new Promise((resolve, reject) => {
      db.get(
        `SELECT * FROM doctors WHERE username = ?`,
        [username],
        (error, doctor) => {
          if (error) reject(error)
          if (!doctor) reject('No such doctor!')
          resolve(doctor)
        })
    })
  }

  static commit(doctor) {
    return new Promise((resolve, reject) => {
      db.run(`
        INSERT INTO doctors
        (
          username, email, password,
          fullName, speciality, phoneNumber,
          socialNetworks
        )
        VALUES (?, ?, ?, ?, ?, ?, ?)`, [
        doctor.username, doctor.email, doctor.password,
        doctor.fullName, doctor.speciality, doctor.phoneNumber,
        doctor.socialNetworks],
        (error) => {
          if (error) reject(error)
          resolve(this)
        })
    })
  }

  static addPatient(patientId, doctorId) {
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

  static getPatients(doctorId) {
    return new Promise((resolve, reject) => {
      db.all(
        `SELECT * FROM patients
        LEFT JOIN patients_doctors
        ON patients_doctors.patient_id = patients.id
        WHERE patients_doctors.doctor_id = ?`,
        [doctorId],
        (error, patients) => {
          if (error) reject(error)
          if (patients.length == 0)
            reject('This doctor does not have any patients!')
          resolve(patients)
        })
    })
  }
}

module.exports = DoctorModel
