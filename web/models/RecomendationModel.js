
class RecomendationModel {
  constructor(recomendation) {
    if(!RecomendationModel.validate(recomendation)) {
      console.error("Not enought arguments for RecomendationModel!")
      return
    }
    Object.assign(this, recomendation)
  }

  statis.validate(obj) {
    if (!obj.date    || !obj.title ||
        !obj.content || !obj.doctor)
        return false
      else
        return true
  }
}

module.exports = RecomendationModel
