#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int casos;
    cin>>casos;
    while(casos>0){

        int conejo,caballo;
        cin>>conejo>>caballo;
        //calculamos porcentaje de conejo en la mezcla
        conejo=(conejo*100)/(conejo+caballo);
        //mostramos porcentaje de conejo en la mezcla
        cout<<conejo<<endl;

        casos--;
    }


    cout.flush();
    return 0;
}