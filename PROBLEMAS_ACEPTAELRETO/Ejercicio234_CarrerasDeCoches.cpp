#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;



bool casoprueba(){
    int pruebas,pilas,voltaje;
    int valores [100000];
    cin>>pruebas;
    if(pruebas == 0){
        return false;
    }
    while(pruebas>0){
        cin>>pilas>>voltaje;
        int n=0;

        for(int i=0;i<pilas;i++){
            //leemos los valores de las pilas y los metemos en el array
            cin>>n;
            valores[i]=n;
        }
        //ordenamos el valor de las pilas de menor a mayor
        sort(valores,valores+pilas);
        int coches=0;
        //recorremos todas las pilas
        for(int i=0,j=pilas-1;i<j;){
            //si la suma de las dos pilas es superior al voltaje correra un coche (sumamos uno a coches)
            if ((valores[i]+valores[j])>=voltaje){
                coches++;
                //movemos punteros
                i++;
                j--;
            }else{
                //si no movemos solo el puntero de la izquierda
                i++;
            }
            if(i==j){
                //si los punteros coinciden salimos del bucle
                break;
            }
        }
        //mostramos el numero de coches que puede correr
        cout<<coches<<"\n";
        pruebas--;
    }

    return false;
}





int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    while(casoprueba());

    cout.flush();
    return 0;
}