module.exports = {
    type: 'object',
    required:["name","lastName","email","dateOfBirth","password"],
    properties:{
        id:{
            type:"string",
            example:"6730bdad0776a521e7e6b9f3"
        },
        name:{
            type:"string",
            example:"Marcos"
        },
        lastName:{
            type:"string",
            example:"López"
        },
        email:{
            type:"string",
            example:"marcoslopezgarau@gmail.com"
        },
        dateOfBirth:{
            type:"date",
            example:"2001-11-19"
        },
        password:{
            type:"string",
            example:"1234567890"
        }
    },
    // Esquema para cambiar el rol de un usuario
    userRole:{
        type:"object",
        required: ["email","role"],
        properties:{
            email:{
                type:"string",
                example:"marcoslopezgarau@gmail.com"
            },
            role:{
                type:"array",
                example:["admin"]
            }
        }
    },
    // Esquema para crear un comentario en una web
    reviewMovie:{
        type:"object",
        required:["scoring","points","review"],
        properties:{
            scoring:{
                type:"number",
                example: 3
            },
            points:{
                type:"number",
                example: 3
            },
            review:{
                type:"string",
                example: "Buena película"
            },
        }
    },
    UserUpdate:{
        type:"object",
        properties:{
            message:{
                type:"string",
                example:"User updated"
            },
            name:{
                type:"string",
                example:"Marcos"
            },
            lastName:{
                type:"string",
                example:"López"
            },
            email:{
                type:"string",
                example:"marcoslopezgarau@gmail.com"
            },
            dateOfBirth:{
                type:"date",
                example:"2001-11-19"
            },
            password:{
                type:"string",
                example:"1234567890"
            },
            role:{
                type:"array",
                example:["user"]
            }
        }
    },
    UserUpdateRole:{
        type:"object",
        properties:{
            message:{
                type:"string",
                example:"Role changed"
            }
        }
    },
    UserDelete:{
        type:"object",
        properties:{
            message:{
                type:"string",
                example:"User deleted succesfully"
            }
        }
    },
    UserReviewWeb:{
        type:"object",
        properties:{
            message:{
                type:"string",
                example:"Web Reviewed"
            },
            message:{
                type:"string",
                example:"WEB_CREATED"
            },
            city:{
                type:"string",
                example:"Madrid"
            },
            activity:{
                type:"string",
                example:"Running"
            },
            title:{
                type:"string",
                example:"Running in Madrid"
            },
            summary:{
                type:"string",
                example:"Running in Madrid is a great experience"
            },
            texts:{
                type:"array",
                example:["Madrid is a great city"]
            },
            images:{
                type:"array",
                example:["madrid.jpg"]
            },
            reviews:{
                type:"object",
                properties:{
                    scoring:{
                        type:"number",
                        example: 3
                    },
                    points:{
                        type:"number",
                        example: 3
                    },
                    review:{
                        type:"string",
                        example: "Buena experiencia"
                    },
                }
            },
        }
    }
}