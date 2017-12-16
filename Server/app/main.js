const express = require('express')
const path = require('path')
const bodyParser = require('body-parser')
const auth = require('./auth')()
const db = require('../database/db')

// ####
// ## Setup:
// ####

const port = 8000
const app = express()

// ####
// ## Middlewares:
// ####

app.use(auth.initialize())
app.use(bodyParser.urlencoded({ extended: true }))
app.use(bodyParser.json());
app.use(require('../middlewares/crossOriginMiddleware').init)

// ####
// ## Routes:
// ####

require('../routes/loginPatientRoute').init(app)
require('../routes/loginDoctorRoute').init(app)
require('../routes/patientRoute').init(app)
require('../routes/doctorRoute').init(app)
require('../routes/registerPatientRoute').init(app)
require('../routes/registerDoctorRoute').init(app)
require('../routes/recomendationsPatientRoute').init(app)

// ####
// ## Other:
// ####

app.listen(port, (error) => {
  if (error) {
    console.error(error)
  }
  console.log('Listening to localhost:8000')
})

process.on('exit', () => {
  db.close()
})

module.exports.app = app
