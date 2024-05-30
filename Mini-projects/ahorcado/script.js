import {words} from './words.js';

const wordContainer = document.getElementById('wordContainer');
const startBtn = document.getElementById('startBtn');
const usedLetters = document.getElementById('usedLetters');
const Message = document.getElementById('message');
const correctWord = document.getElementById('correctWord');
const isntructions = document.getElementById('instructions');
const score = document.getElementById('score');
const wins = document.getElementById('wins');
const loses = document.getElementById('losses');
const pistaText = document.getElementById('pistaText');
const pista = document.getElementById('pista');
const pistaBtn = document.getElementById('pistaBtn');
const numPistas = document.getElementById('numPistas');

let canvas = document.getElementById('canvas');
let ctx = canvas.getContext('2d');
ctx.canvas.width = 0;
ctx.canvas.height = 0;
pista.style.display = 'none';


const bodyParts = [
    [4,2,1,1],
    [4,3,1,2],
    [3,5,1,1],
    [5,5,1,1],
    [3,3,1,1],
    [5,3,1,1]
];

let selectedWord;
let usedLettersArray;
let mistakes;
let hits;
let pistas;
let winscount = 0;
let losescount = 0;

const addLetter = (letter)=>{
    const letterElement = document.createElement('span');
    letterElement.innerHTML = letter.toUpperCase();
    usedLetters.appendChild(letterElement);
}  

const addBodyPart = (part)=>{
    ctx.fillStyle = '#fff';
    ctx.fillRect(...part);
}

const wrongLetter = ()=>{
    addBodyPart(bodyParts[mistakes]);
    mistakes++;
    if(mistakes === bodyParts.length) endGame();
}

const endGame = ()=>{
    document.removeEventListener('keydown', checkLetter);
    startBtn.id = 'startBtn';
    startBtn.innerHTML = 'Play again';
    startBtn.addEventListener('click', startGame);
    if(mistakes === bodyParts.length){
        Message.innerHTML = 'You lose';
        correctWord.innerHTML = `The word was: ${selectedWord.join('')}`;
        Message.classList.add('lose');
        losescount++;
        loses.innerHTML = `${losescount}`;
    }

    if(hits === selectedWord.length){
        Message.innerHTML = 'You win';
        Message.classList.add('win');
        winscount++;
        wins.innerHTML = `${winscount}`;
    }
        
}

const letterToAccent = (letter)=>{
    if(letter === 'A') return 'Á';
    if(letter === 'E') return 'É';
    if(letter === 'I') return 'Í';
    if(letter === 'O') return 'Ó';
    if(letter === 'U') return 'Ú';
    return letter;
}


const correctLetter = (letter)=>{
    const {children} = wordContainer;
    for(let i=0; i<children.length; i++){
        if(children[i].innerHTML === letter || children[i].innerHTML === letterToAccent(letter)){
            children[i].classList.toggle('hidden');
            hits++;
        }
    }
    if (letter === pistaText.innerHTML){
        pistaText.innerHTML = '';
    }
    if(hits === selectedWord.length) endGame();
}

const wordWithAccent = (word)=>{
    for(let i=0; i<word.length; i++){
        if(word[i] === 'Á') word[i] = 'A';
        if(word[i] === 'É') word[i] = 'E';
        if(word[i] === 'Í') word[i] = 'I';
        if(word[i] === 'Ó') word[i] = 'O';
        if(word[i] === 'Ú') word[i] = 'U';
    }
    return word;
}

const letterInput = (letter)=>{
    selectedWord = wordWithAccent(selectedWord);
    if(selectedWord.includes(letter)){
        correctLetter(letter);

    }else{
        wrongLetter();
    }
    addLetter(letter);
    usedLettersArray.push(letter);
}

const checkLetter = (e)=>{
    let newLetter = e.key.toUpperCase();
    if(newLetter.match(/^[a-zñ]$/i) && !usedLettersArray.includes(newLetter)){
        letterInput(newLetter);
    }
}

const drawHangMan = ()=>{
    ctx.canvas.width = 120;
    ctx.canvas.height = 160;
    ctx.lineWidth = 2;
    ctx.scale(20,20);
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    ctx.fillStyle = '#d95d39'
    ctx.fillRect(0, 7, 4, 1);
    ctx.fillRect(1, 0, 1, 8);
    ctx.fillRect(2, 0, 3, 1);
    ctx.fillRect(4, 1, 1, 1);

}


const drawWord = ()=>{
    selectedWord.forEach(letter=>{
        const letterElement = document.createElement('span');
        letterElement.innerHTML = letter.toUpperCase();
        letterElement.classList.add('letter');
        letterElement.classList.add('hidden');
        wordContainer.appendChild(letterElement);
    });
}

const startGame = ()=>{
    pistas = 1;
    usedLettersArray = [];
    mistakes = 0;
    hits = 0;
    pista.style.display = 'block';
    numPistas.innerHTML = `Available hints <span id="pistaCounter">1</span>`;
    pistaText.innerHTML = '';
    Message.innerHTML = '';
    correctWord.innerHTML = '';
    wordContainer.innerHTML = '';
    usedLetters.innerHTML = '';
    pistaBtn.id = 'pistaBtn';
    startBtn.innerHTML = 'START';
    startBtn.removeEventListener('click', startGame);
    startBtn.id = 'startBtnInactive';
    isntructions.style.display = 'none';
    score.style.bottom = '300px';
    drawHangMan();
    selectedWord = words[Math.floor(Math.random()*words.length)].toUpperCase();
    selectedWord = selectedWord.split('');
    drawWord();
    document.addEventListener('keydown', checkLetter);
}

const showPista = ()=>{
    const pistaCounter = document.getElementById('pistaCounter');
    if(pistas > 0){
        pistaCounter.innerHTML = `${--pistas}`;
        var randomPista = selectedWord[Math.floor(Math.random()*selectedWord.length)];
        while(usedLettersArray.includes(randomPista)){
            randomPista = selectedWord[Math.floor(Math.random()*selectedWord.length)];
        }
        pistaText.innerHTML = randomPista;
    }
    if(pistas === 0){
        pistaBtn.id = 'pistaBtnInactive';
        numPistas.innerHTML = '';
    }
}

startBtn.addEventListener('click', startGame);
pistaBtn.addEventListener('click', showPista);