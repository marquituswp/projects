#include <iostream>

using namespace std;

bool casoprueba(){
    long long casos;
    cin>>casos;
    if(casos==0)return false;
    while(casos>0){
        long long longitud,antenas;
        cin>>longitud;
        cin>>antenas;
        //inicializamos booleano de cubierto todo el tunel a false
        bool cubierto=false;
        long long total,j=0;
        long long distancia;
        long long ini,fin,cobertura,ini2,fin2=0;
        //si solo hay una antena
        if(antenas==1){
            cin>>distancia;
            cin>>cobertura;
            //calculamos distancia de cobertura inicial y final de la antena 1
            ini=distancia-cobertura;
            fin=distancia+cobertura;
            //si el rango esta entre 0 y longitud total del metro cubre todo el tunel
            if(ini<=0 && fin>=longitud){
                cubierto=true;
            }
        }else{
            cin>>distancia;
            cin>>cobertura;
            //calculamos distancia de cobertura inicial y final de la antena 1
            ini=distancia-cobertura;
            fin=distancia+cobertura; 
            //durante todo el numero de antenas*2 (las antenas van de dos en dos)
            for(long long i=2;i<antenas*2;i+=2){
                cin>>distancia;
                cin>>cobertura;
                //calculamos distancia de cobertura inicial y final de la antena 2
                ini2=distancia-cobertura;
                fin2=distancia+cobertura; 
                //si la inicial de la antena 2 empieza (es menor) a la final de la antena 1
                if(ini2<fin){
                    //si la inicial de la antena 2 es menor a la inicial de la antena 1, ahora la inicial sera la mas baja
                    if(ini2<ini){
                        ini=ini2;
                    }
                    //si la final de la antena 2 es mayor a la final de la antena 1, ahora la final sera la mas alta
                    if(fin2>fin){
                    fin=fin2;
                    }
                }
                
            }
            //si al final inicial es menor a 0 y final es mayor o igual a la longitud del tunel, lo cubrira entero
            if(ini<=0 && fin>=longitud){
                cubierto=true;
            }
        }
        //si lo cubre mostramos SI, sino mostramos NO
        if(cubierto==true){
            cout<<"SI"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        casos--;
    }

    return false;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(casoprueba());

    cout.flush();
    return 0;
}