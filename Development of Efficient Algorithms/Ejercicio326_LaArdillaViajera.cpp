#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int N;
int M;
int K;
int n;

int K_K;
int maxdist;

//se crea una matriz y un vector de dos valores para almacenar los arboles y sus posiciones
typedef pair<int, int> pii;
char* matriz; //  [1001 * 1001] ;
pii* arboles; // [100000] ;

int last_indice;

//recorrer los arboles mirando si las posiciones estan una al lado de la otra para poder saltar
bool recorrer_rec_opt(int pos_x, int pos_y)
{
    //si en esta posicion de la matriz hay un uno quiere decir que puede saltar de un arbol a otro
    matriz[pos_x * (M + 1) + pos_y] = 1;
    //se mira si las distancias no superan a la mínima para poder saltar, si se cumple querra decir que se puede recorrer el bosque
    if ((N - pos_x) * (N - pos_x) + (M - pos_y) * (M - pos_y) <= K_K) {
        return true;
    }
    // recorrer el area de distancia del arbol
    for (int dx = maxdist; dx >= -maxdist; --dx) {
        for (int dy = maxdist; dy >= -maxdist; --dy) {
            //si en la posicion hay un 2, quiere decir que el arbol seria accesible desde otro
            if (matriz[(pos_x + dx) * (M + 1) + pos_y + dy] == 2) {
                //probar de colocar otro arbol
                if (dx * dx + dy * dy <= K_K) {
                    if ((0 <= pos_x + dx && pos_x + dx <= N) &&
                        (0 <= pos_y + dy && pos_y + dy <= M)) {
                        if (recorrer_rec_opt(pos_x + dx, pos_y + dy)) {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool marcar(int pos_x, int pos_y)
{
    //se pone la posicion de las matriz rodeando el arbol a 2, para decir que seria accesible desde otro arbol
    matriz[pos_x * (M + 1) + pos_y] = 2;

    //se recorre el area del salto alrededor del arbol
    for (int dx = maxdist; dx >= -maxdist; --dx) {
        for (int dy = maxdist; dy >= -maxdist; --dy) {
            //si se encuentra un 1, quire decir que se puede saltar
            if (matriz[(pos_x + dx) * (M + 1) + pos_y + dy] == 1) {
                if (dx * dx + dy * dy <= K_K) {
                    //si aun no hemos llegado al final repetimos el proceso
                    if ((0 <= pos_x + dx && pos_x + dx <= N) &&
                        (0 <= pos_y + dy && pos_y + dy <= M)) {
                        return recorrer_rec_opt(pos_x, pos_y);
                    }
                }
            }
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    matriz = new char[1001 * 1001] ;
    arboles = new pii[100000];
    
    //Mientras haya entrada, se leeran los numeros
    while (cin >> N) {
        cin >> M;
        cin >> K;
        //se crea un entero que es la distancia entre arboles al cuadrado.
        K_K = K * K;
        maxdist = K;
        cin >> n;

        memset(matriz, 0, (unsigned int)(sizeof(char) * (M + 1) * (N + 1)));

        matriz[0] = 1; // Posicion arbol inicial a 1 (se puede saltar)
        matriz[(M + 1) * (N + 1) - 1] = 2; // Posicion arbol final a 2 (Accesible desde otro arbol)
        // Guardamos los arboles
        int pos_x;
        int pos_y;

        //guardar la posicion de los arboles
        for (int i = 0; i < n; ++i) {
            cin >> pos_x >> pos_y;
            arboles[i].first = pos_x;
            arboles[i].second = pos_y;
        }

        int se_puede = -1;
        int se_puede_pos_x;
        int se_puede_pos_y;

        //Colocamos arbol por arbol mirando si se puede saltar de uno a otro hasta llegar al final 
        for (int i = n-1; i >= 0; --i) {
            pos_x = arboles[i].first;
            pos_y = arboles[i].second;
            if (se_puede == -1) {
                //colocamos la posicion del arbol en la matriz y observamos si se puede saltar o no
                if (marcar(pos_x, pos_y)) {
                    se_puede = i;
                    //si se puede se guarda la posicion de ese arbol
                    se_puede_pos_x = pos_x;
                    se_puede_pos_y = pos_y;
                }
            }
        }
        //si se puede no ha cambiado de valor quiere decir que nunca se pudo
        if (se_puede == -1) {
            cout << "NUNCA SE PUDO\n";
        }
        //si se puede ya no vale -1, mostramos la posicion del ultimo arbol que se ha puesto que ha hecho que se pueda saltar
        else {
            cout << se_puede_pos_x << " " << se_puede_pos_y << '\n';
        }
    }

    delete[] matriz; //  [1001 * 1001] ;
    delete[] arboles; // [100000] ;
    

    return 0;
}
