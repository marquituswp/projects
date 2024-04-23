#include <iostream>
#include <math.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int casos;
    cin>>casos;
    while(casos>0){
        int n;
        cin>>n;
        //elevamos a 2 numeros entre 0 y 35 (ya que 2^34 > 10^9) para cubrir todos los numeros
        for(int i=0;i<35;i++){
            //si el numero elevado es mayor o igual a numero veces tiene que escribir
            if(pow(2,i)>=n){
                //el minimo numero de fotocopia, recorte y pegado que debera hacer es i.
                cout<<i<<endl;
                break;
            }
        }

        casos--;
    }

    cout.flush();
    return 0;
}