#include <iostream>
#include "ABB.h"
int main() {

    try {

        ABB<int> AB;
        cout << "Agregando valores al \240rbol..." << endl;
        AB.Agregar(40);
        AB.Agregar(30);
        AB.Agregar(50);
        AB.Agregar(28);
        AB.Agregar(35);
        AB.Agregar(45);
        AB.Agregar(55);
        AB.Agregar(42);
        AB.Agregar(49);

        cout << "Imprimiendo el \240rbol en el siguiente orden: Por niveles, de forma ascendente, de forma descendete, en preorden y en postorden" << endl;

        AB.ImprimirPorNiveles();
        cout << endl;
        AB.ImprimirAcendiente();
        cout << endl;
        AB.ImprimirDescendiente();
        cout << endl;
        AB.ImprimirEnPreOrden();
        cout << endl;
        AB.ImprimirEnPostOrden();
        cout << endl;

        cout << "El \240rbol actualmente tiene " << AB.ObtenerNumNodos() << " nodos..." << endl;

        int n;

        cout << "Favor de introducir un nodo que quiera buscar: " << endl;
        cin >> n;

        cout << n << (AB.buscar(n) ? " s\241 se encuentra en el \240rbol" : " no se encuentra en el \240rbol");

        cout << endl << "Eliminando el nodo 40 del \240rbol: " << endl;
        AB.Eliminar(40);
        cout << "Imprimiendo por niveles el \240 sin el nodo 40" << endl;
        AB.ImprimirPorNiveles();


    }catch(Excepcion &exc){
        cout << "Error: " << exc.quePaso();
    }catch(bad_alloc &exc){
        cout << "Error en la asignaci\242n de memoria" << endl;
    }catch(...){
        cout << "Ocurri\242 un error inesperado" << endl;
    }

    system("pause");
    return 0;
}