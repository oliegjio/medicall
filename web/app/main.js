const express = require('express')
const path = require('path')
const bodyParser = require('body-parser')
const auth = require('./auth')()
const db = require('./db')

require('./dbInit')

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

require('../routes/loginRoute').init(app)
require('../routes/userRoute').init(app)
require('../routes/registerPatientRoute').init(app)

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
