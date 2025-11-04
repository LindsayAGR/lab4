#ifndef ROUTER_H
#define ROUTER_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;


class Router {
private:
    // --- Atributos ---
    string nombre;
    map<string, int> vecinos;  // Vecinos directos con su costo
    map<string, pair<int, vector<string>>> rutas;  // Destino -> (costo total, camino)

public:
    // --- Constructores ---
    Router() = default;                // Constructor vacío
    Router(const string& nombre);      // Constructor con nombre

    // --- Métodos de acceso ---
    string getNombre() const;  // Devuelve el nombre del router
    map<string, int> getVecinos() const;  // Devuelve los vecinos del router
    map<string, pair<int, vector<string>>> getRutas() const;  // Devuelve las rutas calculadas

    // --- Métodos de modificación ---
    void agregarVecino(const string& destino, int costo);  // Agrega o actualiza un enlace directo
    void eliminarVecino(const string& destino);            // Elimina un enlace directo
    void setRuta(const string& destino, int costo, const vector<string>& camino);  // Guarda una ruta

    // --- Métodos de visualización ---
    void mostrarTabla() const;  // Muestra las rutas almacenadas en el router
};

#endif // ROUTER_H
