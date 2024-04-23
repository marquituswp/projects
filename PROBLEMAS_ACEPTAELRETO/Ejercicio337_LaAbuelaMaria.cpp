#include <iostream>
#include <cmath>

using namespace std;

bool casoprueba(){
    int casos;
    //creamos dos arrays uno para los dientes de arriba y otro para los de abajo
    int dientes_sup[6]={0};
    int dientes_inf[6]={0};
    int n=0;
    cin>>casos;
    while (casos>0){
        bool encajan=true;
        //metemos el valor de los dientes de arriba
        for(int i=0;i<6;i++){
            cin>>n;
            dientes_sup[i]=n;
        }
        //metemos el valor de los dientes de abajo
        for(int i=0;i<6;i++){
            cin>>n;
            dientes_inf[i]=n;
        }
        int dif1,dif2 =0;
        for(int i=0;i<5;i++){
            //miramos la diferencia que hay con los dos dientes superiores e inferiores consecutivos
            dif1=abs(dientes_sup[i]-dientes_sup[i+1]);
            dif2=abs(dientes_inf[i]-dientes_inf[i+1]);
            //si la diferencia de arriba y abajo no es la misma no encajan y salimos del bucle
            if(dif1!=dif2){
                encajan=false;
                break;
            }
        }
        //si no encajan mostramos NO y si encajan mostramos SI
        if(encajan==false){
            cout<<"NO"<<endl;
        }else{
            cout<<"SI"<<endl;
        }
        casos--;
    }
    return false;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(casoprueba());

    cout.flush();
    return 0;
}