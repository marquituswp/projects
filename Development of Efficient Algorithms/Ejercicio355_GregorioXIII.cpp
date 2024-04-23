#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int casos;
    cin>>casos;
    while(casos>0){
        int fecha;
        bool es_bisiesto=true;
        cin>>fecha;
        //si la fecha es divisible entre 4 puede que sea bisiesto o no
        if(fecha%4==0){
            //si la fecha es divisible entre 100 puede que sea bisiesto o no
            if(fecha%100==0){
                //si la fecha es divisible entre 4,100 y 400, es un año bisiesto
                if(fecha%400==0){
                    es_bisiesto=true;
                }else{
                //si la fecha es divisible entre 4,100 pero no entre 400, no es un año bisiesto
                    es_bisiesto=false;
                }
            //si la fecha es divisible entre 4 pero no entre 100, es un año bisiesto
            }else{
                es_bisiesto=true;
            }
        //si la fecha no es divisible entre 4, no es un año bisiesto
        }else{
            es_bisiesto=false;
        }
        //si es bisiesto mostramos 29 y sino, 28
        if(es_bisiesto){
            cout<<29<<endl;
        }else{
            cout<<28<<endl;
        }


        casos--;
    }


    cout.flush();
    return 0;
}