const PatientModel = require('../models/PatientModel')
const bcrypt = require('bcrypt')

var init = (app) => {
  app.post("/register-patient", function(request, response) {

    var b = request.body
    if (!PatientModel.validate(b)) {
      response.sendStatus(406)
      return
    }
    var patient = new PatientModel(b)

    bcrypt.hash(patient.password, 10)
    .then((hash) => {
      patient.password = hash
      patient.commit()

      .then((info) => {
        return response.sendStatus(200)
      })

      .catch((error) => {
        console.error(error)
        response.sendStatus(406)
      })
    })
    .catch((error) => {
      console.error(error)
      response.sendStatus(400)
    })
  })
}

module.exports.init = init
