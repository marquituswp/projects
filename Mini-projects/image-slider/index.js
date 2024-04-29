//IMG SLIDER

const slides = document.querySelectorAll('.slides img');
let slide_index = 0;

let intervalId = null

// intializeSlider()
document.addEventListener('DOMContentLoaded', intializeSlider())


function intializeSlider(){
    if (slides.length > 0){

        slides[slide_index].classList.add('displaySlide')
        intervalId = setInterval(nextSlide,5000)
    }
}


function showSlide(index){

    if (index >= slides.length){
        slide_index = 0
    }
    else if (index < 0){
        slide_index = slides.length - 1
    }

    slides.forEach((slide) => {
        slide.classList.remove('displaySlide')
    })
    console.log(slide_index)
    slides[slide_index].classList.add('displaySlide')
}

function prevSlide(){
    clearInterval(intervalId)
    slide_index--
    showSlide(slide_index)
}

function nextSlide(){
    slide_index++
    showSlide(slide_index)
}