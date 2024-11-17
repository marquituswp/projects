const mongoose = require("mongoose")
const mongooseDelete = require("mongoose-delete")

const userSchema = new mongoose.Schema(
    {
        name:{
            type:String
        },
        lastName:{
            type:String
        },
        email:{
            type:String,
            unique:true
        },
        password:{
            type:String
        },
        dateOfBirth:{
            type:Date
        },
        role:{
            type:["admin","user"],
            default:"user"
        }
    },
    {
        timestamps:true
    }
)

userSchema.plugin(mongooseDelete,{overrideMethods:"all"})
module.exports = mongoose.model("user",userSchema)