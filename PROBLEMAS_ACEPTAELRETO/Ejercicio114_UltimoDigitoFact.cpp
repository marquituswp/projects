#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n>0){
        int x;
        cin>>x;
        int sol;
        //si el numero es mayor a 5, por matematica el ultimo digito del factorial sera siempre 0.
        if (x>=5){
            sol=0;
        }
        else {
            //si no calculamos el factorial y lo dividimos por 10, el resto sera el ultimo digito
            int factorial=1;
            for(int i=1;i<=x;i++){
                factorial*=i;
            }
            sol=factorial%10;
        }
        cout<<sol<<"\n";
        n--;
    }

    return 0;
}