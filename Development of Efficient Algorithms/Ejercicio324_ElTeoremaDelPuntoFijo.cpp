#include <iostream>

using namespace std;

//funcion que saca el minimo comun multiplo de dos numeros
int maximocomundivisor(int a, int b) {
    if(b == 0) return a;
    return maximocomundivisor(b, a%b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin>>c;
    while(c>0){
        //creamos dos arrays uno de moleculas y otro de valores del tamaño de la entrada
        int mol[c];
        int valores[c];
        for(int i=0;i<c;i++){
            int z;
            cin>>z;
            //leemos la entrada y la metemos en el array de moleculas e inicializamos los valores a 0
            mol[i]=z;
            valores[i]=0;
        }
        int aux,mov=0;
        int j=0;
        for(int i=0;i<c;i++){
            //creamos un numero que sera la posicion del array
            int num=i+1;
            //si el la posicion en el array de moleculas no es 0
            if(mol[i]!=0){
                //mientras no sea 0
                while(mol[num-1]!=0){
                    //bucle donde leo el valor del array de la molecula en la posicion del numero
                    //pongo el valor de la molecula en la poscion del numero a 0 y paso al siguiente valor de la molecula en la poscion del numero que habia leido anteriormente
                    aux=num;
                    num=mol[num-1];
                    mol[aux-1]=0;
                    if(num==0){
                        num++;
                    }
                    //cada vez que lo hago es un movimiento 
                    mov++;
                    //se repide hasta que llego a un valor que es 0 y querra decir que he dado toda la vuelta
                }
                //guardo los movimientos de este numero en un array de valores
                valores[j]=mov;
                j++;
                mov=0;
            }
        }
        int residuo,mcm=1;
        //saco el minimo comun multiplo de cada valor 
        for (int i = 0; i<c && valores[i]!=0; i++){
            mcm=(mcm*valores[i])/maximocomundivisor(mcm,valores[i]);
        }
        //muestro el minimo comun multiplo final
        cout<<mcm<<endl;
        cin>>c;
    }

    cout.flush();
    return 0;
}