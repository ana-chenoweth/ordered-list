#include <iostream>
#include "ListaOrdenada/ListaOrdenada.hpp"

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

    // Imprimir la lista despu�s de eliminar elementos
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
        std::cerr << "Error: La lista est� vac�a." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error inesperado: " << e.what() << std::endl;
    }
    return 0;
}
