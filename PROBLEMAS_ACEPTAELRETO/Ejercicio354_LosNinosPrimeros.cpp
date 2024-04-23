#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin>>c;
    while(c>0){
        //creamos una array de la gente que ha ido al circo
        int gente[c];
        int z;
        int alt_max=0,max=0;
        int ninos=0;
        cin>>z;
        //la primera persona sera un niño y tendra la altura z
        gente[0]=z;
        //inicializamos la altura maxima de la gente y de los niños a la primera 
        alt_max=z;
        max=z;
        for(int i=1;i<c;i++){
            cin>>z;
            gente[i]=z;
            //si la altura leida es mayor a la maxima se actualiza
            if(z>max){
                max=z;
            }
            //si la altura leida es menor o igual a la altura maxima de los niños, ahora la altura maxima de los niños sera la maxima de la gente
            if(z<=alt_max){
                alt_max=max;
            }   

        }
        for(int i=0;i<c;i++){
            //si la gente es menor o igual a la altura maxima de los niños, querra decir que es un niño
            if(gente[i]<=alt_max){
                ninos++;
            }
        }
        //mostramos el numero de niños que puede haber
        cout<<ninos<<endl;

        cin>>c; 
    }

    cout.flush();
    return 0;
}