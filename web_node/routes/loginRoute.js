const jwt = require('jwt-simple')
const config = require('../app/config')
const PatientModel = require('../models/PatientModel')

var init = (app) => {
  app.post("/login", function(request, response) {

      if (request.body.username && request.body.password) {
          var username = request.body.username
          var password = request.body.password

          var user = PatientModel.getFromCredentials(username, password)
          .catch((error) => console.error(error))

          .then((user) => {
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

          .catch((error) => { console.error(error) })
      } else {
          response.sendStatus(401)
      }
  })
}

module.exports.init = init
