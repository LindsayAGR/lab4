#ifndef RED_H
#define RED_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <climits>
#include "router.h"   // Incluimos la clase Router

using namespace std;


class Red {
private:
    // Lista de routers identificados por su nombre
    map<string, Router> routers;

public:
    // --- Constructores ---
    Red() = default;

    // --- Métodos principales ---

    // Agrega un nuevo router a la red
    void agregarRouter(const string& nombre);

    // Crea un enlace (conexión) entre dos routers con un costo determinado
    void agregarEnlace(const string& origen, const string& destino, int costo);

    // Aplica el algoritmo de Dijkstra desde un router origen
    void calcularDijkstraDesde(const string& origen);

    // Muestra el camino más corto entre dos routers
    void caminoMasCorto(const string& origen, const string& destino);

    // --- Métodos auxiliares ---
    // Verifica si un router existe en la red
    bool existeRouter(const string& nombre) const;

    // Devuelve el mapa completo de routers
void mostrarTablaRouter(const string& nombre);
};

#endif // RED_H
