#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int casos;
    cin>> casos;
    while(casos>0){
        int m1,m2;
        char sobrante;
        cin>>m1;
        //leemos el sobrante que equival a "/"
        cin>>sobrante;
        cin>>m2;
        //si la primera tension es mayor o igual a la segunda BIEN, sino MAL
        if(m1>=m2){
            cout<<"BIEN"<<endl;
        }else{
            cout<<"MAL"<<endl;
        }
        casos--;
    }



    cout.flush();
    return 0;
}