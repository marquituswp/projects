//TEMPERATURE CONVERSION PROGRAM

const result = document.getElementById("result")
const textBox = document.getElementById("textBox")
const toCelsius = document.getElementById("toCelsius")
const toFahrenheit = document.getElementById("toFahrenheit")

let temp = 0

function convert(){
    if(toCelsius.checked){
        temp = (textBox.value - 32) * 5/9
        result.textContent = `${textBox.value}°F is ${temp.toFixed(1)}°C`
    }
    else if (toFahrenheit.checked){
        temp = textBox.value * 9/5 + 32
        result.textContent = `${textBox.value}°C is ${temp.toFixed(1)}°F`
    }else {
        result.textContent = `Please select a conversion`
    }
}