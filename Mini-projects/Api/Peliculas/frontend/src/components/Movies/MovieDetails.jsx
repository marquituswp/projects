import Image from "next/image"
import HandlePoints from "@/components/Rating"
import Link from "next/link"
const getMovieId = async (id) => {
    try {
        let movie = null
        await fetch(`http://localhost:3000/movie/${id}`)
            .then(response => response.ok ? response.json() : response.text())
            .then(data => {
                movie = data
            })
        return movie
    } catch {
        return ("ERROR FETCHING DATA")
    }
}

export default async function MovieDetails({ movieId }) {
    const movie = await getMovieId(movieId)

    if (!movie) {
        return (
            <div className="flex justify-center items-center min-h-screen text-white">
                <p className="text-2xl">Error fetching data</p>
            </div>
        );
    }

    return (
        <div className="grid grid-cols-1 lg:grid-cols-3 gap-8 p-8 bg-gray-900 text-white relative">

            <div className="lg:col-span-1 flex flex-col justify-start items-center">
                <div className="relative w-full max-w-md mb-20">
                    <Image
                        src={movie.poster}
                        alt={`${movie.title} poster`}
                        layout="responsive"
                        width={300}
                        height={450}
                        className="rounded-lg shadow-lg"
                    />
                </div>

            </div>

            <div className="lg:col-span-2 space-y-6">
                <div className="flex justify-between">
                    <h1 className="text-5xl font-bold drop-shadow-lg text-yellow-400">
                        {movie.title}
                    </h1>
                    <Link href={`/movie/${movie._id}/leaveReview`} className={"btn"}>Leave a review</Link>
                </div>


                <div>
                    <h3 className="text-2xl font-semibold">Actors</h3>
                    {movie.actors.map((actor, index) => {
                        return <span key={index} className="text-lg text-gray-300">{actor} </span>
                    })}

                </div>

                <div>
                    <h3 className="text-2xl font-semibold">Genre</h3>
                    <p className="text-lg text-gray-300">{movie.filmGenre}</p>
                </div>

                <div className="flex items-center gap-4">
                    <h3 className="text-2xl font-semibold">Rating</h3>
                    <div className="text-lg text-gray-500 flex items-center">
                        <HandlePoints points={movie.points} />
                    </div>
                </div>

                <div className="space-y-6 h-80 overflow-y-auto p-4 bg-gray-800 rounded-lg shadow-lg">
                    <h2 className="text-3xl font-semibold text-yellow-400">Reviews</h2>
                    <ul className="space-y-4">
                        {movie.reviews.map((review, index) => (
                            <li
                                key={index}
                                className="p-6 flex gap-6"
                            >
                                <h3 className="text-lg font-bold text-white">{review.review}</h3>
                                <div className="text-lg text-gray-500 flex items-center">
                                    <HandlePoints points={review.scoring} />
                                </div>
                            </li>
                        ))}
                    </ul>
                </div>

            </div>
        </div>
    );
}