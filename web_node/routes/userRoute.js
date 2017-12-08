const auth = require('../app/auth')()
const PatientModel = require('../models/PatientModel')

var init = (app) => {
  app.post('/user/:id', auth.authenticate(), (request, response) => {

    PatientModel.getById(request.params.id)

    .then((user) => {
      if (user) response.json(user)
      response.sendStatus(404)
    })

    .catch((error) => {
      console.error(error)
      response.sendStatus(406)
    })
  })
}

module.exports.init = init
