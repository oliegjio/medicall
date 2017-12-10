const RecomendationModel = require('../../models/RecomendationModel')
const db = require('../db')

db.serialize(() => {
  var recomendation = new RecomendationModel({
    title: 'Test title',
    date: '2017',
    content: 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.',
    doctor: '1',
    patient: '1'
  })
  RecomendationModel.commit(recomendation)
  .catch((error) => { console.log(error) })
})
