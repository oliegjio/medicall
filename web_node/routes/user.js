const users = require('../app/users.js')
const auth = require('../app/auth.js')()

var init = (app) => {
  app.post('/user', auth.authenticate(), (request, response) => {
    response.json("true")
  })
}

module.exports.init = init
