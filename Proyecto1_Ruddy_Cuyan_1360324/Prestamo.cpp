#include "Prestamo.h"
#include <iostream>

using namespace std;


Prestamo::Prestamo() {}

Prestamo::Prestamo(int capitalInicial, int plazoEnAnios, float tasaInteres) {
	this->capitalInicial = capitalInicial;
	this->plazoEnAnios = plazoEnAnios;
	this->tasaInteres = tasaInteres;
}

void Prestamo::obtenerPrestamo() {
	cout << "El monto inicial del prestamo es de: Q" << capitalInicial << endl;
	cout << "El plazo del prestamo en anios es de: " << plazoEnAnios << " anios" << endl;
	cout << "El interes del prestamo es de: " << (tasaInteres*100) <<"%" << endl;
}

void Prestamo::calcularInteres() {}

void Prestamo::abonarCapital(float abono) {}

float Prestamo::obtenerInteres() {
	return 0;
}

void Prestamo::reiniciarDiasTranscurridos() {}

Prestamo::~Prestamo() {
	cout << "DestructorPrestamo: Memoria liberada" << endl;
}