#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin>>c;
    while(c>0){
        //si el lado de la calle es par estara a la derecha, si no a la izquierda
        if(c%2==0){
            cout<<"DERECHA"<<endl;
        }else{
            cout<<"IZQUIERDA"<<endl;
        }
        cin>>c;
    }
    
    cout.flush();
    return 0;
}