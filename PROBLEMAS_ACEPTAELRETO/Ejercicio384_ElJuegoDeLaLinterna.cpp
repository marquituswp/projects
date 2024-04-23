#include <iostream>
#include <vector>

using namespace std;

//se crea un vector de intervalos para tener un registro de los rangos de numeros
struct Intervalo
{
    int ini, fin;
};

vector<Intervalo> intervalos;

//buscamos el numero en el intervalo. Si esta entre un intervalo quiere decir que fallara
int busqueda(int ini, int fin, int v)
{
    
    if (ini > fin)
        return -1;
    int mid = (ini + fin) / 2;
    Intervalo i = intervalos[mid];
    if (i.ini <= v && v <= i.fin)
        return mid;

    if (v < i.ini)
        return busqueda(ini, mid - 1, v);
    return busqueda(mid + 1, fin, v);
}

int busqueda(int v)
{
    int num_intervalos = intervalos.size();
    if (num_intervalos == 0)
        return -1;
    return busqueda(0, num_intervalos - 1, v);
}


//mirar donde va el intervalo para poder actualizarlo
double dondeva(int ini, int fin, int v) {
    if (ini > fin)
        return (ini+fin)/2.0;
    Intervalo i;
    if (ini == fin)
    {
        i = intervalos[ini];
        if (v < i.ini)
            return ini - 0.5;
        if (v > i.fin)
            return fin + 0.5;
        return ini;
    }
    int mid = (ini + fin) / 2;
    i = intervalos[mid];
    if (i.ini <= v && v <= i.fin)
        return mid;

    if (v < i.ini)
        return dondeva(ini, mid - 1, v);
    return dondeva(mid + 1, fin, v);
}

double dondeva(int v) {
    return dondeva(0, intervalos.size() - 1, v);
}

//actualizar los intervalos
void inserta(Intervalo i)
{
    if (intervalos.size() == 0)
    {
        intervalos.push_back(i);
        return;
    }
    double loc_ini = dondeva(i.ini);
    bool en_intervalo_ini = (loc_ini == (int)loc_ini);
    double loc_fin = dondeva(i.fin);
    bool en_intervalo_fin = (loc_fin == (int)loc_fin);

    // Si el intervalo esta dentro de otro no se debe hacer nada
    if (loc_ini == loc_fin && en_intervalo_ini && en_intervalo_fin)
        return;
    
    // De un rango a otro
    if (en_intervalo_ini && en_intervalo_fin)
    {
        int int_ini = (int)loc_ini;
        int int_fin = (int)loc_fin;
        intervalos[int_ini].fin = intervalos[int_fin].fin;
        for (int i = int_fin; i > int_ini; --i)
            intervalos.erase(intervalos.begin() + i);
        return;
    }

    // Entre dos rangos
    if (loc_ini == loc_fin && !en_intervalo_ini && !en_intervalo_fin) {
        int int_ini = (int)(loc_ini + 0.5);
        intervalos.insert(intervalos.begin() + int_ini, i);
        return;
    }

    // Comienza entre dos rangos y termina en otro
    if (!en_intervalo_ini && en_intervalo_fin) {
        int int_ini = (int)(loc_ini + 0.5);
        int int_fin = (int)loc_fin;

        intervalos[int_ini].ini = i.ini;
        intervalos[int_ini].fin = intervalos[int_fin].fin;

        for (int i = int_fin; i > int_ini; --i)
            intervalos.erase(intervalos.begin() + i);

        return;
    }

    // Comienza entre dos rangos y termina en otro
    if (en_intervalo_ini && !en_intervalo_fin) {
        int int_ini = loc_ini;
        int int_fin = (int)(loc_fin - 0.5);

        intervalos[int_ini].ini = intervalos[int_ini].ini;
        intervalos[int_ini].fin = i.fin;

        for (int i = int_fin; i > int_ini; --i)
            intervalos.erase(intervalos.begin() + i);
        return;
    }

    if (!en_intervalo_ini && !en_intervalo_fin) {
        int int_ini = (int)(loc_ini + 0.5);
        int int_fin = (int)(loc_fin - 0.5);

        intervalos[int_ini].ini = i.ini;
        intervalos[int_ini].fin = i.fin;

        for (int i = int_fin; i > int_ini; --i)
            intervalos.erase(intervalos.begin() + i);
        return;
    }
}


bool caso_de_prueba()
{
    int num;
    if (!cin)
        return false;

    // Numero de crios
    cin >> num;

    //si el numero es menor a 0 o no hay entrada acabamos el programa
    if (num < 0)
        return false;
    if (!cin)
        return false;

    intervalos.clear();

    int ant;
    int act;
    bool sube = false;
    bool falla = false;

    cin >> ant;
    int i = 1;
    int minimo_sube = ant;
    int maximo_sube = ant;

    while (i < num && !falla) {
        cin >> act;
        ++i;

        //mirar si el siguiente numero es mayor o menor al enterior
        if (ant < act) {
            // Sube
            if (sube == false) {
                minimo_sube = ant;
                sube = true;
            }
            maximo_sube = act;
        }
        else {
            // Baja
            if (sube == true) {
                // Meter el rango minimo_sube, maximo_sube en la estructura
                Intervalo i;
                i.ini = minimo_sube;
                i.fin = maximo_sube;
                inserta(i);
            }
            sube = false;
        }
        int index = busqueda(act);
        
        //si el indice es distinto a -1 el orden de los crios no es correcto y fallara
        if (index != -1)
            falla = true;

        
        ant = act;
    }
    while (i < num) {
        cin >> act;
        ++i;
    }

    //si falla hay que elegir otro orden
    if (falla)
        cout << "ELEGIR OTRA\n";

    //si no falla siempre habra premio
    else
        cout << "SIEMPRE PREMIO\n";

    return true;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (caso_de_prueba());

    cout.flush();
    return 0;
}
