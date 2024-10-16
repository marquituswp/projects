const mongoose = require("mongoose")
const mongooseDelete = require("mongoose-delete")
const { array } = require("prop-types")

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
            type: [String],
            default: []
        },
        image:{
            type:String,
            required:true
        },
        location:{
            type:String,
            required:true
        },
    }
)