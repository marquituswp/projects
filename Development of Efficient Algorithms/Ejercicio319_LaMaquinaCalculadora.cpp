#include <iostream>
#include <math.h>
#include <queue>

using namespace std;

bool casoprueba(){
    if(!cin)return false;
    int ini,fin=0;
    cin>>ini;
    cin>>fin;
    //mientras haya entrada continuaremos, si no acabamos el programa
    if(!cin)return false;
    //creamos una cola
    queue<int> cola;
    //el valor inicial de la cola es el inicial de la entrada
    cola.push(ini);
    //creamos una segunda fila en la cola con un valor inicial de -1 para simbolizar la siguiente fila
    cola.push(-1);
    //creamos un array booleano de visitados inicializado en false
    bool visitados[10005]={false};
    int pasos=0;
    //si el valor inicial y final es el mismo mostramos un 0
    if(ini==fin){
        cout<<0<<endl;
    }else{
        //si no mientras el tamaño de la cola sea mayor que 1 (basicamente siempre)
        while(cola.size()>1){
            //sacamos el primer valor de la cola
            int n=cola.front();
            cola.pop();
            //si el primer valor es el valor nulo, sumamos un paso y añades el valor nulo otra vez al final
            if(n==-1){
                pasos++;
                cola.push(-1);
            //si no es valor nulo
            }else{
                //creamos variable de sumar uno, multiplicar 2 y dividir 3 (las 3 opciones que se tienen) y se calculan en modulo 10000
                int sumauno=(n+1)%10000;
                int multdos=(n*2)%10000;
                int div3=(n/3)%10000;
                //si alguno de los 3 resultados es el valor final salimos del bucle
                if(sumauno==fin)break;
                if(multdos==fin)break;
                if(div3==fin)break;
                //si ninguno de los tres valores habia salido aun, se añaden al array de visitados y se mete al final de la cola
                if(!visitados[sumauno]){
                    visitados[sumauno]=true;
                    cola.push(sumauno);
                }
                if(!visitados[multdos]){
                    visitados[multdos]=true;
                    cola.push(multdos);
                }
                if(!visitados[div3]){
                    visitados[div3]=true;
                    cola.push(div3);
                }
            }
        }
        //al final mostramos el numero de pasos +1
        cout<<pasos+1<<endl;
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