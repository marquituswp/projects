// DIGITAL CLOCK PROGRAM

function updateClock(){

    const now = new Date()
    let hour = now.getHours()
    const meridium = hour >=12 ? 'PM':'AM'
    hour = hour % 12 || 12
    hour = hour.toString().padStart(2,0)
    const minute = now.getMinutes().toString().padStart(2,0)
    const second = now.getSeconds().toString().padStart(2,0)

    const timeString = `${hour}:${minute}:${second} ${meridium}`

    document.getElementById('clock').textContent=timeString
}

updateClock()
setInterval(updateClock,1000)