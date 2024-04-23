#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

bool casoprueba(){
    if(!cin) return false;
    float puntos[7];
    float z;
    cin>>z;
    if(!cin) return false;
    puntos[0]=z;
    for(int i=1;i<7;i++){
        //leemos los puntos de cada categoria y los añadimos al array
        cin>>z;
        puntos[i]=z;
    }
    //ordenamos los puntos de menor a mayor
    sort(puntos,puntos+7);
    float puntuacion;
    //la puntuacion sera la suma de los puntos de la posicion 2,3 y 4 de la array y que se quitan las dos puntuacions mas bajas y las dos mas altas
    puntuacion=(puntos[2]+puntos[3]+puntos[4])*2;
    cout<<puntuacion<<endl;

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(casoprueba());

    cout.flush();
    return 0;
}