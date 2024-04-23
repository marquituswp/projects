#include <iostream>

using namespace std;


int main(){

    int casos;
    cin>>casos;
    while(casos!=0){
        int gotas=0;
        int minutos=0;
        int resto=0;
        int horas=0;
        cin>>gotas;
        //si no pasamos del minuto mostramos la salida con las gotas en los segundos
        if(gotas<=59){
            //si hay que añadir un 0 o no si el numero es menos a 10
            if(gotas<10){
                cout<<"00"<<":"<<"00"<<":"<<"0"<<gotas<<endl;
            }else{
                cout<<"00"<<":"<<"00"<<":"<<gotas<<endl;
            }
            
        }else if(gotas>=60 && gotas <=3599){
            //si hay mas de un minuto pero menos de una hora calculamos los minutos y segundos y los mostramos
            minutos=gotas/60;
            resto=gotas%60;
            //miramos si hay que añadir 0 o no a la salida
            if(minutos>=10 && resto>=10){
                cout<<"00"<<":"<<minutos<<":"<<resto<<endl;
            }else if(minutos>=10 && resto<10){
                cout<<"00"<<":"<<minutos<<":"<<"0"<<resto<<endl;
            }else if(minutos<10 && resto<10){
                cout<<"00"<<":"<<"0"<<minutos<<":"<<"0"<<resto<<endl;
            }else if(minutos<10 && resto>=10){
                cout<<"00"<<":"<<"0"<<minutos<<":"<<resto<<endl;
            }
            
        }else{
            //si hay horas calculamos horas, minutos y segundos y los mostramos
            minutos=gotas/60;
            resto=gotas%60;
            horas=minutos/60;
            minutos=minutos%60;
            //miramos si hay que añadir 0 o no a la salida
            if(minutos>=10 && resto>=10 && horas>=10){
                cout<<horas<<":"<<minutos<<":"<<resto<<endl;
            }else if(horas>=10 && minutos>=10 && resto<10){
                cout<<horas<<":"<<minutos<<":"<<"0"<<resto<<endl;
            }else if(horas>=10 && minutos<10 && resto<10){
                cout<<horas<<":"<<"0"<<minutos<<":"<<"0"<<resto<<endl;
            }else if(horas<10 && minutos<10 && resto<10){
                cout<<"0"<<horas<<":"<<"0"<<minutos<<":"<<"0"<<resto<<endl;
            }else if(horas<10 && minutos>=10 && resto<10){
                cout<<"0"<<horas<<":"<<minutos<<":"<<"0"<<resto<<endl;
            }else if(horas<10 && minutos<10 && resto>=10){
                cout<<"0"<<horas<<":"<<"0"<<minutos<<":"<<resto<<endl;
            }else if(horas<10 && minutos>=10 && resto>=10){
                cout<<"0"<<horas<<":"<<minutos<<":"<<resto<<endl;
            }else if(horas>=10 && minutos<10 && resto>=10){
                cout<<horas<<":"<<"0"<<minutos<<":"<<resto<<endl;
            }
        
        }
    
        casos--;
    }
    return 0;
}