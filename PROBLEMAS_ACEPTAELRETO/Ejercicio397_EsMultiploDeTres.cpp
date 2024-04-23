#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long int casos;
    cin>>casos;
    while(casos>0){
        long long int n;
        cin>>n;
        //si el numero es divisible por 3 o cuando dividimos por tres el resto da 2, es multiplo de 3 y mostramos SI
        if(n%3==0 || n%3==2){
            cout<<"SI"<<endl;
        }else{
        //si no mostramos NO
            cout<<"NO"<<endl;
        }


        casos--;
    }

    cout.flush();
    return 0;
}