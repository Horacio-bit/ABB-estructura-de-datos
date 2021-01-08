//
// Created by Rodrigo Calles on 2020-11-05.
//

#ifndef UNTITLED_ABB_H
#define UNTITLED_ABB_H

#include <iostream>
using namespace std;

#include "Cola.h"

template <typename T>
class ABB {
public:
    /**
     *@brief Contructor del árbol binario de busqueda
     */
    ABB();

    /**
     *@brief destructor del árbol binario de busqueda
     */
    ~ABB();

    /**
     *@brief Constructor de copia del árbol
     * @param AB Una referencia constante a AB
     * @return un árbol binario
     */
    ABB(const ABB<T> &AB);

    /**
     * @brief El operador igual sobrecargado
     * @param AB Una referencia constante a AB
     */
     ABB<T> &operator=(const ABB<T> &AB);

    /**
     *@brief Método público para agregar un nodo al árbol
     * @param valor El valor que se agregará al árbol
     * @return Un valor booleano indicando si se pudo agregar o no el valor
     */
    bool Agregar(const T & valor);

    /**
     *@brief Método público para eliminar un nodo del árbol
     * @param valor El valor que se eliminará del árbol
     * @return Un valor booleano indicando si se pudo eliminar o no el valor
     */
    bool Eliminar(const T & valor);

    /**
     * @brief Método público para imprimir el árbol usando el algoritmo de preorden
     */
    void ImprimirEnPreOrden() const;

    /**
     * @brief Método para buscar un nodo en el árbol
     * @param valor El valor del nodo que se se quiere buscar
     * @return un booleano indicando si el nodo está o no en el árbol
     */
    bool buscar(const T & valor) const;

    /**
     * @brief Método público para imprimir el árbol de forma ascendiente
     */
    void ImprimirAcendiente() const;

    /**
     * @brief Método público para imprimir el árbol de forma descendiente
     */
    void ImprimirDescendiente() const;

    /**
     * @brief método público para imprimir el árbol en forma de postorden
     */
    void ImprimirEnPostOrden() const;

    /**
     * @brief Método para vaciar el árbol
     */
    void Vaciar();

    /**
     * @brief Método para imprimir el árbol por niveles
     */
    void ImprimirPorNiveles() const;

    /**
     * @método para obtener el números de nodos en la lista
     * @return Un entero indicando el número de nodos en el árbol
     */
    int ObtenerNumNodos();



private:
    struct Nodo{
        Nodo(T _valor, Nodo * _hijoIzq = NULL, Nodo * _hijoDer = NULL): valor(_valor), hijoIzq(_hijoIzq), hijoDer(_hijoDer){}
        T valor;
        Nodo * hijoIzq, * hijoDer;

        bool esHoja(){
            return hijoIzq == NULL && hijoDer == NULL;
        }
    } * raiz;

    int numNodos;

    /**
     *  @brief Método para imprimir el árbol en preorden
     * @param _raiz un puntero a nodo que representa a una raiz local del árbol
     */
    void ImprimirPreorden(Nodo *_raiz) const;

    /**
     * @brief Método para imprimir el árbol en Entre Orden
     * @param _raiz un puntero a nodo que representa a una raiz local del árbol
     */
    void ImprimirEnEntreOrden(Nodo *_raiz) const;

    /**
     *  @brief Método para imprimir el árbol en post orden
     * @param _raiz un puntero a nodo que representa a una raiz local del árbol
     */
    void ImprimirEnPostOrden(Nodo *_raiz) const;

    /**
     * @ Método para eliminar todos los nodos a partir de una raíz
     * @param _raiz un puntero a nodo que represente una raíz local
     */
    void Podar(Nodo*&_raiz);

    /**
     * @brief Método privado para agregar un nodo a la raíz
     * @param valor El valor que se va a agregar al árbol
     * @param _raiz la raíz local
     * @return un valor booleano para indicar si se pudo o no agregar un valor
     */
    bool Agregar(const T & valor, Nodo * &_raiz);

