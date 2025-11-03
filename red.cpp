#include "red.h"
#include <iostream>

using namespace std;

// Agrega un nuevo router a la red

void Red::agregarRouter(const string& nombre) {
    if (routers.find(nombre) == routers.end()) {
        routers[nombre] = Router(nombre);
        cout << "Router " << nombre << " agregado a la red.\n";
    } else {
        cout << "El router " << nombre << " ya existe.\n";
    }
}

// Crea un enlace entre dos routers con un costo

void Red::agregarEnlace(const string& origen, const string& destino, int costo) {
    agregarRouter(origen);
    agregarRouter(destino);
    
    routers[origen].agregarVecino(destino, costo);
    routers[destino].agregarVecino(origen, costo);
    
    cout << "Enlace agregado entre " << origen << " y " << destino
         << " con costo " << costo << ".\n";
}


// Verifica si un router existe en la red

bool Red::existeRouter(const string& nombre) const {
    return routers.find(nombre) != routers.end();
}


// Devuelve el mapa de routers

void Red::mostrarTablaRouter(const string& nombre) {
    if (routers.count(nombre)) {
        routers[nombre].mostrarTabla();
    } else {
        cout << "El router no existe en la red." << endl;
    }
}


// Algoritmo de Dijkstra
// Calcula los caminos más cortos desde un router orige

void Red::calcularDijkstraDesde(const string& origen) {
    if (!existeRouter(origen)) {
        cout << "El router " << origen << " no existe en la red.\n";
        return;
    }
    
    // Inicializar estructuras
    map<string, int> dist;
    map<string, string> previo;
    set<string> visitados;
    
    for (auto& r : routers)
        dist[r.first] = INT_MAX;
    
    dist[origen] = 0;
    
    while (visitados.size() < routers.size()) {
        // Encontrar el router con menor distancia no visitado
        string actual;
        int minDist = INT_MAX;
        for (auto& r : dist) {
            if (visitados.count(r.first) == 0 && r.second < minDist) {
                actual = r.first;
                minDist = r.second;
            }
        }
        
        if (minDist == INT_MAX)
            break;
        
        visitados.insert(actual);
        
        // Actualizar distancias a los vecinos del router actual
        for (auto& [vecino, costo] : routers[actual].getVecinos()) {
            if (dist[actual] + costo < dist[vecino]) {
                dist[vecino] = dist[actual] + costo;
                previo[vecino] = actual;
            }
        }
    }
    
    // Guardar rutas calculadas en el router origen
    for (auto& [destino, d] : dist) {
        vector<string> camino;
        string temp = destino;
        
        while (temp != origen && previo.count(temp)) {
            camino.insert(camino.begin(), temp);
            temp = previo[temp];
        }
        
        if (temp == origen)
            camino.insert(camino.begin(), origen);
        
        routers[origen].setRuta(destino, d, camino);
    }
    
    cout << "Tablas de enrutamiento actualizadas desde " << origen << ".\n";
}

// Muestra el camino más corto entre dos routers


void Red::caminoMasCorto(const string& origen, const string& destino) {
    if (!existeRouter(origen) || !existeRouter(destino)) {
        cout << "Alguno de los routers no existe.\n";
        return;
    }
    
    calcularDijkstraDesde(origen);
    
    auto rutas = routers[origen].getRutas();
    if (rutas.find(destino) != rutas.end()) {
        auto [costo, camino] = rutas[destino];
        cout << "\nCamino más corto desde " << origen << " hasta " << destino << ":\n";
        for (size_t i = 0; i < camino.size(); ++i) {
            cout << camino[i];
            if (i < camino.size() - 1)
                cout << " -> ";
        }
        cout << "\nCosto total: " << costo << "\n";
    } else {
        cout << "No hay camino disponible entre " << origen << " y " << destino << ".\n";
    }
}
