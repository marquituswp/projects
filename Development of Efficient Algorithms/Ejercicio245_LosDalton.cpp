#include <iostream>

using namespace std;

bool casoprueba(){
    int n;
    cin>>n;
    long long y;
    long long z;
    if(n==0)return false;
    //variables de si estan ordenados de mayor a menor o al reves
    int x=0;
    int x1=0;
    cin>>z;
    for(int i=1;i<n;i++){
        cin>>y;
        //si el primer numero es mayor al siguiente sumamos a variable ordenados de mayor a menor
        if(z>y){
            x++;
        //si el primer numero es menor al siguiente sumamos a variable ordenados de menor a mayor
        }else if (z<y){
            x1++;
        }
        
        //actualizamos primer numero como el siguiente
        z=y;
    }
    
    //si alguna de las dos variables es igual a numero de hermanos querra decir que todos estan ordenados de mayor a menor o menora a mayor y son los DALTON
    if(x==n-1 || x1==n-1){
        cout<<"DALTON"<<endl;
    }else{
    //si no son DESCONOCIDOS
        cout<<"DESCONOCIDOS"<<endl;
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(casoprueba());

    cout.flush();
    return 0;
}