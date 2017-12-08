const PatientModel = require('../models/PatientModel')

var init = (app) => {
  app.post("/register-patient", function(request, response) {

    var b = request.body
    if (!PatientModel.validate(b)) {
      response.sendStatus(406)
      return
    }
    var patient = new PatientModel(b)

    patient.commit()

    .then((info) => {
      return response.sendStatus(200)
    })

    .catch((error) => {
      console.error(error)
      response.sendStatus(406)
    })
  })
}

module.exports.init = init
