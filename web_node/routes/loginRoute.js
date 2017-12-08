var init = (app) => {
  app.get('/login', (request, response) => {
    response.send('true')
  })
}

module.exports.init = init
