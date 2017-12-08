const express = require('express')
const path = require('path')
const passport = require('passport')
const passportJwt = require('passport-jwt')
const jwt = require('jsonwebtoken')
const bodyParser = require('body-parser')
const auth = require('./auth')()
const UserModel = require('../models/userModel') 

require('./dbInit')
UserModel.getUser(1).then((user) => {
  console.log(user) 
})

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
require('../routes/tokenRoute').init(app)
require('../routes/userRoute').init(app)

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
