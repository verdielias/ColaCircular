#include "ListaCircular.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void LeerNombres(const string& nombreArchivo, ListaCircular<string>& lista);
void SimulacionPatoGanso(const string& archivoNombres, int k);

int main(){
    string archivoNombres = "Nombres.txt";
    int k;
    cout << "Ingrese el valor de k: ";
    cin >> k;
    if (k > 0) {
        SimulacionPatoGanso(archivoNombres, k);
    } else {
        cout << "Por favor, introduzca un valor válido para k (k > 0)." << endl;
    }
    return 0;
}


void LeerNombres(const string& nombreArchivo, ListaCircular<string>& lista){
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()){
        cerr << "No se puede abrir el archivo .txt";
        return;
    }
        
    string nombre;
    while (getline(archivo, nombre)){
        if (!nombre.empty()){
            lista.AgregarValor(nombre);
        }
    }
    archivo.close();
}


void SimulacionPatoGanso(const string& archivoNombres, int k){
    ListaCircular<string> lista;
    
    LeerNombres(archivoNombres, lista);
    
    if(lista.ConocerNumElem()== 0){
        cout << "La lista est\240 vac\242a" << endl;
        return;
    }
    
    cout << "Orden inicial: ";
    lista.Imprimir();
    while (lista.ConocerNumElem() > 1){
        for (int i = 0; i < k - 1; ++i){
            lista.AvanzarCabeza();
        }
        lista.EliminarCabeza();
        lista.Imprimir();

    }
    cout << "Ganador: ";
    lista.Imprimir();
}