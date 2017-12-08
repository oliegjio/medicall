const express = require('express')
const path = require('path')
const passport = require('passport')
const passportJwt = require('passport-jwt')
const jwt = require('jsonwebtoken')
const bodyParser = require('body-parser')
const sqlite = require('sqlite3')
const auth = require('./auth')()

// ####
// ## Init:
// ####

const port = 8000
const app = express()

// ####
// ## Database:
// ####

var db = new sqlite.Database('../db.sqlite')

// ####
// ## Middlewares:
// ####


app.use(auth.initialize())
app.use(bodyParser.urlencoded({ extended: true }))
app.use(bodyParser.json());
app.use(require('../middlewares/crossOrigin').init)

// ####
// ## Routes:
// ####

require('../routes/login').init(app)
require('../routes/token').init(app)
require('../routes/user').init(app)

// ####
// ## Other:
// ####

app.listen(port, (error) => {
  if (error) {
    console.error(error)
  }
  console.log('Listening to localhost:8000')
})

module.exports.app = app
