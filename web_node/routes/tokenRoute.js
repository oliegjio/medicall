const jwt = require('jwt-simple')
const config = require('../app/config')
const UserModel = require('../models/userModel')

var init = (app) => {
  app.post("/token", function(request, response) {  

      if (request.body.username && request.body.password) {
          var username = request.body.username
          var password = request.body.password

          var user = UserModel.getUserByCredentials(username, password)

          if (user) {

              var payload = { id: user.id }
              var token = jwt.encode(payload, config.jwtSecret)

              response.json({
                  token: token
              })

          } else {
              response.sendStatus(401)
          }

      } else {
          response.sendStatus(401)
      }

  })
}

module.exports.init = init
