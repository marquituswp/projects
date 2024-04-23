#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int casos;
    cin>>casos;
    while(casos>0){
        int choco,vain;
        cin>>choco>>vain;
        //creamos dos arrays, uno de caracteres y otro equivalente que seran 1s y 0s de tamaño suma de los dos numeros
        char bolas[(choco+vain)];
        int equ[(choco+vain)];
        //creamos un array igual a CV
        char valor[3]="CV";
        //ponemos cantidad de choco que tenemos que equivale a 0s
        for(int i=0;i<choco;i++){
            equ[i]=0;
        }
        //ponemos cantidad de vainilla que tenemos que equivale a 1s
        for(int i=choco;i<vain+choco;i++){
            equ[i]=1;
        }
        //recorremos todo el array una vez y mostramos el primer valor que sera todo 0s seguido de todo1s
        for(int i=0;i<choco+vain;i++){
            //si equ es 0 el valor[0] es C, si es 1 el valor[1] es V
                bolas[i]=valor[equ[i]];
                cout<<bolas[i];
            }
        //mientras se pueda intercambiar una  C con una V seguiremos mostrando
        while(next_permutation(equ,equ+choco+vain)){
            cout<<' ';
            //mostramos otra vez los valores, ahora el array equ ha permutado un 1 con un 0
            for(int i=0;i<choco+vain;i++){
                //para mostrar ponemos en el array de caracteres el caracter que equivale al valor del array equ
                //si equ es 0 el valor[0] es C, si es 1 el valor[1] es V
                bolas[i]=valor[equ[i]];
                cout<<bolas[i];
            }
        }
            
        cout<<endl;
        

        casos--;
        
    }

    cout.flush();
    return 0;
}