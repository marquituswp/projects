#include <iostream>

using namespace std;

//funcion para invertir el numero
int invertirnumero(long long int num){
    long long int aux=0;
    while(num>0){
        aux=(aux*10) + (num%10);
        num=num/10;
    }
    return aux;
}

//funcion para ver si es capicua
bool capicua(long long int total){
    //si el numero es igual a cuando esta invertido sera capicua
    if(total==invertirnumero(total)){
        return true;
    }else{
        return false;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int casos;
    cin>>casos;
    while(casos>0){
        long long int num=0,total=0,num2=0,pasos=0;;
        cin>>num;
        total=num;
        //creamos un bucle mientras el numero no sea lychrel (mayor a 1000000000)
        while(total<=1000000000){
            num=total;
            num2=invertirnumero(num);
            //el total se actualiza sumandole el numero invertido
            total=total+num2;
            //sumamos uno a cantidad pasos hechos para llegar a un numero capicua
            pasos++;
            if(total>1000000000){
                //si el numero se pasa de 1000000000 mostramos "Lychrel?"
                cout<<"Lychrel?"<<endl;
                break;
            }
            //si el numero es capicua mostramos la cantidad de pasos hechos hasta llegar y el numero 
            if(capicua(total)==true){
                cout<<pasos<<" "<<total<<endl;
                break;
            }
        }
        casos--;
    }



    cout.flush();
    return 0;
}