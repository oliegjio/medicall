const auth = require('../app/auth')()
const PatientModel = require('../models/PatientModel')

var init = (app) => {
  app.post('/patient/:id',
           auth.authenticate(),
           (request, response) => {

    PatientModel.getById(request.params.id)

    .then((patient) => {
      if (patient)
        return response.json(patient)
      return response.sendStatus(404)
    })

    .catch((error) => {
      console.error(error)
      return response.sendStatus(406)
    })
  })
}

module.exports.init = init
