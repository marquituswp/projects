const mongoose = require("mongoose")
const mongooseDelete = require("mongoose-delete")

const movieSchema = new mongoose.Schema(
    {
        title:{
            type:String
        },
        date:{
            type:Date
        },
        actors:{
            type:[String]
        },
        filmGenre:{
            type:[
                "Action",
                "Adventure",
                "Comedy",
                "Drama",
                "Horror",
                "Thriller",
                "Romance",
                "Science Fiction",
                "Fantasy",
                "Documentary",
                "Animation",
                "Musical",
                "Crime",
                "Mystery",
                "Western",
                "Historical",
                "Biographical",
                "War",
                "Family",
                "Sports",
                "Noir",
                "Superhero"
              ]
        },
        poster:{
            type:String
        },
        reviews:{
            type:[Object],
            properties:{
                scoring:{
                    type:Number
                },
                points:{
                    type:Number
                },
                review:{
                    type:String
                }
            }
        }
    },
    {
        timestamps:true

})

movieSchema.plugin(mongooseDelete,{overrideMethods:"all"})
module.exports = mongoose.model("movie",movieSchema)