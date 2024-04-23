#include <iostream>

using namespace std;

bool casoprueba(){
    long long num_gastos=0;
    cin>>num_gastos;
    if(num_gastos==0)return false;
    long long gasto,total;
    total=0;
    //durante todo el numero de gastos que ha habido
    for(long long i=0;i<num_gastos;i++){
        //sumamos el gasto leido al total modulo 10^9
        cin>>gasto;
        total+=gasto%1000000000;
    }
    //mostramos el total
    cout<<total<<endl;


    return true;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(casoprueba());

    cout.flush();
    return 0;
}