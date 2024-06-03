

async function fetchPokemon(){
        try{
            const myInput = document.getElementById("search")
            const myImg = document.getElementById("pokeImg")
            const pokeName = document.getElementById("pokeName")
            const pokeType = document.getElementById("pokeType")
            const response = await fetch(`https://pokeapi.co/api/v2/pokemon/${myInput.value}`)
            if (!response.ok){
                myImg.style.display = "none"
                pokeName.textContent = "Pokemon not found"
                pokeName.style.color = "red"
                pokeType.textContent = ""
                throw new Error(`HTTP error! status: ${response.status}`)
            }
            const data = await response.json()
            myImg.src = data.sprites.front_default
            myImg.style.display = "block"
            pokeName.textContent = `Name: ${data.name}`
            pokeType.textContent = `Type: ${data.types[0].type.name}`

        }catch(error){
            console.error(error)
        }
    }