const mongoose = require("mongoose")
const mongooseDelete = require("mongoose-delete")

const UserScheme = new mongoose.Schema(
    {
        name: {
            type:String,
            required : true
        },
        lastName1:{
            type:String,
            required : true
        },
        lastName2:{
            type:String,
        },
        email:{
            type:String,
            required:true
        },
        dateOfBirth: {
            type: Date,
            required:true
        },
        password:{
            type: String,
            required: true
        },
        data:{
            
        }
    
    }
)