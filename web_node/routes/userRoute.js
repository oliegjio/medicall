const users = require('../app/users')
const auth = require('../app/auth')()

var init = (app) => {
  app.post('/user', auth.authenticate(), (request, response) => {
    response.json("true")
  })
}

module.exports.init = init
