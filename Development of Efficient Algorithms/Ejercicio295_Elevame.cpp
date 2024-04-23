#include <iostream>
#include <cmath>

using namespace std;

//funcion que eleva un numero a otro
//algoritmo recursivo, reducimos el valor a elevar y devolvemos el valor elevado a un numero menos por el valor 
int Elevar(int n,int x){
    //valor al que se hara modulo
    int k=31543;
    int xmodk;
    //si el numero es 0 devolvemos uno ya que cualquier numero elevado a 0 es 1
    if(n==0){
        return 1;
    }
    //si el numero es par llamamos a elevar otra vez elevado a la mitad
    if(n%2==0){
        xmodk=(Elevar(n/2,x))%k;
        //devolvemos el valor elevado por el valor elevado
        return (xmodk*xmodk)%k;
    }else{
        //si es impar llamamos a elevarlo por uno menos
        xmodk=(Elevar(n-1,x))%k;
        //devolvemos el valor elevado por el numero 
        return (xmodk*(x%k))%k;
    }
}



int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    int x;
    cin>>x;
    cin>>n;
    while (x!=0 || n!=0){
        //mientras no sean 0 elevamos el numero
        cout<<Elevar(n,x)<<"\n";
        cin>>x;
        cin>>n;
    }

    return 0;
}