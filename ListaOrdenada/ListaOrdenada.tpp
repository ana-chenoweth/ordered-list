template <typename T>
ListaOrdenada<T>::ListaOrdenada() : listaDesordenada() {}
//************************************************************************************************
template <typename T>
ListaOrdenada<T>::~ListaOrdenada() {
    listaDesordenada.Vaciar();
}