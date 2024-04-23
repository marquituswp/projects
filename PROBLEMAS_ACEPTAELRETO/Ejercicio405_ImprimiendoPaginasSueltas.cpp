#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num1,num2,aux;
    //mientras haya entrada y sea distinta a 0
    while(scanf("%d",&num1)==1&&num1!=0){
        //inicializamos booleano de rango a false
        bool rango=false;
        //inicializamos valor auxiliar a valor leido
        aux=num1;
        //mientras haya entrada
        while(scanf("%d",&num2)==1){
            //si el segundo numero leido menos 1 es igual al auxiliar, rango es true
            if(num2-1==aux){
                rango=true;
            }else{
                //si no, miramos si rango es true
                if(rango==true){
                    //si es true mostramos el rango desde el primer numero hasta el auxiliar
                    cout<<num1<<'-'<<aux;
                    //Actualizamos primer valor al segundo valor
                    num1=num2;
                    //si el segundo valor es 0 mostramos una coma
                    if(num2!=0){
                        cout<<',';
                    }
                    rango=false;
                }else{
                    //si no, no hay rango y solo mostramos el valor auxiliar
                    cout<<aux;
                    //Actualizamos primer valor al segundo valor
                    num1=num2;
                    //si el segundo valor es 0 mostramos una coma
                    if(num2!=0){
                        cout<<',';
                    }
                }
            }
            //Actualizamos valor auxiliar
            aux=num2;
            //si el numero es 0 salimos del bucle
            if(num2==0) break;
            
        }
        //mostramos un salto de linea
        cout<<endl;
    }

    cout.flush();
    return 0;
}