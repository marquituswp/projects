// ROCK PAPER SCISSORS GAME

const choices = ['rock', 'paper', 'scissors']
const playerDisplay = document.getElementById('playerDisplay')
const computerDisplay = document.getElementById('computerDisplay')
const resultDisplay = document.getElementById('resultDisplay')
const playerScore = document.getElementById('playerScore')
const computerScore = document.getElementById('computerScore')
const resetBtn = document.getElementById('resetBtn')

let playerScoreValue = 0
let computerScoreValue = 0

function playGame(playerChoice) {
    const computerChoice = choices[Math.floor(Math.random() * 3)]

    let result = ''

    if (playerChoice === computerChoice) {
        result = "IT'S A TIE!"
    }
    else {
        switch(playerChoice) {
            case 'rock':
                result = computerChoice === 'scissors' ? 'YOU WIN!' : 'YOU LOSE!'
                break
            case 'paper':
                result = computerChoice === 'rock' ? 'YOU WIN!' : 'YOU LOSE!'
                break
            case 'scissors':
                result = computerChoice === 'paper' ? 'YOU WIN!' : 'YOU LOSE!'
                break
        }
    }

    playerDisplay.innerHTML = `PLAYER: ${playerChoice}`
    computerDisplay.innerHTML = `COMPUTER: ${computerChoice}`

    resultDisplay.classList.remove('greenText', 'redText')
    if (result === 'YOU WIN!') {
        playerScoreValue++
        playerScore.textContent = playerScoreValue
        resultDisplay.classList.add('greenText')
    }
    else if (result === 'YOU LOSE!') {
        computerScoreValue++
        computerScore.textContent = computerScoreValue
        resultDisplay.classList.add('redText')
    }
    resultDisplay.innerHTML = result
    
}

function resetGame() {
    playerScoreValue = 0
    computerScoreValue = 0
    playerScore.textContent = playerScoreValue
    computerScore.textContent = computerScoreValue
    playerDisplay.innerHTML = 'PLAYER:'
    computerDisplay.innerHTML = 'COMPUTER:'
    resultDisplay.innerHTML = ''
    resultDisplay.classList.remove('greenText', 'redText')
}

resetBtn.addEventListener('click', resetGame)