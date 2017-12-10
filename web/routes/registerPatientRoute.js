const PatientModel = require('../models/PatientModel')
const bcrypt = require('bcrypt')
const jwt = require('jwt-simple')
const config = require('../app/config')

var init = (app) => {
  app.post('/register-patient', function(request, response) {

    var b = request.body
    if (!PatientModel.validate(b))
      return response.sendStatus(406)

    if (b.password != b.passwordRepeat)
      return response.sendStatus(406)

    var patient = new PatientModel(b)

    bcrypt.hash(patient.password, 10)
    .then((hash) => {
      patient.password = hash
      PatientModel.commit(patient)

      .then((info) => {
        var payload = { id: patient.id }
        var token = jwt.encode(payload, config.jwtSecret)

        return response.json({
          token: token,
          patient: patient
        })
      })

      .catch((error) => {
        console.error(error)
        return response.sendStatus(406)
      })
    })
    .catch((error) => {
      console.error(error)
      return response.sendStatus(400)
    })
  })
}

module.exports.init = init
