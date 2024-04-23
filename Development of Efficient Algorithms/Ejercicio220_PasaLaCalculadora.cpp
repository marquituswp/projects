#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

//creamos matriz de todos los posibles valores hasta 31 que es cuando se pierde
//y todos los digitos que se pueden pulsar (de 1-9)
char matrix[32][10];
//matriz de el digito que pulsan y los respectivos que puede pulsar
int posibles[10][4] = { 
    {0, 0, 0, 0}, // 0 no es posible pulsarlo
    {2, 3, 4, 7}, // Si el ultima digito es 1, solo se puede pulsar 2, 3, 4 o 7
    {1, 3, 5, 8}, // 2
    {1, 2, 6, 9}, // 3
    {5, 6, 1, 7}, // 4
    {4, 6, 2, 8}, // 5
    {4, 5, 3, 9}, // 6
    {8, 9, 1, 4}, // 7
    {7, 9, 2, 5}, // 8
    {7, 8, 3, 6}  // 9
 };

bool calcula_victoria_1(int num, int dig);
bool calcula_victoria_2(int num, int dig);

// Determina si gana el jugador 1 a partir de lo que le llega al jugador 2
bool calcula_victoria_2(int num, int dig) {
    //si le llega una valor superior o igual a 31 devolvera false (ha perdido jugador 1)
    if (num >= 31)
        return false;

    //le manda todos las posibles combinaciones que puede hacer con los 4 digitos y determina si gana o no el jugador 1
    for (int i = 0; i < 4; ++i) {
        int digito = posibles[dig][i];
        //si el jugador 1 no gana devolvera false (ha perdido jugador 1)
        if (!calcula_victoria_1(num + digito, digito))
            return false;
    }
    return true;
}

// Determina si gana el jugador 1 a partir de lo que le llega al jugador 1
bool calcula_victoria_1(int num, int dig) {
    //si le llega un numero mayor o igual a 31 devolvera true(ha ganado jugador 1)
    if (num >= 31)
        return true;

    // Miramos si la combinacion de numero llegado y digito pulsado ya se ha calculado
    if (matrix[num][dig] != ' ') {
        //si ya se ha calculado devolveremos true si con esta combinacion gana o false si pasa lo contrario
        return matrix[num][dig] == 'G';
    }

    //comprobar toda la combinacion de digitos posibles
    for (int i = 0; i < 4; ++i) {
        int digito = posibles[dig][i];
        //se pasa al jugador dos y se mira si gana(no se cumple la siguiente condicion) o pierde (si se cumple)
        if (calcula_victoria_2(num + digito, digito)) {
            // si el jugador uno Gana se guarda en la matriz de todas las combinaciones
            matrix[num][dig] = 'G';
            return true;
        }
    }
    // si el jugador uno Pierde se guarda en la matriz de todas las combinaciones
    matrix[num][dig] = 'P';
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //inicializar la matriz grande a vacio
    for (int p = 0; p <= 31; ++p) {
        for (int d = 0; d < 10; ++d) {
            matrix[p][d] = ' ';
        }
    }
    int num_casos;
    int pantalla;
    int digito;
    cin >> num_casos;
    for (int i = 0; i < num_casos; ++i) {
        cin >> pantalla;
        cin >> digito;
        //si esta combinacion no se ha calculado, se calcula
        if (matrix[pantalla][digito] == ' '){
            bool gana = calcula_victoria_1(pantalla, digito);
            matrix[pantalla][digito] = (gana) ? 'G' : 'P';
        }
        //mostrara por pantalla el si gana o pierden dependiendo de la combinacion calculada
        cout << ((matrix[pantalla][digito]== 'G') ? "GANA" : "PIERDE") << '\n';
    }
    
    cout.flush();
    return 0;
}