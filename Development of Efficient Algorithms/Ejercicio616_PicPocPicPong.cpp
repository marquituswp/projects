#include <iostream>

using namespace std;

bool casoprueba(){
    int casos;
    cin>>casos;
    //si casos es 0 acabamos programa
    if(casos==0)return false;
    //al principio va a la derecha, asi que izq es false y derecha es true
    bool izq=false,derecha=true;
    //inicializamos puntuacion de cada lado a 0
    int punt_izq=0,punt_der=0;
    while(casos>0){
        //leemos el efecto que hace
        string efecto;
        cin>>efecto;
        //si el efecto es PIC (rebota)
        if(efecto=="PIC"){
            //si iba hacia la derecha, ahora ira hacia la izquierda
            if(derecha==true){
                derecha=false;
                izq=true;
            //si iba hacia la izquierda, ahora ira hacia la derecha
            }else{
                derecha=true;
                izq=false;
            }
        //si el efecto es PONG (mete gol)
        }else if(efecto=="PONG!"){
            //si iba hacia la derecha, ha puntuado la izquieda (se le suma 1)
            if(derecha==true){
                punt_izq++;
            //si iba hacia la izquierda, ha puntuado la derecha (se le suma 1)
            }else{
                punt_der++;
            }
        }
        casos--;
    }
    //mostramos puntuaciones
    cout<<punt_izq<<" "<<punt_der<<endl;

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(casoprueba());

    cout.flush();
    return 0;
}