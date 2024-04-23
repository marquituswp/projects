#include <iostream>

using namespace std;

//funcion que devuelve el minimo comun multiplo
int maximocomundivisor(int a, int b) {
    if(b == 0) return a;
    return maximocomundivisor(b, a%b);
}

bool casoprueba(){
    long num_planetas=0;
    cin>>num_planetas;
    if(num_planetas==0)return false;
    long n;
    long mcm=1;
    for(long i=0;i<num_planetas;i++){
        cin>>n;
        //sacamos el minimo comun multiplo total de todos los planetas que hay
        mcm=(mcm*n)/maximocomundivisor(mcm,n);
    }
    cout<<mcm<<endl;
    return true;
}
    



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(casoprueba());

    cout.flush();
    return 0;
}