const passport = require("passport")
const passportJWT = require("passport-jwt")
const users = require("./users")
const UserModel = require('../models/userModel')
const config = require('./config')

var ExtractJwt = passportJWT.ExtractJwt
var Strategy = passportJWT.Strategy

var params = {  
    secretOrKey: config.jwtSecret,
    jwtFromRequest: ExtractJwt.fromAuthHeaderAsBearerToken()
}


module.exports = function() {
    var strategy = new Strategy(params, function(payload, done) {
      UserModel.getUserById(payload.id)
      .then((user) => {
        return done(null, {
          id: user.id
        })
      }, (error) => {
        return done(new Error("User not found"), null)
      })
    })

    passport.use(strategy)

    return {
        initialize: function() {
            return passport.initialize()
        },
        authenticate: function() {
            return passport.authenticate("jwt", config.jwtSession)
        }
    }
}
