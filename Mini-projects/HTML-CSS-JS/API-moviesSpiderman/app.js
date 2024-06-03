async function fetchData(url, options) {
	try {
		const response = await fetch(url, options);
		if (!response.ok) { // Verifica si la respuesta es correcta
			throw new Error(`HTTP error! status: ${response.status}`);
		}
		const data = await response.json();
		
		arrayMovies = data.d;
		arrayMovies.forEach(movie => {
			const tittle = movie.l;
			const image = movie.i.imageUrl;
			const cast = movie.s;

			const poster = 
			`
				<div>
					<img src="${image}" alt="${tittle}">
					<h2>${tittle}</h2>
					<small>${cast}</small>
				</div>
			`
			document.getElementById('container').innerHTML += poster;
		});


	} catch (error) {
		console.error('Error occurred:', error);
	}
}

const url = 'https://imdb8.p.rapidapi.com/auto-complete?q=spider';
const options = {
	method: 'GET',
	headers: {
		'X-RapidAPI-Key': 'fd1dc3f908msh9f8ab3414e4e3b8p1679bfjsn4618e9da5f04',
		'X-RapidAPI-Host': 'imdb8.p.rapidapi.com'
	}
};

fetchData(url, options);