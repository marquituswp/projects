// NUMBER GUESSING GAME

const minNum = 1
const maxNum = 100
const answer = Math.round(Math.random()*(maxNum-minNum +1))+minNum
const inputNumber = document.getElementById("inputNumber")
const buttonNumber = document.getElementById("buttonNumber")
const resultTittle = document.getElementById("resultTittle")
const result = document.getElementById("result")

let attemps = 0
let guess
let running = true

inputNumber.onkeypress = (e)=>{
    if(e.key == "Enter"){
        buttonNumber.click()
    }
}

buttonNumber.onclick = ()=>{
    if(running){
        guess = inputNumber.value
        attemps++
        if(guess == answer){
            resultTittle.textContent = `Congratulations! You guessed the number in ${attemps} attemps`
            result.textContent = `The number was ${answer}`
            running = false
        }else if(guess < answer){
            resultTittle.textContent = `Try again!`
            result.textContent = `The number is higher`
        }else{
            resultTittle.textContent = `Try again!`
            result.textContent = `The number is lower`
        }
    }
}
