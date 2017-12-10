const DoctorModel = require('../models/DoctorModel')
const bcrypt = require('bcrypt')
const jwt = require('jwt-simple')
const config = require('../app/config')

var init = (app) => {
  app.post("/register-doctor", function(request, response) {

    var b = request.body
    if (!DoctorModel.validate(b))
      return response.sendStatus(406)

    if (b.password != b.passwordRepeat)
      return response.sendStatus(406)

    var doctor = new DoctorModel(b)

    bcrypt.hash(doctor.password, 10)
    .then((hash) => {
      doctor.password = hash
      DoctorModel.commit(doctor)

      .then((info) => {
        var payload = { id: doctor.id }
        var token = jwt.encode(payload, config.jwtSecret)

        return response.json({
          token: token,
          doctor: doctor
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
