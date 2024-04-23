#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int numero;
    cin>>numero;
    while(numero!=0){
        int panD=0,panI=0;
        char comido;
        //leemos toda la entrada
        for(int i=0;i<numero;i++){
            cin>>comido;
            //si uno come por la derecha ponemos el booleano de panD a 1
            if(comido=='D'){
                panD=1;
            }
            //si uno come por la izquierda ponemos el booleano de panI a 1
            if(comido=='I'){
                panI=1;
            }
        }
        //si una persona come por la derecha y otra por la izquierda, minimo una siempre no comera
        if(panD==1 && panI==1){
            cout<<"ALGUNO NO COME"<<endl;
        }else{
        //Si no siempre comeran todos
           cout<<"TODOS COMEN"<<endl;
        }



        cin>>numero;
    }


    cout.flush();
    return 0;
}