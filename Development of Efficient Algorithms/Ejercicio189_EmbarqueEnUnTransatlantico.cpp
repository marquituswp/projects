#include <iostream>
#include <math.h>
#include <algorithm>
#include <map>

using namespace std;



bool casoprueba(){
    
    int num_pasajeros,accion,num_accion;

    cin>>num_pasajeros;
    int pasajeros_aux;
    pasajeros_aux=num_pasajeros;
    //registro de el numero de la cubierta si esta ocupada o no (vale 1 o 0)
    map<int,int> num_cubiertas; 
    int* cubiertas;
    //las cubiertas de los pasajeros
    cubiertas=new int[num_pasajeros];
    //si no hay pasajeros acabaremos el programa
    if (num_pasajeros == 0){
        return false;
    }
    int n;
    //leemos todas las cubiertas
    for(int i=0;i<num_pasajeros;i++){
        cin>>n;
        //la cubierta del pasajero i sera la que hemos leiado
        cubiertas[i]=n;
        //decimos que esa cubierta esta ocupada sumandole uno
        num_cubiertas[n]++;
    }
    cin>>accion;

    //realizamos el numero de acciones indicadas
    while(accion>0){
        //leemos el tipo de accion
        string tipo_accion;
        cin>>tipo_accion;
        if(tipo_accion=="EMBARQUE"){
            //si hacemos un embarque leemos que cubierta es
            cin>>num_accion;
            int desplazamiento=0;
            //si esa cubierta esta ocupada, la ponemos a 0 (indicar que ya no esta ocupada)
            if(num_cubiertas[num_accion]>0){
                num_cubiertas[num_accion]=0;
                for(int i=0;i<num_pasajeros;i++){
                    //recorremos todos los pasajeros mirando si estan en la cubierta que debe embarcar
                    if(cubiertas[i]==num_accion){
                        //si esta sumamos uno a desplazamiento y restamos uno al numero de pasajeros
                        desplazamiento++;
                        pasajeros_aux--;
                          
                    }else{
                        //si no esta, hay que actualizar el array, desplazando los valores
                        cubiertas[(i)-desplazamiento]=cubiertas[i];
                    }
                }
            }
            //reiniciamos valores
            desplazamiento=0;
            num_pasajeros=pasajeros_aux;
            //mostramos pasajeros restantes
            cout<<pasajeros_aux<<endl;
        }
        else{
            //si nos piden CONSULTA mostramos la cubierta en la que esta la persona num_accion-1
            cin>>num_accion;
            cout<<cubiertas[num_accion-1]<<endl;
        }
        //leemos el salto de linea
        getline(cin,tipo_accion);
        accion--;
    }
    //cuando acaba un caso mostramos *
    cout<<"*"<<endl;
    delete[] cubiertas;
    return true;
}




int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(casoprueba());
   
    cout.flush();
    return 0;
}