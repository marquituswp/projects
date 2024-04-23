#include <iostream>
#include <map>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string categ,equipolocal,equipovisit,ganador;
    while(cin>>categ){
        //leemos mientras haya algo que leer
        map<string,int> Registro;
        // registro de nombre equipo y su puntuacion
        int sets1,sets2,partidos=0,actual=-1;
        bool empate=false;
        //si categoria es fin salimos del bucle
        if(categ=="FIN") break;
        while(1){
            //si no bucle hasta que el equipo local sea fin que saldremos del bucle
            cin>>equipolocal;
            if(equipolocal=="FIN") break;
            cin>>sets1>>equipovisit>>sets2;
            //si el primer set es mayor, el equipo local ha ganado. 
            if(sets1>sets2){
                //actualizamos regitro de partidos y puntuacion
                Registro[equipolocal]+=2;
                Registro[equipovisit]+=1;
            }else if(sets2>sets1){
                Registro[equipovisit]+=2;
                Registro[equipolocal]+=1;
            }
            partidos++;
        }   
        map<string,int>::iterator it=Registro.begin();
        //iteramos a traves del registro para encontrar el ganador o si hay empate
        for(;it!=Registro.end();it++){
            //si la puntuacion de un equipo es mayor a la puntuacion maxima actual actualizamos valores
            if(it->second>actual){
                actual=it->second;
                ganador=it->first;
                //empate sera falso
                empate=false;
            //si la puntuacion del equipo es igual a la puntuacion maxima actual ponemos a true empate
            }else if(it->second==actual){
                empate=true;
            }
        }
        //saldremos del bucle con un valor de empate
        if(empate==false){
            //si no hay empate mostraremos el ganador y el numero de partidos que no se han jugado
            cout<<ganador<<" "<<(Registro.size()*(Registro.size()-1))-partidos<<endl;
        }else{
            //si hay empate mostraremos EMPATE y el numero de partidos que no se han jugado
            cout<<"EMPATE "<<(Registro.size()*(Registro.size()-1))-partidos<<endl;
        }
        //el numero de partidos que no se han jugado es igual al numero maximo de partidos que se juagarian menos los partidos que se han jugado
        //Numero partidos maximos es igual al numero de equipos que hay por el numero de equipos-1.


    }

    cout.flush();
    return 0;
}