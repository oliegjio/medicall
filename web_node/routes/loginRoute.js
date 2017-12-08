const jwt = require('jwt-simple')
const config = require('../app/config')
const PatientModel = require('../models/PatientModel')
const bcrypt = require('bcrypt')

var init = (app) => {
  app.post("/login", function(request, response) {

      if (request.body.username && request.body.password) {
          var username = request.body.username
          var password = request.body.password

          var user = PatientModel.getFromUsername(username)

          .then((user) => {
            bcrypt.compare(password, user.password)
            .then((result) => {
              if (!result) {
                response.sendStatus(401)
                return
              }

              if (user) {
                  var payload = { id: user.id }
                  var token = jwt.encode(payload, config.jwtSecret)
                  response.json({
                      token: token
                  })
              } else {
                response.sendStatus(401)
              }
            })
            .catch((error) => {
              console.error(error)
              response.sendStatus(400)
            })
          })

          .catch((error) => {
            console.error(error)
            response.sendStatus(406)
          })
      } else {
          response.sendStatus(401)
      }
  })
}

module.exports.init = init
