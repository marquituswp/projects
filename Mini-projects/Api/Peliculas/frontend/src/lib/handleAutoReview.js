const handleAutoReview = async (scoring, token, movieId) => {
    try {
        const body = {
            review: "Auto review",
            scoring: scoring,
        };
        console.log("body", body);
        console.log("token", token);
        await fetch(
            `http://localhost:3000/users/reviewMovie/${movieId}`,
            {
                method: "PUT",
                headers: {
                    Authorization: `Bearer ${token}`,
                    "Content-Type": "application/json",
                },
                body: JSON.stringify(body),
            }
        );

    } catch (error) {
        console.error("Login Error:", error);
        
    } 
};

export default handleAutoReview