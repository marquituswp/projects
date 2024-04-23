#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    while(n>0){
        int z;
        bool mayor6=true;
        int avisos=0;
        //durante todos los numeros
        for(int i=0;i<n;i++){
            cin>>z;
            //si el valor leido es menor que 4 y mayor a 6 es true, sumamos uno a aviso
            if(z<=4 && mayor6==true){
                avisos++;
                //ponemos a falso que el valor ha sido mayor a 6
                mayor6=false;
            }
            //si el valor supera 6, ponemos a true que el valor es mayor a 6.
            if(z>6){
                mayor6=true;
            }
            
        }
        //mostramos numero de avisos a realizar
        cout<<avisos<<endl;
        cin>>n;



    }

    cout.flush();
    return 0;
}