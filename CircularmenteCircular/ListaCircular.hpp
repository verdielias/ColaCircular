#ifndef LISTACIRCULAR_HPP_INCLUDED
#define LISTACIRCULAR_HPP_INCLUDED

template<typename T>
class ListaCircular{
public:
    //Constructor
    ListaCircular();
    //Constructor de copias
    ListaCircular(const ListaCircular &LS);
    //Operador igual
    ListaCircular<T>& operator= (const ListaCircular<T> &v);
    // Destructor
    ~ListaCircular();
    //Agregar antes de la cabeza y mueve
    void AgregarValor(T valor);
    //Eliminar a la cabeza
    void EliminarCabeza();
    //Buscar un valor
    bool Buscar(T valor) const;
    //Avanzar la cabeza
    void AvanzarCabeza();
    //Retroceder la cabeza
    void RetrocederCabeza();
    //Conocer el numero de elementos
    int ConocerNumElem();
    //Copnocer si la lista esta vacia
    bool EstaVacia() const;
    //Vaciar
    void Vaciar();
    //Imprimir
    void Imprimir() const;
    //Imprimir al revez
    void ImprimirReversa() const;



private:
    int numElem;
    struct Elemento{
      T valor;
      Elemento * siguiente;
      Elemento * anterior;
      Elemento(T v, Elemento * sig = nullptr, Elemento * ant = nullptr){
        valor = v;
        siguiente = sig;
        anterior = ant;

      }
    }*cabeza;
};

#include "ListaCircular.tpp"

#endif // LISTACIRCULARDOBLEMENTEENLAZADA_HPP_INCLUDED
