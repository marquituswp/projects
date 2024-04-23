#include <iostream>
#include <cmath>

using namespace std;

//funcion que eleva un numero a otro
//algoritmo recursivo, reducimos el valor a elevar y devolvemos el valor elevado a un numero menos por el valor 
int Elevar(int n,int x){
    //valor al que se hara modulo
    int k=46337;
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

//funcion que devuelve el numero de Bernoulli
int Bernoulli(int n,int p){
    int resultado=0;
    for(int i=1;i<=n;i++){
        //el resultado es la suma de cada numero elevado a p
        resultado=Elevar(p,i)+resultado;
    }
    return resultado;
}


int main (){
    
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int n,p;
    cin>>n;
    cin>>p;
    while(n!=0 && p!=0){
        //mientras que no sean 0 vamos mostrando el Bernoulli de cada numero modulo 46337
        cout<<Bernoulli(n,p)%46337<<"\n";
        cin>>n;
        cin>>p;
    }

    cout.flush();
    return 0;
}