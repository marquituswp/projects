// COUNTER PROGRAM

const decrease = document.getElementById("decrement")
const increase = document.getElementById("increment")
const clear = document.getElementById("clear")

const countlabel = document.getElementById("countlabel")

let count = 0

decrease.onclick = () =>{
    count--
    countlabel.textContent = count
}

increase.onclick = () =>{
    count++
    countlabel.textContent = count
}

clear.onclick = () =>{
    count = 0
    countlabel.textContent = count
}
