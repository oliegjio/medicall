const RecomendationModel = require('../models/RecomendationModel')
const auth = require('../app/auth')()

var init = (app) => {
  app.post('/recomendations/patient/:id',
           auth.authenticate(),
           (request, response) => {

    RecomendationModel.getByPatient(request.params.id)

    .then((recomendations) => {
      if (recomendations) {
        var recomendationsObject = {}
        recomendations.forEach((element, index) => {
          recomendationsObject[index] = element
        })
        return response.json(recomendationsObject)
      }
      return response.sendStatus(404)
    })

    .catch((error) => {
      console.error(error)
      return response.sendStatus(406)
    })
  })
}

module.exports.init = init
