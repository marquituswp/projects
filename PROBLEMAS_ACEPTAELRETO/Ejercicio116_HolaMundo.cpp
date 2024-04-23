#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int casos;
    cin>>casos;
    while (casos>0){
        //mostrar la frase el numero de veces del valor de casos.
        cout<<"Hola mundo."<<endl;
        casos--;
    }

    cout.flush();
    return 0;
}