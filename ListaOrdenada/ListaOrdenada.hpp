/**
 * \file ListaOrdenada.hpp
 * \brief Implementaci&oacute;n de una Lista Ordenada Compuesta
 * \author Ana Laura Chenoweth Galaz, Geogina Salcido Valenzuela
 * \date 03/04/2024
 */

#ifndef LISTAORDENADA_HPP_INCLUDED
#define LISTAORDENADA_HPP_INCLUDED

#include <iostream>
#include "../ListaDoble/ListaDoble2.hpp"
/** \class ListaOrdenada
 *
 * Permite manipular una lista ordenada, la cual mantiene sus elementos en orden ascendente, con una serie de operaciones
 * como agregar elementos en orden, eliminar elementos, buscar elementos, entre otras.
 *
 * Esta clase proporciona funcionalidades para mantener los elementos ordenados al agregar nuevos elementos,
 * as&iacute; como m&eacute;todos para realizar operaciones comunes en una lista ordenada, como b&uacute;squeda, eliminaci&oacute;n y mezcla con otras listas ordenadas.
* \code Ejemplo.cpp

#include <iostream>
#include "ListaOrdenada.hpp"

int main() {
    try{
    ListaOrdenada<int> lista;

    // Agregar elementos a la lista
    lista.AgregarOrdenado(5);
    lista.AgregarOrdenado(3);
    lista.AgregarOrdenado(8);
    lista.AgregarOrdenado(1);
    lista.AgregarOrdenado(7);

    // Imprimir la lista ascendente y descendente
    std::cout << "Lista ascendente: ";
    lista.ImprimirAscendente();
    std::cout << std::endl;

    std::cout << "Lista descendente: ";
    lista.ImprimirDescendente();
    std::cout << std::endl;

    // Buscar un elemento en la lista
    std::cout << "Buscar 3: " << (lista.Buscar(3) ? "Encontrado" : "No encontrado") << std::endl;
    std::cout << "Buscar 6: " << (lista.Buscar(6) ? "Encontrado" : "No encontrado") << std::endl;

    // Eliminar un elemento de la lista
    lista.Eliminar(3);
    lista.Eliminar(8);

    // Imprimir la lista despu&eacute;s de eliminar elementos
    std::cout << "Lista despues de eliminar elementos: ";
    lista.ImprimirAscendente();
    std::cout << std::endl;

    // Mezclar dos listas
    ListaOrdenada<int> otraLista;
    otraLista.AgregarOrdenado(2);
    otraLista.AgregarOrdenado(6);
    otraLista.AgregarOrdenado(4);

    ListaOrdenada<int> listaMezclada = lista.Mezclar(otraLista);

    // Imprimir la lista mezclada
    std::cout << "Lista mezclada: ";
    listaMezclada.ImprimirAscendente();
    std::cout << std::endl;
    } catch (const ListaOrdenada<int>::ListaVacia& e) {
        std::cerr << "Error: La lista est&aacute; vac&iacute;a." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error inesperado: " << e.what() << std::endl;
    }

    return 0;
}

 * \endcode
 *
 \verbatim Salida:
Lista ascendente: 1, 3, 5, 7, 8,
Lista descendente: 8, 7, 5, 3, 1,
Buscar 3: Encontrado
Buscar 6: No encontrado
Lista despuΘs de eliminar elementos: 1, 5, 7,
Lista mezclada: 1, 2, 4, 5, 6, 7,
  \endverbatim
 *
 */

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
    /** \class ListaVacia
     *  \brief Excepci&oacute;n lanzada cuando se realiza una operaci&oacute;n en una lista vac&iacute;a.
     */
    class ListaVacia {};
    /** \class FueraRango
     *  \brief Excepci&oacute;n lanzada cuando se intenta acceder a una posici&oacute;n fuera del rango de la lista.
     */
    class FueraRango {};
    /** \brief Constructor por defecto.
     *
     * Crea una lista ordenada vac&iacute;a.
     */
    ListaOrdenada();
    /** \brief Destructor.
     *
     * Libera la memoria ocupada por la lista.
     */
    ~ListaOrdenada();
    /** \brief Operador de asignaci&oacute;n.
     *
     * Asigna el contenido de una lista ordenada a otra.
     *
     * \param Otralista Lista ordenada a asignar.
     * \return Referencia a la lista actual.
     */
    ListaOrdenada<T>& operator=(const ListaOrdenada<T>& Otralista);
    /** \brief Constructor de copia.
     *
     * \param lc Lista a copiar.
     */
    ListaOrdenada(const ListaOrdenada<T>& lc);
    /** \brief Agrega un elemento en orden a la lista.
     *
     * \param valor Valor del elemento a agregar.
     */
    void AgregarOrdenado(T valor);
    /** \brief Elimina un elemento de la lista.
     *
     * \param valor Valor del elemento a eliminar.
     * \throw ListaVacia si la lista est&aacute; vac&iacute;a.
     */
    void Eliminar(T valor);
    /** \brief Busca un valor en la lista.
     *
     * \param valor Valor a buscar.
     * \return true si el valor se encuentra en la lista, false en caso contrario.
     */
    bool Buscar(T valor) const;
    /** \brief Verifica si la lista est&aacute; vac&iacute;a.
     *
     * \return true si la lista est&aacute; vac&iacute;a, false en caso contrario.
     */
    bool EstaVacia() const;
    /** \brief Obtiene el tamaño de la lista.
     *
     * \return N&uacute;mero de elementos en la lista.
     */
    int Tamano() const;
    /** \brief Imprime los elementos de la lista en orden ascendente.
     */
    void ImprimirAscendente() const;
    /** \brief Imprime los elementos de la lista en orden descendente.
     */
    void ImprimirDescendente() const;
    /** \brief Mezcla dos listas ordenadas en una nueva lista ordenada.
     *
     * \param otraLista La otra lista a mezclar con esta lista.
     * \return Una nueva lista ordenada que contiene los elementos de ambas listas.
     */
    ListaOrdenada<T> Mezclar(const ListaOrdenada<T>& otraLista);
};

#include "ListaOrdenada.tpp"

#endif // LISTAORDENADA_HPP_INCLUDED