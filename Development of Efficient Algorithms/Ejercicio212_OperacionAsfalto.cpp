#include <iostream>

using namespace std;

int main(){

    int n_calles,intersecciones;

    cin>>n_calles;

    while(n_calles!=0){
        cin>>intersecciones;
        //array de numero de intersecciones tiene cada valor
        int valores[50];
        //inicializamos los valores a 0
        for(int i=0; i<50;i++){
            valores[i]=0;
        }
        int I1,I2,impares;
        for(int i=0;i<n_calles;i++){
            cin>>I1;
            cin>>I2;
            //sumamos uno al valor de intercciones
            valores[I1-1]++;
            valores[I2-1]++;
        }
        //recorremos todas las intersecciones
        for(int i=0;i<intersecciones;i++){
            //si el valor es impar sumamos uno a impar
            if(valores[i]%2!=0){
                impares++;
            }
            //si hay mas de 3 impares salimos del bucle
            if(impares>=3){
                break;
            }
        }
        //si hay 3 impares sera imposible asfaltar por el teorema de Konigsberg
        if(impares>=3){
                cout<<"NO"<<"\n";
            }else{
                cout<<"SI"<<"\n";
            }
        impares=0;
        cin>>n_calles;
    }

    return 0;
}