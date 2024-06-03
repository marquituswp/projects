// RANDOM PASSWORD GENERATOR

function generatePassword(passwordLength, includeLowerCase, includeUpperCase, includeNumbers, includeSymbols){
    if(passwordLength < 4){
        return 'Password length must be at least 4 characters'
    }
    
    const lowercaseCharacters = 'abcdefghijklmnopqrstuvwxyz'
    const uppercaseCharacters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    const numberCharacters = '0123456789'
    const symbolCharacters = '!@#$%^&*()_+'

    let allowedCharacters = ''
    console.log(passwordLength.value)
    allowedCharacters += (includeLowerCase.checked) ? lowercaseCharacters : ''
    allowedCharacters += (includeUpperCase.checked) ? uppercaseCharacters : ''
    allowedCharacters += (includeNumbers.checked) ? numberCharacters : ''
    allowedCharacters += (includeSymbols.checked) ? symbolCharacters : ''

    if(allowedCharacters === ''){
        return 'Must select at least one character type'
    }

    let passwordCharacters = ''
    for(let i = 0; i < passwordLength.value; i++){
        const randomIndex = Math.floor(Math.random() * allowedCharacters.length)
        passwordCharacters += allowedCharacters[randomIndex]
    }

    return passwordCharacters
}

const passwordLength = document.getElementById('passwordLength')
const includeLowerCase = document.getElementById('includeLowerCase')
const includeUpperCase = document.getElementById('includeUpperCase')
const includeNumbers = document.getElementById('includeNumbers')
const includeSymbols = document.getElementById('includeSymbols')
const generateButton = document.getElementById('generateButton')
const result = document.getElementById("result")
const copyButton = document.getElementById("copyButton")
const resultCopy = document.getElementById("result-copy")

generateButton.onclick = ()=>{
    result.textContent = 'Password: '
    result.textContent += generatePassword(passwordLength,includeLowerCase, includeUpperCase, includeNumbers, includeSymbols)
}

copyButton.onclick = () => {
    const password = result.textContent.slice(10);
    console.log(password);

    // Crear un elemento de texto temporal
    const tempInput = document.createElement("textarea");
    tempInput.value = password;
    document.body.appendChild(tempInput);

    // Seleccionar y copiar el texto
    tempInput.select();
    document.execCommand("copy");
    document.body.removeChild(tempInput);

    resultCopy.textContent = "Password copied to clipboard";
}