    /**
     * @brief Método para eliminar un nodo del árbol
     * @param valor El valor que se va a eliminar
     * @param _raiz la raíz local
     * @return un valor booleando indicando si se pudo eliminar el nodo
     */
    bool Eliminar(const T & valor, Nodo * &_raiz );

    /**
     * @brief Método para intercambiar  la raíz antigua por la nueva (usado en el método de eliminar)
     * @param raiz_antigua La raíz en la posición que se va eliminar
     * @param _raiz la raíz que va a tomar el lugar de la raíz antigua
     */
    void IntercambiarPadre(Nodo * & raiz_antigua, Nodo * &_raiz);

    /**
     * @brief Método para buscar un valor
     * @param valor El valor que se va a buscar
     * @param _raiz una raíz local
     * @return Un valor booleano indicando si está o no la raíz
     */
     Nodo * buscar(const T & valor, Nodo *_raiz) const;

     /**
      * @brief método privado para imprimir un árbol de forma descendiente
      * @param _raiz una raíz local
      */
     void ImprimirDescendiente(Nodo * _raiz) const;


};

//*****************************************************************************************************************************************


template<typename T>
ABB<T>::ABB(): raiz(NULL), numNodos(0) {

}

template <typename T>
ABB<T>::~ABB() {
    Vaciar();
}

template<typename T>
ABB<T>::ABB(const ABB<T> &AB): raiz(NULL), numNodos(0) {
    *this = AB;

}

template<typename T>
ABB<T> &ABB<T>::operator=(const ABB<T> &AB) {
    if(this == &AB)
        return *this;
    Vaciar();
    if(AB.EstaVacio())
        return *this;
    Cola<Nodo *> colaDeEspera;
    colaDeEspera.AgregarElemento(AB.raiz);
    Nodo *aux;
    while(!colaDeEspera.Vaciar()) {
        aux = colaDeEspera.Desencolar();
        Agregar(aux->valor);
        if ( aux->hijoIzq != NULL )
            colaDeEspera.Encolar(aux->hijoIzq);
        if ( aux->hijoDer != NULL )
            colaDeEspera.Encolar(aux->hijoDer);
    }
    return *this;
}




template <typename T>
bool ABB<T>::Agregar(const T &valor) {
    return Agregar(valor, raiz);
}

template<typename T>
bool ABB<T>::Eliminar(const T &valor) {
    return Eliminar(valor, raiz);
}


template<typename T>
bool ABB<T>::buscar(const T & valor) const {
    return buscar(valor, raiz) != NULL;
}



template<typename T>
void ABB<T>::ImprimirEnPreOrden() const{
    ImprimirPreorden(raiz);
    cout << "\b\b ";

}

template<typename T>
void ABB<T>::ImprimirAcendiente() const{
    ImprimirEnEntreOrden(raiz);
    cout << "\b\b ";

}

template<typename T>
void ABB<T>::ImprimirDescendiente() const {
    ImprimirDescendiente(raiz);
    cout << "\b\b ";

}

template<typename T>
void ABB<T>::ImprimirEnPostOrden() const{
    ImprimirEnPostOrden(raiz);
    cout << "\b\b ";

}


template<typename T>
void ABB<T>::Vaciar() {
    Podar(raiz);

}

template<typename T>
int ABB<T>::ObtenerNumNodos() {
    return numNodos;
}


template<typename T>
void ABB<T>::ImprimirPorNiveles() const {
    if(raiz == NULL) throw "El arbol est\240 vac\243o";
    Cola<Nodo *> colaNodos;
    Nodo * aux;
    colaNodos.Encolar(raiz);
    while(!colaNodos.EstaVacia()){
        aux = colaNodos.ObtenerPrimero();
        colaNodos.Desencolar();
        cout <<  aux->valor << ", ";
        if(aux->hijoIzq != NULL) colaNodos.Encolar(aux->hijoIzq);
        if(aux->hijoDer != NULL) colaNodos.Encolar(aux->hijoDer);
    }
    cout << "\b\b ";

}

