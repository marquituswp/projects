#include <iostream>
#include <queue>
#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int casos;
    cin>>casos;
    
    while(casos>0){
        int n,s,p,k;
        cin>>n>>s>>p>>k;
        //creamos una cola
        queue<int> circulo;
        //creamos cola igual de larga a numero de personas que hay
        for(int i=1;i<=n;i++){
            circulo.push(i);
        }
        //si el numero de personas es impar, le sumaremos uno
        int n2=n/2;
        if(n2*2!=n){
            n2++;
        }
        //inicializamos muerte de stark y spiderman a falso
        bool m_stark=false,m_spid=false;
        //mientras la mitad de la poblacion sea superior a 0
        while(n2>0){
            //durante k
            for(int i=0; i<k;i++){
                //sacamos primer valor de la cola y lo volvemos a meter al final
                int pos = circulo.front(); circulo.pop();
                circulo.push(pos);
            }
            //sacamos persona que esta al principio de la cola
            int muere = circulo.front(); circulo.pop();
            //si el valor es igual a posicion estaba spiderman o stark, ponemos a true su muerte
            if(muere==s) m_stark=true; 
            if(muere==p) m_spid=true; 
            //quitamos uno a la mitad de la poblacion total
            n2--;
        }
        
        //si solo spiderman muere mostramos lo siguiente
        if(m_spid==true && m_stark==false){
            cout<<"No quiero irme, Sr. Stark!"<<endl;
        //si solo stark muere mostramos lo siguiente
        }else if(m_stark==true && m_spid==false){
            cout<<"No quiero irme, Peter!"<<endl;
        //si mueren los dos mostramos lo siguiente
        }else{
            cout<<"No hay abrazo"<<endl;
        }
        //reiniciamos muerte de spidereman y stark
        m_spid=false;
        m_stark=false;
        casos--;
    }


    cout.flush();
    return 0;
}