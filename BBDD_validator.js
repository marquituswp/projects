const {check} = require("express-validator")
const validateResults = require("D:/Programación/Workspace/projects/handleValidator.js")

const validateUser = [

    (req,res,next) =>{
        validateResults(req,res,next)
    }
]

module.exports = validateUser

