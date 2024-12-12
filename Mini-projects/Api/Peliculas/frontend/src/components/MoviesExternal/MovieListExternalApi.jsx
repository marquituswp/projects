"use client";
import { useEffect, useState } from "react";
import handleAdaptMovie from "@/lib/handleAdaptMovie";
import { useAuth } from "@/context/AuthContext";
import Image from "next/image";

export default function MovieListExternalApi() {
    const { token } = useAuth()
    const [movies, setMovies] = useState(null);
    const [page, setPage] = useState(1);
    const [options, setOptions] = useState({
        method: 'GET',
        headers: {
            accept: 'application/json',
            Authorization: 'Bearer eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiJiOWIyODI5YzE3NjJkNWI2ZmIxODNjMmVhZDU1YTMxNCIsIm5iZiI6MTczNDAwMDAwMy41NzUsInN1YiI6IjY3NWFiZDgzN2MyZDUxYmRiZDFmN2U5ZSIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.NGen4Ylnw8RM9vTVRns6fg0_uBYu2PiUYkRAz_im8aM'
        }
    });
    const [messageError, setMessageError] = useState("");
    const [message, setMessage] = useState(""); // Estado para el mensaje de éxito

    useEffect(() => {
        try {
            const url = `https://api.themoviedb.org/3/discover/movie?include_adult=true&include_video=false&language=en-US&page=${page}&sort_by=popularity.desc`;
            fetch(url, options)
                .then(response => response.json())
                .then(data => {
                    if (data.results) {
                        setMessageError("");
                        setMovies(data.results);
                        console.log(data.results)
                    } else {
                        setMessageError("NO MOVIES");
                    }
                })
                .catch(() => setMessageError("ERROR FETCHING DATA"));
        } catch (error) {
            setMessageError("ERROR FETCHING DATA");
        }
    }, [page]);

    const handleNextPage = () => {
        setPage(prev => prev + 1);
    };

    const handlePrevPage = () => {
        setPage(prev => (prev > 1 ? prev - 1 : 1));
    };

    return (
        <div className="my-16 mx-4 sm:mx-10 lg:mx-40">
            {movies && (
                <ul className="grid grid-cols-1 sm:grid-cols-2 md:grid-cols-3 lg:grid-cols-4 gap-6">
                    {movies.map((movie, index) => (
                        <li
                            key={index}
                            className="flex flex-col items-center w-full bg-gray-900 p-6 rounded-lg transition-global relative"
                        >
                            <div className="block w-full">
                                <div
                                    className="relative w-full"
                                    style={{ paddingBottom: "150%" }}
                                >
                                    <Image
                                        src={`https://image.tmdb.org/t/p/w300_and_h450_bestv2${movie.poster_path}`}
                                        alt={`${movie.original_title} poster`}
                                        fill
                                        className="rounded-md object-cover"
                                    />
                                </div>
                                <h2 className="mt-4 text-center text-2xl font-bold text-yellow-400">
                                    {movie.original_title}
                                </h2>
                            </div>
                            <button
                                className="btn "
                                onClick={() => setMessage(handleAdaptMovie(movie, token))}
                            >
                                Add to List
                            </button>
                            {message === "MOVIE ADDED"   && (
                                <div key={1} className="mb-4 text-green-700 font-bold text-2xl text-center">
                                    {message}
                                </div>
                            )}
                            {message !== "MOVIE ADDED"  && (
                                    <div className="text-red-600 font-semibold text-center">
                                        {message}
                                    </div>
                                )}
                        </li>

                    ))}
                </ul>

            )}

            {messageError && (
                <div className="flex justify-center">
                    <h2 className="text-3xl text-yellow-400 font-bold">{messageError}</h2>
                </div>
            )}

            <div className="flex justify-between items-center mt-8">
                <button
                    onClick={handlePrevPage}
                    disabled={page === 1}
                    className={`btn ${page === 1 ? 'opacity-50 cursor-not-allowed' : ''}`}
                >
                    Previous Page
                </button>

                <span className="text-xl font-semibold text-yellow-400">Page {page}</span>

                <button
                    onClick={handleNextPage}
                    className="btn"
                >
                    Next Page
                </button>
            </div>
        </div>
    );
}
