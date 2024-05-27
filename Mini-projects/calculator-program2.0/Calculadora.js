export class Calculadora {
    constructor() {
        this.resultado = 0;
    }

    sumar(num1, num2) {
        this.resultado = num1 + num2;
        return this.resultado;
    }

    restar(num1, num2) {
        this.resultado = num1 - num2;
        return this.resultado;
    }

    multiplicar(num1, num2) {
        this.resultado = num1 * num2;
        return this.resultado;
    }

    dividir(num1, num2) {
        this.resultado = num1 / num2;
        return this.resultado;
    }

    getResultado() {
        return this.resultado;
    }
}