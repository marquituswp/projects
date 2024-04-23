#include <iostream>

using namespace std;

bool casoprueba(){
    int c,p,t;
    cin>>c>>p>>t;
    //si los valores de entrada son 0 acabamos el programa
    if(c==0 && p==0 && t==0) return false;
    //inicializamos movimiento a posicion jugador + tirada dado
    int mov=p+t;
    //si el movimiento es mayor a cantidad casillas del tablero, habra que echarse para atras el numero de movimientos restantes
    if(mov>c){
        //nos distanciamos de c el numero de mov que nos sobraban cuando hemos llegado
        mov=mov-c;
        mov=c-mov;
    }
    //mostramos posicion en la que ha quedado la ficha al final
    cout<<mov<<endl;

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(casoprueba());

    cout.flush();
    return 0;
}