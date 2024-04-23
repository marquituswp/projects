#include <iostream>
#include <string>

using namespace std;

//creamos matriz 1001x1001 que sera el cuadrilatero donde estaran las moscas
int* matriz;
const int MAX_X = 1001;
const int MAX_Y = 1001;

bool casoprueba(){
     int tx,ty,mx,my;
    cin>>tx>>ty>>mx>>my;
    //si todas las entradas son 0 se acaba el programa
    if(tx==0 && ty==0 && mx==0 && my==0){
        return false;
    }
    //creamos la linea y leemos una vez para quitar el salto de linea
    string linea;
    getline(cin,linea);
    
    //inicializamos matriz a 0
    for(int x=0;x<=tx;x++){
        matriz[0*MAX_X + x]=0;
    }
    for(int y=1;y<=ty;y++){
        matriz[y*MAX_X + 0]=0;
    }
    //durante toda la matriz
    for(int i=1;i<=ty;i++){
        //leemos la linea
        string linea;
        getline(cin,linea);

        int moscas=0;
        for(int j=1;j<=tx;j++){
            //si el valor de la linea es X sumamos uno al numero de moscas
            moscas += (linea[j - 1] == 'X');
            //el valor en la posicion de la cuadricula sera igual al numero de moscas que mueren en esa zona
            matriz[i * MAX_X + j] = matriz[(i - 1) * MAX_X + j] + moscas;
        }
    }
    
    //creamos array de moscas muertas y lo inicializamos a 0
    int moscas_muertas[8];
    for(int i=0;i<8;i++){
        moscas_muertas[i]=0;
    }
    int X0;
    int Y0;
    int x1;
    int y1;
    //durante la matriz, por bloque igual de grande que matamoscas
    for (x1 = mx, X0 = 0; x1 <= tx; ++x1, X0++) {
        for (y1 = my, Y0 = 0; y1 <= ty; ++y1, Y0++) {
            //en el cuadrado del matamoscas, el numero total de moscas que mueren es igual al numero de la esquina abajo derecha
            //menos las otras esquinas mas la esquina de arriba a la izquierda
            int m = 
                matriz[y1 * MAX_X + x1] +
                matriz[Y0 * MAX_X + X0] -
                matriz[Y0 * MAX_X + x1] -
                matriz[y1 * MAX_X + X0];
            if (m < 8)
            //si el numero de moscas que mueren es menor a 0 sumamos uno al array de moscas que mueren
                moscas_muertas[m]++;
        }
    }

    //mostramos el numero de veces que mueren x moscas
    cout << moscas_muertas[0] << ' ';
    cout << moscas_muertas[1] << ' ';
    cout << moscas_muertas[2] << ' ';
    cout << moscas_muertas[3] << ' ';
    cout << moscas_muertas[4] << ' ';
    cout << moscas_muertas[5] << ' ';
    cout << moscas_muertas[6] << ' ';
    cout << moscas_muertas[7] << '\n';

    return true;
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);

    //creamos matriz de 1001x1001
    matriz = new int[MAX_X * MAX_Y];
    while(casoprueba());

    delete[] matriz;
    cout.flush();
    return 0;
}