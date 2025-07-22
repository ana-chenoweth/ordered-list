#include "ListaOrdenada.hpp"
template <typename T>
ListaOrdenada<T>::ListaOrdenada() : listaDesordenada() {}
//************************************************************************************************
template <typename T>
ListaOrdenada<T>::~ListaOrdenada() {
    listaDesordenada.Vaciar();
}
//************************************************************************************************
template <typename T>
ListaOrdenada<T> &ListaOrdenada<T>::operator=(const ListaOrdenada<T> &Otralista) {
    this->listaDesordenada = Otralista.listaDesordenada;
    return *this;
}
//************************************************************************************************
template <typename T>
ListaOrdenada<T>::ListaOrdenada(const ListaOrdenada<T> &lc) : listaDesordenada()
{
    *this = lc;
}
//************************************************************************************************
template <typename T>
void ListaOrdenada<T>::AgregarOrdenado(T valor) {
    if (listaDesordenada.EstaVacia())
        listaDesordenada.AgregarInicio(valor);
    else {
        int tam = listaDesordenada.ObtenerTam();
        int pos;
        for (pos = 0; pos < tam && listaDesordenada.ObtenerPorPos(pos) < valor; pos++)
            ;
        listaDesordenada.AgregarPos(valor, pos);
    }
}
//************************************************************************************************
template <typename T>
void ListaOrdenada<T>::Eliminar(T valor) {
    listaDesordenada.EliminarPrimeraOcurrencia(valor);
}
//************************************************************************************************
template <typename T>
bool ListaOrdenada<T>::Buscar(T valor) const {
    return listaDesordenada.BuscarValor(valor);
}
//************************************************************************************************
template <typename T>
bool ListaOrdenada<T>::EstaVacia() const {
    return listaDesordenada.EstaVacia();
}
//************************************************************************************************
template <typename T>
int ListaOrdenada<T>::Tamano() const {
    return listaDesordenada.ObtenerTam();
}
//************************************************************************************************
template <typename T>
void ListaOrdenada<T>::ImprimirAscendente() const {
    listaDesordenada.Imprimir();
}
//************************************************************************************************
template <typename T>
void ListaOrdenada<T>::ImprimirDescendente() const {
    listaDesordenada.ImprimirReversa();
}
//************************************************************************************************
template <typename T>
ListaOrdenada<T> ListaOrdenada<T>::Mezclar(const ListaOrdenada<T>& otraLista) {
    ListaOrdenada<T> resultado;
    int tam1 = this->Tamano();
    int tam2 = otraLista.Tamano();
    int i = 0, j = 0;

    while (i < tam1 && j < tam2) {
        T elem1 = listaDesordenada[i];
        T elem2 = otraLista.listaDesordenada[j];

        if (elem1 <= elem2) {
            resultado.AgregarOrdenado(elem1);
            ++i;
        } else {
            resultado.AgregarOrdenado(elem2);
            ++j;
        }
    }

    while (i < tam1) {
        T elem1 = listaDesordenada[i];
        resultado.AgregarOrdenado(elem1);
        ++i;
    }

    while (j < tam2) {
        T elem2 = otraLista.listaDesordenada[j];
        resultado.AgregarOrdenado(elem2);
        ++j;
    }

    return resultado;
}
