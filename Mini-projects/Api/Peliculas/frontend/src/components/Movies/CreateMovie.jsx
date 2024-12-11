"use client";
import Image from "next/image";
import StarRating from "../StarRating";
import { Formik, Form, Field, ErrorMessage } from "formik";
import * as Yup from "yup";
import { useState } from "react";
import handleUploadMoviePoster from "@/lib/handleUploadMoviePoster";
import { useAuth } from "@/context/AuthContext";
import { useRouter } from "next/navigation";
const CreateMovieSchema = Yup.object().shape({
    title: Yup.string().required("Title is required").min(3, "Title too short"),
    filmGenre: Yup.string().required("Genre is required").notOneOf([""], "Genre is required"),
    actors: Yup.string()
        .required("Actors are required")
        .matches(/^[a-zA-Z0-9 ,]+$/, "Invalid characters"),
    date: Yup.date()
        .required("date is required"),
    poster: Yup.mixed().required("Poster is required"),
});

export default function CreateMovie() {
    const [previewImage, setPreviewImage] = useState(null);
    const [genreList] = useState([
        "Action", "Adventure", "Comedy", "Drama", "Horror", "Thriller",
        "Romance", "Science Fiction", "Fantasy", "Documentary", "Animation",
        "Musical", "Crime", "Mystery", "Western", "Historical", "Biographical",
        "War", "Family", "Sports", "Noir", "Superhero",
    ]);
    const [imageFile, setImageFile] = useState(null); // Almacena el archivo seleccionado
    const [successMessage, setSuccessMessage] = useState(""); // Estado para el mensaje de éxito
    const { token } = useAuth()
    const router = useRouter()

    const handleSubmit = async (values, { setSubmitting, resetForm, setErrors }) => {
        try {
            const body = {
                title: values.title,
                date: values.date,
                actors: values.actors.split(",").map((actor) => actor.trim()), // Convierte el string en un array y elimina espacios
                filmGenre: Array.isArray(values.filmGenre)
                    ? values.filmGenre
                    : [values.filmGenre], // Convierte en array si no lo es
            };
            console.log(body)
            const response = await fetch("http://localhost:3000/movie", {
                method: "POST",
                headers: {
                    Authorization: `Bearer ${token}`,
                    "Content-Type": "application/json",
                },
                body: JSON.stringify(body),
            });

            if (response.ok) {
                const data = await response.json();
                setSuccessMessage("MOVIE CREATED")
                handleUploadMoviePoster(imageFile, token, data._id)
                setTimeout(() => {
                    resetForm();
                    setPreviewImage(null);
                    router.push("/")
                }, 4000);
                
            } else {
                setSuccessMessage("");
                const errorText = await response.text();
                setErrors({ general: errorText || "Registration failed." });
            }
        } catch {
            setSuccessMessage("");
            setErrors({ general: "An unexpected error occurred. Please try again." });
        } finally {
            setSubmitting(false);
        }
    };

    const handleFileChange = (event, setFieldValue) => {
        const file = event.target.files[0];
        if (file) {
            setImageFile(file); // Almacena el archivo en el estado
            setFieldValue("poster", file); // Pasa el archivo al formulario
        }
    };


    return (
        <div className="flex justify-center items-center min-h-screen text-white">
            <div className="bg-gray-800 p-8 rounded-lg shadow-lg w-full h-full">
                <h1 className="text-3xl font-bold mb-6 text-yellow-400">Create a Movie</h1>
                <Formik
                    initialValues={{
                        title: "",
                        filmGenre: "",
                        actors: "",
                        date: "",
                        poster: "",
                    }}
                    validationSchema={CreateMovieSchema}
                    onSubmit={handleSubmit}
                >
                    {({ setFieldValue, values, isSubmitting, errors }) => (
                        <Form className="grid grid-cols-1 lg:grid-cols-3 gap-8 p-8 bg-gray-900 h-full text-white">
                            <div className="lg:col-span-1 flex flex-col justify-start items-center">
                                <label htmlFor="poster" className="block font-semibold">
                                    Poster
                                </label>
                                <input
                                    id="poster"
                                    name="poster"
                                    type="file"
                                    accept="image/*"
                                    className="block w-full text-gray-500 file:bg-yellow-400 file:border-none file:rounded-lg file:px-4 file:py-2"
                                    onChange={(event) => {
                                        const file = event.currentTarget.files[0];
                                        handleFileChange(event, setFieldValue);
                                        setPreviewImage(URL.createObjectURL(file));
                                    }}
                                />
                                {previewImage && (
                                    <div className="relative w-full  mb-20">
                                        <Image
                                            src={previewImage}
                                            alt={`${values.title} poster`}
                                            layout="responsive"
                                            width={300}
                                            height={450}
                                            className="rounded-lg shadow-lg"
                                        />
                                    </div>


                                )}
                                <ErrorMessage
                                    name="poster"
                                    component="div"
                                    className="text-red-500 text-sm"
                                />
                            </div>
                            <div className="lg:col-span-2 space-y-6">
                                <div>
                                    <Field
                                        name="title"
                                        type="text"
                                        className="border-b-2 text-5xl font-bold drop-shadow-lg text-yellow-400 border-transparent bg-transparent rounded-lg p-2 focus:outline-none focus:border-blue-500"
                                        placeholder="Movie title"
                                    />
                                    <ErrorMessage
                                        name="title"
                                        component="div"
                                        className="text-red-500 text-sm"
                                    />
                                </div>

                                <div>
                                    <label htmlFor="actors" className="block text-2xl font-semibold">
                                        Actors (comma-separated)
                                    </label>
                                    <Field
                                        name="actors"
                                        type="text"
                                        className="border-b-2 font-semibold drop-shadow-lg text-lg text-gray-300 border-transparent bg-transparent rounded-lg p-2 focus:outline-none focus:border-blue-500"
                                        placeholder="Actor1, Actor2, Actor3"
                                    />
                                    <ErrorMessage
                                        name="actors"
                                        component="div"
                                        className="text-red-500 text-sm"
                                    />
                                </div>

                                <div>
                                    <label htmlFor="filmGenre" className="block text-2xl font-semibold">
                                        Genre
                                    </label>
                                    <Field
                                        as="select"
                                        name="filmGenre"
                                        className="w-40 h-10 border-b-2 text-gray-300 border-transparent bg-transparent rounded-lg p-2 focus:outline-none focus:border-blue-500"
                                    >
                                        <option className="text-black" value="" name="filmGenre">All Genres</option>
                                        {genreList.map((genre) => (
                                            <option key={genre} value={genre} className="text-black">
                                                {genre}
                                            </option>
                                        ))}
                                    </Field>
                                    <ErrorMessage
                                        name="filmGenre"
                                        component="div"
                                        className="text-red-500 text-sm"
                                    />
                                </div>

                                <div>
                                    <label htmlFor="date" className="block text-2xl font-semibold">
                                        Date
                                    </label>
                                    <Field
                                        name="date"
                                        type="date"
                                        className="border-b-2 font-semibold drop-shadow-lg text-lg text-gray-300 border-transparent bg-transparent rounded-lg p-2 focus:outline-none focus:border-blue-500"
                                        placeholder="Actor1, Actor2, Actor3"
                                    />
                                    <ErrorMessage
                                        name="date"
                                        component="div"
                                        className="text-red-500 text-sm"
                                    />
                                </div>

                                {successMessage && (
                                    <div className="mb-4 text-green-700 font-bold text-2xl text-center">
                                        {successMessage}
                                    </div>
                                )}

                                {errors.general && (
                                    <div className="text-red-600 font-semibold text-center">
                                        {errors.general}
                                    </div>
                                )}

                                <button
                                    type="submit"
                                    disabled={isSubmitting}
                                    className="btn bg-yellow-400 hover:bg-yellow-500 w-full py-2 text-black font-bold rounded-lg"
                                >
                                    {isSubmitting ? "Submitting..." : "Create Movie"}
                                </button>
                            </div>
                        </Form>
                    )}
                </Formik>
            </div>
        </div>
    );
}
