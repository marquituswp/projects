#include <iostream>
#include <string>
#include <map>
#include <algorithm> 
#include <vector>

using namespace std;

//creamos una variable global que sera la cantidad de comida
int* cant_comida;

//creamos un hush con el que revisaremos si ya hemos pasado por esta opcion o no
map<int,int> hush;

//funcion para obtener la etiqueta del hush
int get_etiq(int ini, int fin)
{
    return ini * 1000 + fin;
}

int resolver(int ini,int fin){
    //si se han comido todos los cubos devolvemos la cantidad de comida
    if (ini == fin) {
        return cant_comida[ini];
    }
    if (ini > fin) {
        return 0;
    }

    int etiq=get_etiq(ini,fin);
    
    
    auto it=hush.find(etiq);
    if(it!=hush.end()){
        return it->second;
    }

    int comidaA;
    int comidaB;
    //opcion comemos por la izquierda
    {
        int ini1=ini;
        int fin1=fin;
        comidaA=cant_comida[ini1];
        ini1++;
        //come la otra vaca
        if(cant_comida[ini1]>cant_comida[fin1]){
            ini1++;
        }else{
            fin1--;
        }
        //se resuelve con el resultado
        comidaA+=resolver(ini1,fin1);
    }
    
    //opcion comemos por la derecha
    {
        int ini2=ini;
        int fin2=fin;
        comidaB=cant_comida[fin2];
        fin2--;
        //come la otra vaca
        if(cant_comida[ini2]>cant_comida[fin2]){
            ini2++;
        }else{
            fin2--;
        }
        //se resuelve con el resultado
        comidaB+=resolver(ini2,fin2);
    }
    //guardamos el que mas a comido en el hush
    int mayor = max(comidaA,comidaB);
    hush[etiq]=mayor;
    //devoldemos el valor maximo
    return mayor;
}


bool casoprueba(){
    int cubos;
    cin>>cubos;
    if(cubos==0)return false;
    
    for(int i=0;i<cubos;i++){
        int z;
        cin>>z;
        cant_comida[i]=z;
    }
    int ini=0;
    int fin=cubos-1;
    hush.clear();
    int resultado=resolver(ini,fin);
    cout<<resultado<<endl;
    return true;
}

int main(){
    //la  cantidad de comida sera un array de enteros de tamaño 1001
    cant_comida = new int[1001];
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(casoprueba());

    cout.flush();
    return 0;
}