let playerText = document.getElementById('playerText');
let restartBtn = document.getElementById('restartBtn');
let boxes = Array.from(document.querySelectorAll('.box'));

let winnerIndicator = getComputedStyle(document.body).getPropertyValue('--winning-blocks');

console.log(boxes);

const O_TEXT = 'O';
const X_TEXT = 'X';

let currentPlayer = X_TEXT;

let spaces = Array(9).fill(null);

const startGame = () => {
    boxes.forEach(box => box.addEventListener('click', boxClicked));
}

function boxClicked(e){
    const id = e.target.id;
    if(!spaces[id]){
        spaces[id] = currentPlayer;
        e.target.innerText = currentPlayer;

        if(playerHasWon() !== false){
            playerText.innerText = `${currentPlayer} has won!`;
            spaces = Array(9).fill(playerHasWon);
            let winningBlocks = playerHasWon();
            console.log(winningBlocks);
            winningBlocks.map(box => boxes[box].style.backgroundColor = winnerIndicator);
            return;
        }

        currentPlayer = currentPlayer === X_TEXT ? O_TEXT : X_TEXT;
    }
}

const winningCombinations = [
    [0, 1, 2], // Top row
    [3, 4, 5], // Middle row
    [6, 7, 8], // Bottom row
    [0, 3, 6], // Left column
    [1, 4, 7], // Middle column
    [2, 5, 8], // Right column
    [0, 4, 8], // Diagonal
    [2, 4, 6] // Diagonal
]

function playerHasWon(){
    for(let i = 0; i < winningCombinations.length; i++){
        const winCondition = winningCombinations[i];
        let a = spaces[winCondition[0]];
        let b = spaces[winCondition[1]];
        let c = spaces[winCondition[2]];

        if(!a || !b || !c){
            continue;
        }

        if(a === b && b === c){
            return [winCondition[0], winCondition[1], winCondition[2]];
        }
    }
    return false;
}

restartBtn.addEventListener('click', restart)

function restart(){
    spaces = Array(9).fill(null);
    boxes.forEach(box => box.innerText = '');
    playerText.innerText = 'Tic Tac Toe';
    currentPlayer = X_TEXT;
}

startGame();