#include <iostream>
#include <math.h>
#include <set>


using namespace std;

bool casoprueba(){
    int n,m;
    int i=0;
    //registro de que numeros han salido
    set<int> han_salido;
    cin>>n;
    if(n==1){
        // si el numero es 1 sera cubifinito
        cout<<n<<" -> cubifinito."<<endl;
        return true;
    }else if(n==0){
        //si el numero es 0 acabamos programa
        return false;
    }
    int total=0;
    bool seguir=true;
    cout<<n<<" - ";
    han_salido.insert(n);
    m=n;
    while(seguir){
        while(m>0){
            //calculamos el total de todos los digitos del numero al cubo
            total+=pow(m%10,3);
            m=m/10;
        }
        //buscamos en el registro si el numero resultante ya ha salidos
        auto pos=han_salido.find(total);
        //si el numero resultante es 1 el numero es cubifinito
        if(total==1){
            cout<<total<<" -> cubifinito."<<endl;
            break;
        //si no miramos si ha salido. Si es asi el numero no es cubifinito
        }else if (pos!=han_salido.end()){
            cout<<total<<" -> no cubifinito."<<endl;
            break;
        }
        //si no ha salido lo añadimos al registro y actualizamos valores
        han_salido.insert(total);

        m=total;
        cout<<total<<" - ";
        total=0; 
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