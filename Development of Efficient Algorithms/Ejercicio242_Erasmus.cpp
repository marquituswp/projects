#include <iostream>

using namespace std;

//funcion que devuelve el numero sobre 2 
//(n)
//(2)
long long numerosobre2(long long n){
    return ((n*(n-1))/2);
}

bool casoprueba(){
    int num_paises;
    cin>>num_paises;
    if(num_paises==0)return false;
    long long total=0,resta=0;
    if(num_paises==1){
        //si solo hay un pais hay que leer la entrada igualmente antes de mostrara el 0
        cin>>total;
        cout<<total*0<<endl;
    }
    if(num_paises!=1){
        long long z;
        for(int i=0;i<num_paises;i++){
            //leemos la entrada
            cin>>z;
            //sumamos al total
            total+=z;
            //la resta es el total de cada numero sobre 2 (parejas del mismo pais)
            resta+=numerosobre2(z);
        }
        //sacamos el total sobre 2 (todas las posibles parejas)
        total=numerosobre2(total); 
        //restamos al total la resta y la mostramos
        cout<<(total-resta)<<endl;       
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