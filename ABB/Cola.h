//
// Created by Rodrigo Calles on 2020-11-10.
//

#ifndef UNTITLED_COLA_H
#define UNTITLED_COLA_H

#include "Excepcion.h"

template<typename T>
class Cola {

public:
    /**
     * @brief Constructor de la clase.
     */
    Cola();

    /**
     * @brief Destructor de la clase
     */
    ~Cola();

    /**
     * @brief Constructor de copias de la clase
     * @param C Una referencia a una cola
     */
    Cola(const Cola<T> &C);

    /**
     * @brief El operador igual sobrecargado para copiar los elementos de una cola a otra
     * @param C La referencia a otra cola
     * @return Regresa una cola con los elementos de otra
     */
    Cola<T> & operator=(const Cola<T> &C);

    /**
     * @brief Método para agregar un elemento al final de la cola
     * @param valor el valor que tendrá el elemento que se agregará a la cola
     */
    void Encolar(const T &valor);

    /**
     * @brief Método para eliminar el elemento al frente de la cola
     */
    void Desencolar();

    /**
     * @brief Método para obtener el valor del elemento al inicio de la cola.
     * @return El valor del elemento al frente de la cola.
     */
    T ObtenerPrimero();

    /**
     * @brief Método para conocer el elemento al final de la cola.
     * @return El valor del elemento al final de la cola
     */
    unsigned ObtenerFinal();

    /**
     * @brief Método para conocer si la cola está vacía o no
     * @return Un valor booleano que nos indica true si está vacía o false si tiene elemento
     */
    bool EstaVacia() const ;

    /**
     * @brief Método para quitar a todos los elementos de la cola
     */
    void Vaciar();

    /**
     * @brief Método para obtener el tamaño de la cola
     */
    unsigned ObtenerTam();

    /**
     * @brief Método para imprimir la cola
     */
    void imprimir();


private:
    struct Elemento{
        T valor;
        Elemento * sig;
        Elemento(T v, Elemento *sig = NULL):valor(v), sig(sig){}
    };
    Elemento *fondo;
    int numELem;

};

// Constructor
template <typename T>
Cola<T>::Cola(): fondo(NULL), numELem(0){
}


// Constructor de copias
template <typename T>
Cola<T>::Cola(const Cola<T> &C): fondo(NULL), numELem(0) {
    *this = C;
}

template <typename T>
Cola<T> & Cola<T>::operator=(const Cola<T> &C) {
    if(this == &C) return *this;
    Vaciar();
    if(!C.EstaVacia()){
        Elemento *aux = C.fondo->sig;
        do{
            Encolar(aux->valor);
            aux = aux->sig;
        }while(aux != C.fondo->sig);
    }
    return *this;
}

// Destructor
template <typename T>
Cola<T>::~Cola() {
    Vaciar();
}

template <typename T>
void Cola<T>::Encolar(const T &valor) {

    Elemento *nuevo = new Elemento(valor, EstaVacia() ? NULL : fondo->sig);

    EstaVacia() ? nuevo->sig = nuevo : fondo->sig = nuevo;

    fondo = nuevo;

    ++numELem;
}

template <typename T>
void Cola<T>::Desencolar() {
    if(EstaVacia()) throw Excepcion("Está vacia");
    Elemento * aux = fondo -> sig;
    numELem == 1 ? fondo = NULL : fondo->sig = aux->sig;
    delete aux;
    --numELem;
}

template <typename T>
unsigned Cola<T>::ObtenerTam() {
    return numELem;
}

template <typename T>
unsigned Cola<T>::ObtenerFinal(){
    return fondo -> valor;
}

template <typename T>
T Cola<T>::ObtenerPrimero() {
    return fondo -> sig -> valor;
}


template <typename T>
bool Cola<T>::EstaVacia() const {
    return fondo ==  NULL;
}

template <typename T>
void Cola<T>::Vaciar() {
    while(!EstaVacia()){
        Desencolar();
    }
}

// Función imprimir para pruebas
template <typename T>
void Cola<T>::imprimir() {
    if(EstaVacia()) std::cout << "Cola Vac\241a" << std::endl;
    else{
        Elemento *aux = fondo -> sig;
        do{
            std::cout << "Cliente: " << aux->valor << " <- ";
            aux = aux ->sig;
        }while(aux != fondo ->sig);
        std::cout << "\b\b\b   " <<  std::endl;
    }
}




#endif //UNTITLED_COLA_H
