import { Display } from "./Display.js";

const displayValorAnterior = document.getElementById('valor-anterior');
const displayValorActual = document.getElementById('valor-actual');
const botonesNumeros = document.querySelectorAll('.number');
const botonesOperadores = document.querySelectorAll('.operator');
const botonC = document.getElementById('clear');
const botonDelete = document.getElementById('delete');

const display = new Display(displayValorAnterior, displayValorActual);

botonesNumeros.forEach(boton => {
    boton.addEventListener('click', () => {
        display.agregarNumero(boton.innerHTML);
        console.log(boton.innerHTML);
    });
});

botonC.addEventListener('click', () => {
    display.borrarTodo();
});

botonDelete.addEventListener('click', () => {
    display.borrar();
});

botonesOperadores.forEach(boton => {
    boton.addEventListener('click', () => {
        display.computar(boton.value);
    });
});