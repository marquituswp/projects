#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int casos;
    cin>>casos;
    while(casos>0){
        string carta,palo;
        int paloC=0,paloD=0,paloP=0,paloT=0;
        int puntos=0;
        //durante las trece cartas
        for(int i=0;i<13;i++){
            cin>>carta;
            cin>>palo;
            //sumamos los puntos correspondientes dependiendo del valor de la carta
            if(carta=="A") {puntos+=4;}
            else if(carta=="K") {puntos+=3;}
            else if(carta=="Q") {puntos+=2;}
            else if(carta=="J") {puntos++;}
            //sumamos cuantos palos de cada ha habido
            if(palo=="C") {paloC++;}
            else if(palo=="D") {paloD++;}
            else if(palo=="P") {paloP++;}
            else if(palo=="T") {paloT++;}

        }
        //sumamos puntuacion correspondiente segun numero de palos que ha habido de cada
        if(paloC==2){
            puntos++;
        }else if(paloC==1){
            puntos+=2;
        }else if(paloC==0){
            puntos+=3;
        }
        if(paloD==2){
            puntos++;
        }else if(paloD==1){
            puntos+=2;
        }else if(paloD==0){
            puntos+=3;
        }
        if(paloP==2){
            puntos++;
        }else if(paloP==1){
            puntos+=2;
        }else if(paloP==0){
            puntos+=3;
        }
        if(paloT==2){
            puntos++;
        }else if(paloT==1){
            puntos+=2;
        }else if(paloT==0){
            puntos+=3;
        }
        //mostramos la puntuacion total final
        cout<<puntos<<endl;

        casos--;
    }


    cout.flush();
    return 0;
}