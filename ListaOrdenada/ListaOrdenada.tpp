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