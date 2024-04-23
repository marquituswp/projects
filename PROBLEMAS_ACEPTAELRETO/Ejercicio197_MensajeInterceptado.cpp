#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string mensaje;
    //mientras haya un mensaje que leer
    while(getline(cin,mensaje)){
        //creamos strings auxiliares
        string aux="",aux1,aux2,final="";

        for(int i=0;i<mensaje.length();i++){
            //recorremos el mensaje.
            //si estamos en la penultima letra del mensaje
            if(i+1==mensaje.length()){
                //metemos en el auxiliar 1 la penultima letra.
                aux1=aux1+mensaje[i];
            }else{
                //si no en el la palabra auxiliar 1 metemos la letra actual y en el auxiliar 2 la siguiente letra de la palabra
                aux1=aux1+mensaje[i];
                aux2=mensaje[i+1]+aux2;
                i++;
            }
        }
        //juntamos las dos palabras (en aux1 tenemos las letras impares y en aux2 las letras pares)
        aux=aux1+aux2;
        aux1="";
        aux2="";
        for(int i=0;i<mensaje.length();i++){
            //si en la palabra encontramos una vocal
            if(tolower(aux[i])=='a' || tolower(aux[i])=='e' || tolower(aux[i])=='i' || tolower(aux[i])=='o' || tolower(aux[i])=='u'){
                //giramos la palabra que hay entre las vocales de orden (la ultima letra sera la primera, etc)
                for(int i=aux1.length()-1;i>=0;i--){
                    aux2+=aux1[i];
                }
                //vamos creando la palabra final
                final+=aux2+aux[i];
                aux1="";
                aux2="";
            }else{
                //si no, guardamos las letras que nos vamos encontrando formando la palabra que hay entre las vocales
                aux1+=aux[i];
            }
        }
        //si al acabar aun hay una palabra creada que no ha sido girada, la giramos
        if(aux1.length()>0){
            for(int i=aux1.length()-1;i>=0;i--){
                    aux2+=aux1[i];
                }
                final+=aux2;
        }
        //mostramos el mensaje final
        cout<<mensaje<<" => "<<final<<endl;
    }
    
    cout.flush();
    return 0;
}