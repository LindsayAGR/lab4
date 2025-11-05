#include <iostream>
#include "red.h"
#include "router.h"
#include "enlace.h"

using namespace std;

int main() {
    Red red;
    int opcion;
    string origen, destino;
    int costo;

    do {
        cout << "\n=========== MENU PRINCIPAL ===========\n";
        cout << "1. Agregar router\n";
        cout << "2. Agregar enlace\n";
        cout << "3. Calcular camino más corto (Dijkstra)\n";
        cout << "4. Mostrar tabla de enrutamiento de un router\n";
        cout << "0. Salir\n";
        cout << "=====================================\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingrese el nombre del router: ";
            cin >> origen;
            red.agregarRouter(origen);
            break;

        case 2:
            cout << "Ingrese el router origen: ";
            cin >> origen;
            cout << "Ingrese el router destino: ";
            cin >> destino;
            cout << "Ingrese el costo del enlace: ";
            cin >> costo;
            red.agregarEnlace(origen, destino, costo);
            break;

        case 3:
            cout << "Ingrese el router origen: ";
            cin >> origen;
            cout << "Ingrese el router destino: ";
            cin >> destino;
            red.caminoMasCorto(origen, destino);
            break;

        case 4:
            cout << "Ingrese el router que desea visualizar: ";
            cin >> origen;
            red.mostrarTablaRouter(origen);

            break;

        case 0:
            cout << "Saliendo del programa...\n";
            break;

        default:
            cout << "Opción inválida. Intente de nuevo.\n";
        }

    } while (opcion != 0);

    return 0;
}
