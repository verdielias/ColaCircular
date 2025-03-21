#include <iostream>

//Constructor
template <typename T>
ListaCircular<T>::ListaCircular(): numElem(0), cabeza(nullptr){
}
//Constructor de copias
template <typename T>
ListaCircular<T>::ListaCircular(const ListaCircular &LS){
    *this = LS;
}
//Operador igual
template <typename T>
ListaCircular<T>& ListaCircular<T>::operator= (const ListaCircular &v){
    if (this == &v) return *this;
    this ->Vaciar();
    Elemento *aux = v.cabeza;
    this.AgregarValor(aux -> valor);
    aux = aux -> siguiente;
    while(aux -> siguiente != cabeza){
        this.AgregarValor(aux -> valor);
        aux = aux -> siguiente;
    }
    return *this;
}
// Destructor
template <typename T>
ListaCircular<T>::~ListaCircular(){
    Vaciar();
}
//Agregar antes de la cabeza y mueve
template <typename T>
void ListaCircular<T>::AgregarValor(T valor){
    Elemento* nuevo = new Elemento(valor);
    
    if(numElem  == 0){
        cabeza = nuevo;
        cabeza -> siguiente = nuevo;
        cabeza -> anterior = nuevo;
    }else{
        nuevo-> siguiente = cabeza;
        nuevo -> anterior = cabeza -> anterior;
        cabeza -> anterior -> siguiente = nuevo;
        cabeza -> anterior = nuevo;
        cabeza = nuevo;
    }

    ++numElem;
}
//Eliminar a la cabeza
template <typename T>
void ListaCircular<T>::EliminarCabeza(){
    if(EstaVacia())throw "La lista esta vacia";
    
    Elemento * porBorrar  = cabeza;
        
    if(numElem==1){
        cabeza = nullptr;
    } else{
        cabeza -> anterior -> siguiente = cabeza -> siguiente;
        cabeza -> siguiente -> anterior = cabeza -> anterior;
        cabeza = cabeza -> siguiente;
    }
    delete porBorrar;
    --numElem;

}
//Buscar un valor
template <typename T>
bool ListaCircular<T>::Buscar(T valor) const {
    Elemento *aux = cabeza;
    if (EstaVacia()){
        return false;
    }
    if (valor == aux->valor){
        return true;
    }
    do{
        aux = aux->siguiente;
        if (valor == aux->valor){
            return true;
        }
    } while (aux != cabeza);

    return false;
}
//Avanzar la cabeza
template <typename T>
void ListaCircular<T>::AvanzarCabeza(){
    if (!EstaVacia()){
        cabeza = cabeza -> siguiente;
    }
}
//Retroceder la cabeza
template <typename T>
void ListaCircular<T>::RetrocederCabeza(){
    cabeza = cabeza -> anterior;
}
//Conocer el numero de elementos
template <typename T>
int ListaCircular<T>::ConocerNumElem(){
    return numElem;
}

//Copnocer si la lista esta vacia
template <typename T>
bool ListaCircular<T>::EstaVacia() const {
    if(numElem == 0) return true;
    return false;
}
//Vaciar
template <typename T>
void ListaCircular<T>::Vaciar(){
    while(numElem != 0){
        EliminarCabeza();
    }
}
//Imprimir
template <typename T>
void ListaCircular<T>::Imprimir() const {
    if (EstaVacia()) {
        std::cout << "Lista vacía." << std::endl;
        return;
    }

    Elemento* aux = cabeza;
    for (int i = 0; i < numElem; ++i) {
        std::cout << aux->valor;
        if (i != numElem - 1) {
            std::cout << ", ";
        }
        aux = aux->siguiente;
    }
    std::cout << std::endl;
}
//Imprimir al revez
template <typename T>
void ListaCircular<T>::ImprimirReversa() const{
    if(EstaVacia())return;
    Elemento *aux = cabeza -> anterior;
    int i = numElem;
    while(i != 0){
        std::cout << aux -> valor <<  ",";
        aux = aux -> anterior;
        --i;
    }
    std::cout << std::endl;
}
