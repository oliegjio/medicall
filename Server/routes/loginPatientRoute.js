const jwt = require('jwt-simple')
const config = require('../app/config')
const PatientModel = require('../models/PatientModel')
const bcrypt = require('bcrypt')

var init = (app) => {
  app.post('/login-patient', function(request, response) {

      if (request.body.username && request.body.password) {
          var username = request.body.username
          var password = request.body.password

          var patient = PatientModel.getByUsername(username)

          .then((patient) => {
            bcrypt.compare(password, patient.password)
            .then((result) => {
              if (!result)
                return response.sendStatus(401)

              var payload = { id: patient.id }
              var token = jwt.encode(payload, config.jwtSecret)
              response.json({
                  token: token,
                  patient: patient
              })
            })
            .catch((error) => {
              console.error(error)
              return response.sendStatus(400)
            })
          })

          .catch((error) => {
            console.error(error)
            return response.sendStatus(406)
          })
      } else {
          response.sendStatus(401)
      }
  })
}

module.exports.init = init
