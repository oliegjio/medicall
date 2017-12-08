var UserModel = function() {}

UserModel.db = require('../app/db')

UserModel.getUser = (id) => {
  return new Promise((resolve, reject) => {
    UserModel.db.get(`select * from 'users' where id = ?`, [id], (error, user) => {
      if (error) { reject(error) }
      resolve(user)
    })
  })
}

module.exports = UserModel
