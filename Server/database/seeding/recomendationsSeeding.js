const RecomendationModel = require('../../models/RecomendationModel')
const db = require('../db')

db.serialize(() => {
  var recomendation1 = new RecomendationModel({
    title: 'Test title 1',
    date: '2017',
    content: 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.',
    doctor: '1',
    patient: '1'
  })
  RecomendationModel.commit(recomendation1)
  .catch((error) => { console.log(error) })

  var recomendation2 = new RecomendationModel({
    title: 'Test title 2',
    date: '2018',
    content: 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.',
    doctor: '1',
    patient: '1'
  })
  RecomendationModel.commit(recomendation2)
  .catch((error) => { console.log(error) })

  var recomendation3 = new RecomendationModel({
    title: 'Test title 3',
    date: '2019',
    content: 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.',
    doctor: '2',
    patient: '2'
  })
  RecomendationModel.commit(recomendation3)
  .catch((error) => { console.log(error) })

  var recomendation4 = new RecomendationModel({
    title: 'Test title 4',
    date: '2020',
    content: 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.',
    doctor: '2',
    patient: '2'
  })
  RecomendationModel.commit(recomendation4)
  .catch((error) => { console.log(error) })
})
