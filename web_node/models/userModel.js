var UserModel = function() {}

UserModel.db = require('../app/db')

UserModel.getUser = (id) => {
  return new Promise((resolve, reject) => {

    var callback = (error, user) => {
      if (error) { reject(error) }
      resolve(user)
    }

    UserModel.db.get(
      `select * from 'users' where id = ?`,
      [id],
      callback
    )

  })
}

UserModel.createUser = (user) => {
  return new Promise((resolve, reject) => {

    var callback = (error) => {
      if (error) { reject(error) }
      resolve(this)
    }

    UserModel.db.run(
      `insert into 'users' ('username', 'password') values (?, ?)`,
      [
        user.username,
        user.password
      ],
      callback
    )

  })
}

module.exports = UserModel
