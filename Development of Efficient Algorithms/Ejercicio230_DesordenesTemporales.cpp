#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

//funcion que unira dos mitades que estaran ordenadas
long long Merge(long long edades[], long long edades_aux[], long long valor0, long long valor_medio, long long valor1)
{
    long long k = valor0, i = valor0, j = valor_medio + 1;
    long long total = 0;
 
    while (i <= valor_medio && j <= valor1)
    {
        if (edades[i] <= edades[j]) {
            edades_aux[k++] = edades[i++];
        }
        else {
            edades_aux[k++] = edades[j++];
            //actualizamos valor del total sumandole la diferencia de posiciones que esta de la edad mas pequeña
            total += (valor_medio - i + 1);    
        }
    }
 

    while (i <= valor_medio) {
        edades_aux[k++] = edades[i++];
    }

    for (long long i = valor0; i <= valor1; i++) {
        edades[i] = edades_aux[i];
    }
 
    return total;
}
 
//funcion que ordenara las edades 
long long MergeSort(long long edades[], long long edades_aux[], long long valor0, long long valor1)
{

    if (valor1 <= valor0) {       
        return 0;
    }
 
    long long valor_medio = (valor0 + ((valor1 - valor0) >> 1));
    long long total = 0;
 
    //ordenamos primera mitad
    total += MergeSort(edades, edades_aux, valor0, valor_medio);
 
    //ordenamos segunda mitad
    total += MergeSort(edades, edades_aux, valor_medio + 1, valor1);
 
    //juntamos lo ordenado
    total += Merge(edades, edades_aux, valor0, valor_medio, valor1);
    
    //el total sera el numero de desordenes temporales totales que habran salido de la funcion merge.
    return total;
}


bool casoprueba(){
    long long casos;
    long long n;
    cin>>casos;
    //si no hay casos acabamos programa
    if(casos==0){
        return false;
    }
    //creamos dos arrays de longitud el numero de casos
    long long edades[casos-1];
    long long edades_aux[casos-1];
    for(long long i=0;i<casos;i++){
        //leemos la entrada y la metemos en los arrays
        cin>>n;
        edades[i]=n;
        edades_aux[i]=edades[i];
    }
    
    //devolver cantidad de desordenes temporales de la poblacion
    cout<<MergeSort(edades,edades_aux,0,casos-1)<<endl;
    return true;
       
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(casoprueba());
    
    cout.flush();
    return 0;
}