const db = require('../database/db')

class RecomendationModel {
  constructor(recomendation) {
    if(!RecomendationModel.validate(recomendation)) {
      console.error("Not enought arguments for RecomendationModel!")
      return
    }
    Object.assign(this, recomendation)
  }

  static validate(obj) {
    if (!obj.date    || !obj.title  ||
        !obj.content || !obj.doctor ||
        !obj.patient) return false
      else
        return true
  }

  static getById(id) {
    return new Promise((resolve, reject) => {
      db.get(
        `SELECT * FROM recomendations WHERE id = ?`,
        [id],
        (error, recomendation) => {
          if (error)  reject(error)
          if (!recomendation) reject('No such recomendation!')
          resolve(recomendation)
        })
    })
  }

  static commit(recomendation) {
    return new Promise((resolve, reject) => {
      db.run(`
        INSERT INTO recomendations
        (title, date, content, doctor, patient)
        VALUES (?, ?, ?, ?, ?)`, [
        recomendation.title, recomendation.date,
        recomendation.content, recomendation.doctor,
        recomendation.patient],
        (error) => {
          if (error) reject(error)
          resolve(this)
        })
    })
  }

  static getByPatient(patientId) {
    return new Promise((resolve, reject) => {
      db.all(
        `SELECT * FROM recomendations WHERE patient = ?`,
        [patientId],
        (error, recomendations) => {
          if (error)  reject(error)
          if (!recomendations) reject('There is no recomendations!')
          resolve(recomendations)
        })
    })
  }
}

module.exports = RecomendationModel
