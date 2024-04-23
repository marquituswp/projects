#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int distancia,v_max,tiempo;
    cin>>distancia>>v_max>>tiempo;
    //mientras todos los valores sean distintos a 0 continuamos
    while(distancia!=0 || v_max!=0 || tiempo!=0){
        //si los valores son negativos o 0 es un error
        if(distancia<=0 || v_max<=0 || tiempo <=0)cout<<"ERROR"<<endl;
        else{
            //calculamos velocidad del coche con la equacion v=e/t por 3.6 ya que hay que pasarla a km/h
            double v_coche=3.6*distancia/tiempo;
            //si no sobrepasa la velocidad ok
            if(v_coche<=v_max) cout<<"OK"<<endl;
            //si la sobrepasa un 20% tiene solo multa
            else if(v_coche<(v_max*1.2)) cout<<"MULTA"<<endl;
            //si la sobrepasa mas se le quitan puntos
            else cout<<"PUNTOS"<<endl;  
        }
        //volvemos a leer entrada
        cin>>distancia>>v_max>>tiempo;
    }
    
    cout.flush();
    return 0;
}