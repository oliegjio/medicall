const jwt = require('jwt-simple')
const config = require('../app/config')
const DoctorModel = require('../models/DoctorModel')
const bcrypt = require('bcrypt')

var init = (app) => {
  app.post('/login-doctor', function(request, response) {

      if (request.body.username && request.body.password) {
          var username = request.body.username
          var password = request.body.password

          var doctor = DoctorModel.getByUsername(username)

          .then((doctor) => {
            bcrypt.compare(password, doctor.password)
            .then((result) => {
              if (!result)
                return response.sendStatus(401)

              if (doctor) {
                  var payload = { id: doctor.id }
                  var token = jwt.encode(payload, config.jwtSecret)
                  response.json({
                      token: token,
                      doctor: doctor
                  })
              } else {
                return response.sendStatus(401)
              }
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
