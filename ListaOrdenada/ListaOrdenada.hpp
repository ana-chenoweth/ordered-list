#ifndef LISTAORDENADA_HPP_INCLUDED
#define LISTAORDENADA_HPP_INCLUDED

#include <iostream>
#include "../ListaDoble/ListaDoble2.hpp"

template <typename T>
class ListaOrdenada {
private:
    struct Elemento {
        T valor;
        Elemento* siguiente;
        Elemento* anterior;
        Elemento(T v, Elemento* sig = nullptr, Elemento* ant = nullptr)
            : valor(v), siguiente(sig), anterior(ant) {}
    };
    int tam;
    Elemento* primero;
    Elemento* ultimo;
    ListaDoble2<T> listaDesordenada;

public:
    ListaOrdenada();
    ~ListaOrdenada();
    ListaOrdenada<T>& operator=(const ListaOrdenada<T>& Otralista);
    ListaOrdenada(const ListaOrdenada<T>& lc);
    void AgregarOrdenado(T valor);
    void Eliminar(T valor);
};

#include "ListaOrdenada.tpp"

#endif // LISTAORDENADA_HPP_INCLUDED