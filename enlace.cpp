#include "enlace.h"
#include <iostream>
using namespace std;

// Constructor con parámetros
Enlace::Enlace(const string& destino, int costo) {
    this->destino = destino;
    this->costo = costo;
}


// Devuelve el nombre del destino

string Enlace::getDestino() const {
    return destino;
}

// Devuelve el costo del enlace

int Enlace::getCosto() const {
    return costo;
}


// Cambia el destino del enlace

void Enlace::setDestino(const string& destino) {
    this->destino = destino;
}

// Cambia el costo del enlace

void Enlace::setCosto(int costo) {
    this->costo = costo;
}
