module.exports = {
    type:"object",
    require:["title","date","actors","poster","filmGenre"],
    properties:{
        title:{
            type:"string",
            example:"Spiderman 1"
        },
        date:{
            type:"date",
            example:"2002-06-21"
        },
        actors:{
            type:"array",
            example:["Tobey Maguire","James Franco"]
        },
        poster:{
            type:"string",
            example:"https://m.media-amazon.com/images/M/MV5BZWM0OWVmNTEtNWVkOS00MzgyLTkyMzgtMmE2ZTZiNjY4MmFiXkEyXkFqcGc@._V1_FMjpg_UX1000_.jpg"
        },
        filmGenre:{
            type:"array",
            example:"Superhero"
        }
    }
}