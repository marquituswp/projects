#include <iostream>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    char a;
    map<char, double> Registro;
    int comidas=0,resto=0;
    while(cin>>a){
        double venta=0;
        cin>>venta;

        if(a=='N'){
            //entraremos cuando haya terminado una cuenta
            double maximo=0, minimo=0,total=0;
            string letras="DAMIC",mini,max;
            bool empatemax=false, empatemin=false;
            for(int i=0;i<5;i++){
                if(i==0){
                    //inicializamos valor maximo y minimo y que letra es la que tiene el valor maximo y minimo
                    maximo=Registro[letras[i]];
                    minimo=Registro[letras[i]];
                    mini=letras[i];
                    max=letras[i];
                }else{
                    //actualizamos valores
                    if(Registro[letras[i]]<minimo){
                        minimo=Registro[letras[i]];
                        mini=letras[i];
                        empatemin=false;
                    }else if(Registro[letras[i]]>maximo){
                        maximo=Registro[letras[i]];
                        max=letras[i];
                        empatemax=false;
                    }else if(Registro[letras[i]]==minimo){
                        empatemin=true;
                    }else if(Registro[letras[i]]==maximo){
                        empatemax=true;
                    }
                }
                //sumamos el total de la cuenta
                total+=Registro[letras[i]];
            }
            //si el maximo y el minimo coinciden querra decir que los dos valores empatan
            if(maximo==minimo){
                empatemax=true;
                empatemin=true;
            }
            //si el valor maximo ha empatado mostraremos empate
            if(empatemax==true){
                cout<<"EMPATE#";
            }else{
                //si no mostraremos el valor del maximo. Cada letra siginifica una palabra
                if(max=="C") max="COPAS";
                else if(max=="A") max="COMIDAS";
                else if(max=="I") max="CENAS";
                else if(max=="M") max="MERIENDAS";
                else if(max=="D") max="DESAYUNOS";
                cout<<max<<"#";
            }
            //si el valor minimo ha empatado mostraremos empate
            if(empatemin==true){
                cout<<"EMPATE#";
            }else{
                //si no mostraremos el valor del minimo. Cada letra siginifica una palabra
                if(mini=="C") mini="COPAS";
                else if(mini=="A") mini="COMIDAS";
                else if(mini=="I") mini="CENAS";
                else if(mini=="M") mini="MERIENDAS";
                else if(mini=="D") mini="DESAYUNOS";
                cout<<mini<<"#";
            }
            //condicion de que la media gastada en comidas sea mayor a media gastada en total
            if((Registro['A']/comidas)>(total/resto)){
                cout<<"SI"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
            //reiniciamos valores
            comidas=0;
            resto=0;
            total=0;
            Registro.clear();
        }else{
            //si no ha acabado la cuenta vamos actualizando el registro de la cuenta.
            Registro[a]+=venta;
            //contar cuantas comidas se han hecho para la posterior condicion de media de comidas
            if(a=='A') {comidas++;}
            resto++;
        }

    }
    

    cout.flush();
    return 0;
}