#ifndef ENLACE_H
#define ENLACE_H

#include <string>
#include <iostream>
using namespace std;


class Enlace {
private:
    // --- Atributos ---
    string destino;  // Nombre del router destino
    int costo;       // Costo del enlace

public:
    // --- Constructores ---
    Enlace() = default;                      // Constructor vacío
    Enlace(const string& destino, int costo); // Constructor con parámetros

    // --- Métodos de acceso ---
    string getDestino() const; // Devuelve el nombre del destino
    int getCosto() const;      // Devuelve el costo del enlace

    // --- Métodos de modificación ---
    void setDestino(const string& destino); // Cambia el destino
    void setCosto(int costo);               // Cambia el costo
};

#endif // ENLACE_H
