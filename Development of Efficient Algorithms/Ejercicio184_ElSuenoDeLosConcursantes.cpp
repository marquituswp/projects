#include <iostream>

using namespace std;

bool casoprueba(){
    int casos;
    cin>>casos;
    int min_dormido=0;
    int horas_dormido=0;
    if(casos==0)return false;
    while(casos>0){
        //leemos la entrada
        int h1,m1;
        char sobrante;
        //leemos la hora 1
        cin>>h1;
        //leemos el sobrante que son los ":"
        cin>>sobrante;
        //leemos el minuto 1
        cin>>m1;
        int h2,m2;
        cin>>sobrante;
        //leemos la hora 2
        cin>>h2;
        cin>>sobrante;
        //leemos el minuto 2
        cin>>m2;

        //si estamos entre 0 y 10 horas, le sumamos 24
        if(h1>=0 && h1<=10){
            h1+=24;
        }
        if(h2>=0 && h2<=10){
            h2+=24;
        }
        //los minutos que ha dormido sera la diferencia de las dos horas pasadas a minutos mas los minutos
        min_dormido+=((h2*60)+m2)-((h1*60)+m1);
        //acumulamos los minutos dormidos hasta que acabamos los casos
        casos--;
    }
    //pasamos los minutos totales a horas y minutos 
    horas_dormido=min_dormido/60;
    min_dormido=min_dormido%60;
    //si alguno de ellos es menos a 10 hay que mostrar la salida añadiendole un 0 delante al valor.
    if(horas_dormido<10 && min_dormido<10){
        cout<<"0"<<horas_dormido<<":"<<"0"<<min_dormido<<endl;
    }else if(horas_dormido<10 && min_dormido>=10){
        cout<<"0"<<horas_dormido<<":"<<min_dormido<<endl;
    }else if(horas_dormido>=10 && min_dormido<10){
         cout<<horas_dormido<<":"<<"0"<<min_dormido<<endl;
    }else{
        cout<<horas_dormido<<":"<<min_dormido<<endl;
    }


    return true;
}


int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);

    while(casoprueba());

    cout.flush();
    return 0;
}