#include <iostream>
#include <bits/stdc++.h>
using namespace std;


struct state
{
    int t1;
    bool operator<(const state &other)const{ return t1>other.t1; }
};

int main()
{
    int n,t_max;
    //mientras se pueda leer una entrada y los valore no sean 0
    while(scanf("%d%d",&n,&t_max)==2 && (n!=0 || t_max!=0))
    {
        //creamos dos arrays donde arr1 sera el instante de tiempo que llega a hacer uso del microondas
        //y arr2 es el tiempo total que se utilitza
        int arr1[n],arr2[n];
        for(int i=0; i<n;i++){
            cin>>arr1[i]>>arr2[i];
        } 
        //inicializamos variables inferior a 0 y superior y resultado a numero de gente que usara el microondas
        int inf = 0, sup = n,res=n;
        //mientras que la diferencia entre el valor superior e inferior no sea 1 (cuando sea uno sabremos cuantos microondas usar)
        while(sup-inf > 1){
            //creamos una cola de prioridad
           priority_queue<state> PQ;
           state s;
           bool solve = true;
           //creamos valor medio
           int mid = (inf+sup)/2;
           //bucle mientras i sea menor a numero personas y solve sea true (ha acabado o no)
           for(int i=0; i<n && solve;i++)
           {
                //si estamos en la primera mitad
               if(i<mid){ 
                //metemos en la cola de prioridad la suma de los dos arrays
                    s.t1=arr1[i]+arr2[i]; 
                    PQ.push(s); 
                }
                //si estamos en la segunda mitad
               else {
                //Creamos un state auxiliar que se inicializa al primer valor de la cola de prioridad
                   state aux = PQ.top();
                   //si el primer valor menos el instante de tiempo que llega la persona es mayor al tiempo maximo, solve es falso
                   if(aux.t1-arr1[i]>t_max){
                        solve=false;
                   } 
                   //si el primer valor es menor al instante de tiempo que llega la persona
                   else if(aux.t1<arr1[i]){
                    //sacamos el valor de la cola de prioridad y metemos el nuevo
                       PQ.pop();
                       aux.t1=arr1[i]+arr2[i];
                       PQ.push(aux);
                   }
                   //si el primer valor es mayor al instante de tiempo que llega la persona
                   else{
                    //sacamos el valor de la cola de prioridad y metemos el valor + el tiempo que tarda
                        PQ.pop();
                        aux.t1+=arr2[i];
                        PQ.push(aux);
                       }
               }
           }
           //si solve es falso, ahora el valor inferior sera el valor medio
           if(!solve){
                inf=mid;
           } 
           //si no el valor superior sera el valor medio y el resultado tambien
           else{ 
                sup=mid; res=mid;
            }
        }
        //mostramos el resultado
        cout<<res<<endl;
    }
    return 0;
}