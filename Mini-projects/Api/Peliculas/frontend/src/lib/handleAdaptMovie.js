"use client"
import handleUploadMoviePoster from "./handleUploadMoviePoster";
const fetchProviders = async (movie) => {
    const providers = [];
    try {
        
        const url = `https://api.themoviedb.org/3/movie/${movie.id}/watch/providers`;
        const options = {
            method: 'GET',
            headers: {
                accept: 'application/json',
                Authorization: 'Bearer eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiJiOWIyODI5YzE3NjJkNWI2ZmIxODNjMmVhZDU1YTMxNCIsIm5iZiI6MTczNDAwMDAwMy41NzUsInN1YiI6IjY3NWFiZDgzN2MyZDUxYmRiZDFmN2U5ZSIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.NGen4Ylnw8RM9vTVRns6fg0_uBYu2PiUYkRAz_im8aM'
            }
        }
        const response = await fetch(url, options);
        const data = await response.json();
        if (data.results.ES) {
            data.results.ES.map((provider) => {
                providers.push(provider.provider_name);
            });
        } else {
            providers.push("NO PLATFORMS");
        }
    } catch (error) {
        console.error("ERROR FETCHING PROVIDERS", error);
    }

    return providers;
};

const fetchGenres = async (movie) => {
    const genreList = [];
    try {
        
        const url = `https://api.themoviedb.org/3/movie/${movie.id}?language=en-US`;
        const options = {
            method: 'GET',
            headers: {
                accept: 'application/json',
                Authorization: 'Bearer eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiJiOWIyODI5YzE3NjJkNWI2ZmIxODNjMmVhZDU1YTMxNCIsIm5iZiI6MTczNDAwMDAwMy41NzUsInN1YiI6IjY3NWFiZDgzN2MyZDUxYmRiZDFmN2U5ZSIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.NGen4Ylnw8RM9vTVRns6fg0_uBYu2PiUYkRAz_im8aM'
            }
        }
        const response = await fetch(url, options);
        const data = await response.json();
        if (data.genres) {
            data.genres.map((genre) => {
                genreList.push(genre.name);
            });
        } else {
            genreList.push("NO GENRES");
        }
    } catch (error) {
        console.error("ERROR FETCHING GENRES", error);
    }

    return genreList;
};

const handleAdaptMovie = async (movie, token) => {

    const providers = await fetchProviders(movie);
    const genreList = await fetchGenres(movie);
    let Message = "";
    try {
        const body = {
            title: movie.original_title,
            date: movie.release_date,
            platforms: providers,
            actors: ["No Info"],
            filmGenre: genreList,
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
            Message ="MOVIE ADDED";
            handleUploadMoviePoster(`https://image.tmdb.org/t/p/w300_and_h450_bestv2${movie.poster_path}`, token, data._id)
        } else {
            Message = "";
            const errorText = await response.text();
            Message = errorText || "Registration failed."
        }
    } catch (error) {
        console.log(error)
        Message = "";
        Message = "An unexpected error occurred. Please try again."
    }

    return Message;
};

export default handleAdaptMovie