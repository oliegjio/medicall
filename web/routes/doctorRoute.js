const auth = require('../app/auth')()
const DoctorModel = require('../models/DoctorModel')

var init = (app) => {
  app.post('/doctor/:id',
           auth.authenticate(),
           (request, response) => {

    DoctorModel.getById(request.params.id)

    .then((doctor) => {
      if (doctor)
        return response.json(doctor)
      return response.sendStatus(404)
    })

    .catch((error) => {
      console.error(error)
      return response.sendStatus(406)
    })
  })
}

module.exports.init = init
