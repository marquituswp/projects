async function fetchData(url, options) {
	try {
		const response = await fetch(url, options);
		if (!response.ok) { // Verifica si la respuesta es correcta
			throw new Error(`HTTP error! status: ${response.status}`);
		}
		const result = await response.json();
		console.log(result);
	} catch (error) {
		console.error('Error occurred:', error);
	}
}

const url = 'https://imdb-com.p.rapidapi.com/search?searchTerm=spiderman';
const options = {
	method: 'GET',
	headers: {
		'X-RapidAPI-Key': 'fd1dc3f908msh9f8ab3414e4e3b8p1679bfjsn4618e9da5f04',
		'X-RapidAPI-Host': 'imdb-com.p.rapidapi.com'
	}
};

fetchData(url, options);