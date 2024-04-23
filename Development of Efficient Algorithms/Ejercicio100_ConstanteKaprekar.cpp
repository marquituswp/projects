#include <algorithm>
#include <functional>
#include <array>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


// funcion para convertir el entero en string
string convertint (int n){
    stringstream ss;
    ss<<n;
    string m = ss.str();
    while(m.length()<4){
        m = '0'+ m;
    }
    return m;
}

// funcion para ordenar el string de menos a mas
string ordenarmenosmas (string n){
    sort(n.begin(), n.end());
    return n;
}

// funcion para ordenar el string de mas a menos
string ordenarmasmenos (string n){
    sort(n.begin(),n.end(),greater<int>());
    return n;
}

//funcion para restar los dos numeros convertidos a string
int evaluar(string n, string z){
    int resta;
    int mayor=stoi(n);
    int menor=stoi(z);
    resta = mayor-menor;
    return resta;
}


int main(){
    int n;
    int casos;
    int iteraciones = 0;
    cin>>casos;
    for(int i=0;i<casos;i++){
        cin>>n;
        iteraciones=0;
        if (n%1111 == 0){
            cout << 8;cout<<"\n";
        }
        else{
            //buclo de los numeros restados ordenados de mas a menos y menos a mas hasta llegar a la constante de kaprekar
            while (n!=6174){
                n=evaluar(ordenarmasmenos(convertint(n)),ordenarmenosmas(convertint(n)));
                //contar iteraciones que realizamos hasta llegar a la constante
                iteraciones++;
            }
            cout << iteraciones;
            cout<<"\n";
        }

    }
return 0;
}