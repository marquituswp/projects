
export default function handleUploadProfilePicture(token, imageFile){
    try{
        // Crea un objeto FormData con la imagen y los textos
        const formData = new FormData();
        formData.append("image", imageFile);
        fetch("http://localhost:3000/auth/uploadProfilePicture", {
            method: "POST",
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