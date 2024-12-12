
export default function handleUploadMoviePoster(imageFile, token, movieId){
    try{
        // Crea un objeto FormData con la imagen y los textos
        const formData = new FormData();
        console.log("file",imageFile)
        formData.append("image", imageFile);
        console.log(formData)
        fetch(`http://localhost:3000/movie/${movieId}`, {
            method: "PATCH",
            headers: {
                Authorization: `Bearer ${token}`,
            },
            body: formData,
        })
        .then((response) => response.ok? response.json(): response.text())
        .then((data) => {
            console.log(data)
            router.push("/"); // Redirige al home o dashboard
        })
        .catch((error) => {
            console.log(error)
        });

    }catch(error){
        console.log(error)
    }

}