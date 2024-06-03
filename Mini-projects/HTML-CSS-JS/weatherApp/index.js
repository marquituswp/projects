// WEATHER APP

const weatherForm = document.querySelector('.weatherForm');
const cityInput = document.querySelector('.cityInput');
const card = document.querySelector('.card');
const apikey = "7c24f2c4c9969906e333836cf56c87b7";

function handleKeyPress(event) {
    if(event.key === 'Enter'){
        weatherForm.dispatchEvent(new Event('submit'));
    }
}

weatherForm.addEventListener('submit', async (event) => {
    event.preventDefault();
    const city = cityInput.value;
    if (!city) {
        displayError('You must enter a city');
        return;
    }
    try{
        const weatherData = await getWeather(city);
        showWeather(weatherData);
    }catch(error){
        console.error(error);
        displayError('City not found');
    }
})

async function getWeather(city) {
    const apiUrl = `https://api.openweathermap.org/data/2.5/weather?q=${city}&appid=${apikey}`;
    const response = await fetch(apiUrl);
    const data = await response.json();
    if(!response.ok){
        throw new Error("City not found");
    }
    return data;
}

function showWeather(data) {
    const weather = data.weather[0].id;
    const temp = data.main.temp - 273.15;
    const feelsLike = data.main.feels_like - 273.15;
    const humidity = data.main.humidity;
    const windSpeed = data.wind.speed;
    const cityName = data.name;

    const weatherEmoji = getWeatherEmoji(weather);

    const cityDisplay = document.createElement('h1');
    cityDisplay.textContent = cityName;

    const weatherDisplay = document.createElement('p');
    weatherDisplay.textContent = `${weatherEmoji}`;
    weatherDisplay.classList.add('weatherEmoji');

    const tempDisplay = document.createElement('p');
    tempDisplay.textContent = `${temp.toFixed(1)}°C`;
    tempDisplay.classList.add('tempDisplay');

    const feelsLikeDisplay = document.createElement('p');
    feelsLikeDisplay.textContent = `Feels like: ${feelsLike.toFixed(1)}°C`;
    feelsLikeDisplay.classList.add('descDisplay');

    const humidityDisplay = document.createElement('p');
    humidityDisplay.textContent = `Humidity: ${humidity}%`;
    humidityDisplay.classList.add('humidityDisplay');

    const windSpeedDisplay = document.createElement('p');
    windSpeedDisplay.textContent = `Wind speed: ${windSpeed} m/s`;
    windSpeedDisplay.classList.add('descDisplay');

    card.textContent = '';
    card.style.display='flex'
    card.appendChild(cityDisplay);
    card.appendChild(tempDisplay);
    card.appendChild(humidityDisplay);
    card.appendChild(feelsLikeDisplay);
    card.appendChild(windSpeedDisplay);
    card.appendChild(weatherDisplay);


    cityInput.value = '';
    cityInput.focus();
}

function getWeatherEmoji(weather) {
    switch(true){
        case (weather >= 200 && weather < 300):
            return '⛈️';
        case (weather >= 300 && weather < 400):
            return '🌧️';
        case (weather >= 500 && weather < 600):
            return '🌧️';
        case (weather >= 600 && weather < 700):
            return '❄️';
        case (weather >= 700 && weather < 800):
            return '🌫️';
        case (weather === 800):
            return '☀️';
        case (weather >= 801 && weather < 900):
            return '☁️';
        default:
            return '🤷‍♂️';
    }
}

function displayError(message) {
    const errorDisplay = document.createElement('p')
    errorDisplay.textContent = message;
    errorDisplay.classList.add('errorDisplay');

    card.textContent = '';
    card.style.display='flex'
    card.appendChild(errorDisplay);
}
