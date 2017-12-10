const db = require('../database/db')


db.serialize(() => {
  // ####
  // ## Patients:
  // ####
  db.run(`DROP TABLE IF EXISTS patients`)
  db.run(`
    CREATE TABLE IF NOT EXISTS patients
    (
      id INTEGER PRIMARY KEY AUTOINCREMENT,
      username TEXT UNIQUE NOT NULL,
      email TEXT UNIQUE NOT NULL,
      password TEXT NOT NULL,
      fullName TEXT NOT NULL,
      birthDate TEXT NOT NULL,
      location TEXT NOT NULL,
      gender TEXT NOT NULL,
      weight TEXT NOT NULL,
      height TEXT NOT NULL,
      bloodType TEXT NOT NULL)`)

  // ####
  // ## Doctors:
  // ####
  db.run(`DROP TABLE IF EXISTS 'doctors'`)
  db.run(`
    CREATE TABLE IF NOT EXISTS 'doctors'
    (
      id INTEGER PRIMARY KEY AUTOINCREMENT,
      fullName TEXT NOT NULL,
      password TEXT NOT NULL,
      speciality TEXT NOT NULL,
      phoneNumber TEXT NOT NULL,
      username TEXT UNIQUE NOT NULL,
      email TEXT UNIQUE NOT NULL,
      socialNetworks TEXT NOT NULL)`)

  // ####
  // ## Recomendations:
  // ####
  db.run(`DROP TABLE IF EXISTS recomendations`)
  db.run(`
    CREATE TABLE IF NOT EXISTS recomendations
    (
      id INTEGER PRIMARY KEY AUTOINCREMENT,
      title TEXT NOT NULL,
      date TEXT NOT NULL,
      content TEXT NOT NULL,
      doctor INTEGER NOT NULL,
      FOREIGN KEY (doctor) REFERENCES doctors(id))`)

  // ####
  // ## Patients-Doctors:
  // ####
  db.run(`DROP TABLE IF EXISTS patients_doctors`)
  db.run(`
    CREATE TABLE IF NOT EXISTS patients_doctors
    (
      doctor_id INTEGER,
      patient_id INTEGER,
      PRIMARY KEY (doctor_id, patient_id))`)
})
