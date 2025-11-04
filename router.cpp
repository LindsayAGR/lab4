#include "router.h"
#include <iostream>
using namespace std;

// Constructor con name

Router::Router(const string& nombre) {
    this->nombre = nombre;
}


// Devuelve el nombre del router

string Router::getNombre() const {
    return nombre;
}

 // Devuelve todos los vecinos del router

map<string, int> Router::getVecinos() const {
    return vecinos;
}


// Devuelve las rutas calculadas (resultado de Dijkstra)

map<string, pair<int, vector<string>>> Router::getRutas() const {
    return rutas;
}


// Agrega o actualiza un vecino directo

void Router::agregarVecino(const string& destino, int costo) {
    vecinos[destino] = costo; // si ya existe, actualiza el costo
    cout << "Vecino agregado: " << destino << " (costo " << costo << ")\n";
}


// Elimina un vecino directo del router

void Router::eliminarVecino(const string& destino) {
    if (vecinos.erase(destino))
        cout << "Vecino " << destino << " eliminado.\n";
    else
        cout << "El vecino " << destino << " no existe.\n";
}


// Guarda una ruta hacia un destin con su cost y camin

void Router::setRuta(const string& destino, int costo, const vector<string>& camino) {
    rutas[destino] = {costo, camino};
}


// Muestra la tabla de enrutamiento (rutas más cortas)

void Router::mostrarTabla() const {
    cout << "\nTabla de enrutamiento del router " << nombre << ":\n";
    cout << "-----------------------------------------\n";
    cout << "Destino\tCosto\tCamino\n";

    for (const auto& [destino, datos] : rutas) {
        int costo = datos.first;
        const vector<string>& camino = datos.second;

        cout << destino << "\t" << (costo == INT_MAX ? -1 : costo) << "\t";

        for (size_t i = 0; i < camino.size(); ++i) {
            cout << camino[i];
            if (i < camino.size() - 1) cout << " -> ";
        }
        cout << endl;
    }
    cout << "-----------------------------------------\n";
}
