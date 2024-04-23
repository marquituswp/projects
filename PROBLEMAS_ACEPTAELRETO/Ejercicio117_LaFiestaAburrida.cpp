#include <iostream>
#include <sstream>

using namespace std;

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int casos;
    cin>>casos;
    string frase;
    //getline para leer el salto de linea
    getline(cin,frase);
    while (casos>0){
        //leemos la frase
        getline(cin,frase);
        //separar el nombre de la frase 
        //creamos un stringstream de la frase
        stringstream sstream(frase);
        //string del nombre
        string name;
        //cual es el separados de las dos palabras
        const char sep = ' ';
        //obtenemos el nombre de la frase indicando el separados
        getline(sstream,name,sep);
        getline(sstream,name,sep);
        //mostrar la salida
        cout<<"Hola, "<<name<<"."<<endl;


        casos--;
    }


    cout.flush();
    return 0;
}