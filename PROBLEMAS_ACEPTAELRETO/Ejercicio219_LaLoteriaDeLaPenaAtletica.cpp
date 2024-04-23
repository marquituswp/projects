#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int casos;
    cin>>casos;
    while(casos>0){
        int decimos,numero;
        int comprar=0;
        cin>>decimos;
        //si el decimo es par lo compramos
        for(int i=0;i<decimos;i++){
            cin>>numero;
            if(numero%2==0){
                comprar++;
            }
        }
        //mostramos cuandos decimos pares hemos podido comprar
        cout<<comprar<<endl;


        casos--;
    }

    cout.flush();
    return 0;
}