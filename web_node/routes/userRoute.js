const auth = require('../app/auth')()
const UserModel = require('../models/userModel')

var init = (app) => {
  app.post('/user/:id', auth.authenticate(), (request, response) => {

    UserModel.getUser(request.params.id)

    .then((user) => {
      response.json(user)
    })

    .catch((error) => {
      console.error(error)
    })

  })
}

module.exports.init = init
