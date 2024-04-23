#include <iostream>

using namespace std;

bool casoprueba(){
    int num_paises;
    cin>>num_paises;
    if(num_paises==0)return false;
    long long int total=0;
    if(num_paises==1){
        cin>>total;
        cout<<total*0<<endl;
    }
    if(num_paises!=1){
        int paises[100000]={0};
        int z;
        for(int i=0;i<num_paises;i++){
            //leer la entrada y meterla en el array de paises
            cin>>z;
            paises[i]=z;
        }
        //crear un entero que sea igual al ultimo pais
        long long int j=paises[num_paises-1];
        //De derecha a izquierda del array
        for(int i=num_paises-2;i>=0;i--){
            //El total es igual al numero (inicialzado como el ultimo) * el anterior
            total+=paises[i]*j;
            //ahora se le suma el anterior al numero y se repite bucle
            j+=paises[i];
        }
        //mostramos el total que sera el numero de parejas que se pueden hacer
        cout<<total<<endl;
    }
    
    return true;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(casoprueba());

    cout.flush();
    return 0;
}