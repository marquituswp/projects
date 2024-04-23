#include <iostream>

using namespace std;

bool casoprueba(){
    int casos;
    cin>>casos;
    while(casos>0){
        int num_paginas;
        cin>>num_paginas;
        int n;
        cin>>n;
        //inicializamos numero maximo al primero que leemos
        int num_maximo=n;
        //inicializamos salto maximo a -300000, un numero muy bajo
        int salto_maximo=-300000;
        int aux;
        //recorremos el numero de paginas
        for(int i=1;i<num_paginas;i++){
            cin>>n;
            //creamos valor auxiliar igual al numero maximo menos el nuevo valor leido
            aux=num_maximo-n;
            //si aux es mayor al salto maximo, actualizamos salto maximo
            if(aux>salto_maximo){
                salto_maximo=aux;
            }
            //si el numero leido es mayor al numero maximo, actualizamos numero maximo
            if(n>num_maximo){
                num_maximo=n;
            }
        }
        //mostramos el salto maximo
        cout<<salto_maximo<<endl;


        casos--;
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