#include <iostream>
#include <map>

using namespace std;


int main(){
   int N,M;
   //mientras haya entrada
    while(scanf("%d %d",&N,&M)==2){
        //creamos dos mapas, uno con las tallas que se necesitan y otro con las tallas que hay
        map<int,int> t_necesita,t_hay;
        int aux;
        //inicializamos el mapa de las tallas que se necesitan
        for(int i=0; i<N;i++) { 
            cin>>aux; 
            t_necesita[aux]++; 
        }
        //inicializamos el mapa de las tallas que hay
        for(int i=0; i<M;i++) { 
            cin>>aux; 
            t_hay[aux]++; 
        }
        //inicializamos numero de camisetas a comprar a 0
        int comprar = 0;
        //recorremos todos los valores de tallas posibles
        for(int i=1; i<=100;i++){
            //creamos variable puede llevarla con el minimo entre las tallas que hay y la que necesita
            int puede = min(t_necesita[i], t_hay[i]);
            //se quita a las tallas que hay y necesita el valor de puede
            t_necesita[i]-=puede;
            t_hay[i]-=puede;
            //si aun hay tallas que se necesitan
            if (t_necesita[i] > 0) {
                //miramos si hay tallas de una talla superior
                puede = min(t_necesita[i], t_hay[i+1]);
                //Actualizamos valor de tallas que hay y que necesitan
                t_necesita[i]-=puede;
                t_hay[i+1]-=puede;
            }
            //al final compraremos las tallas restantes que aun se necesitan
            comprar += t_necesita[i];
        }
        //mostramos el valor de camisetas a comprar
        cout<<comprar<<endl;
    }
    return 0;
}