//************************************************
//************** METODOS PRIVADOS ****************
//************************************************

template<typename T>
bool ABB<T>::Agregar(const T &valor, Nodo *&_raiz) {
    if(_raiz == NULL){
        _raiz = new Nodo(valor);
        ++numNodos;
        return true;
    }

    if(valor == _raiz->valor) return false;

    if(valor < _raiz -> valor) return Agregar(valor, _raiz -> hijoIzq);

    else return  Agregar(valor, _raiz -> hijoDer);
}

template<typename T>
void ABB<T>::ImprimirPreorden(Nodo* _raiz) const {
    if(_raiz == NULL){
        return;
    }
    cout << _raiz -> valor << ", ";
    ImprimirPreorden(_raiz -> hijoIzq);
    ImprimirPreorden(_raiz -> hijoDer);

}

template<typename T>
void ABB<T>::ImprimirEnEntreOrden(Nodo *_raiz) const {
    if(_raiz == NULL){
        return;
    }
    ImprimirEnEntreOrden(_raiz -> hijoIzq);
    cout << _raiz -> valor << ", ";
    ImprimirEnEntreOrden(_raiz -> hijoDer);

}

template<typename T>
void ABB<T>::ImprimirEnPostOrden(Nodo *_raiz) const {
    if(_raiz == NULL){
        return;
    }

    ImprimirEnPostOrden(_raiz -> hijoIzq);
    ImprimirEnPostOrden(_raiz -> hijoDer);
    cout << _raiz -> valor << ", ";

}

template<typename T>
void ABB<T>::Podar(Nodo *&_raiz) {
  if(_raiz != NULL){
      Podar(_raiz -> hijoIzq);
      Podar(_raiz-> hijoDer);
      delete _raiz;
      --numNodos;
      _raiz = NULL;
  }
}



template<typename T>
bool ABB<T>::Eliminar(const T &valor, ABB::Nodo *&_raiz) {
    if(_raiz == NULL){
        return false;
    } else{
        if(valor < _raiz->valor){
            return Eliminar(valor, _raiz->hijoIzq);
        }
        else if(valor > _raiz->valor){
            return Eliminar(valor, _raiz->hijoDer);
        } else {
            Nodo * raiz_anterior = _raiz;
            if(_raiz->hijoIzq == NULL){
                _raiz = _raiz->hijoDer;
            } else if(_raiz->hijoDer == NULL){
                _raiz = _raiz->hijoIzq;
            } else {
                IntercambiarPadre(raiz_anterior, raiz_anterior->hijoIzq);
            }
            delete raiz_anterior;
            return true;
        }
    }
}

template<typename T>
void ABB<T>::IntercambiarPadre(ABB::Nodo *&raiz_antigua, ABB::Nodo *&_raiz) {
    if(_raiz->hijoDer != NULL){
        IntercambiarPadre(raiz_antigua, _raiz->hijoDer);
    } else {
        raiz_antigua->valor = _raiz->valor;
        raiz_antigua = _raiz;
        _raiz = _raiz -> hijoIzq;
    }
}

template<typename T>
struct ABB<T>::Nodo *ABB<T>::buscar(const T &valor, ABB::Nodo *_raiz) const {
    if(_raiz == NULL){
        return NULL;
    }
    if(valor < _raiz ->valor) return buscar(valor, _raiz->hijoIzq);
    else if(valor > _raiz->valor) return buscar(valor, _raiz->hijoDer);
    else return _raiz;
}

template<typename T>
void ABB<T>::ImprimirDescendiente(ABB::Nodo *_raiz) const{
    if(_raiz == NULL){
        return;
    }
    ImprimirDescendiente(_raiz -> hijoDer);
    cout <<  _raiz -> valor << ", ";
    ImprimirDescendiente(_raiz -> hijoIzq);


}



#endif //UNTITLED_ABB_H
