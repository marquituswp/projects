#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int ini,fin,n;
    cin>>ini>>fin>>n;
    while(ini!=0 && fin!=0 && n!=0){
        int k;
        cin>>k;
        //inicializamos variable >= a inicial y menor a final mas 1
        int mayor_igual=ini;
        int menor=fin+1;
        //mientras la entrada sea mayor a 0 realizamos el programa
        while(k>0){
            int z;
            cin>>z;
            //si el valor leido esta entre el mayor igual y el menor actualizamos valores
            if(z<menor && z>mayor_igual){
                //si el valor leido es mayor al que buscamos
                if(n<z){
                    //ahora menor sera el valor leido
                    menor=z;
                }else if(n>=z){
                    //si no ahora mayor_igual sera el valor leido
                    mayor_igual=z;
                }
            }
            k--;
        }
        //si al acabar, mayor_igual +1 es igual a menor querra decir que ha conseguido averiguar el valor
        if(mayor_igual+1==menor){
            cout<<"LO SABE"<<endl;
        }else{
            //sino no lo puede saber
            cout<<"NO LO SABE"<<endl;
        }


        cin>>ini>>fin>>n;
    }

    cout.flush();
    return 0;
}