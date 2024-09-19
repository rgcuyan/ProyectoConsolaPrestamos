#include "PrestamoAutomovil.h"
#include "Prestamo.h"
#include <math.h>
#include <iostream>
#include <iomanip> 

using namespace std;

PrestamoAutomovil::PrestamoAutomovil(int capitalInicial, int plazoMeses, float tasaInteres)
	:Prestamo(capitalInicial, plazoMeses, tasaInteres) {
	calcularInteres();
	this->capitalResultante = this->capitalInicial;
}

void PrestamoAutomovil::calcularInteres() {
	//Cuota Mensual = (P * i) / (1 - (1 + i) ^ -n)
	this->cuotaMensual = (this->capitalInicial * (this->tasaInteres/12)) /(1 - pow(1 + (this->tasaInteres / 12), -(this->plazoEnAnios)));
}

void PrestamoAutomovil::obtenerPrestamo() {
	Prestamo::obtenerPrestamo();
	cout << std::fixed << std::setprecision(2);
	cout << "Su saldo pendiente es de: Q" << this->capitalResultante << endl;
	cout << "Su cuota mensual es de: Q" << this->cuotaMensual << endl;
}

void PrestamoAutomovil::abonarCapital(float abono) {
	this->capitalResultante -= abono;
}

float PrestamoAutomovil::obtenerInteres() {
	cout << "No es posible pagar directamente al interes en los prestamos automovilisticos!" << endl;
	return 0.00f;
}

PrestamoAutomovil::~PrestamoAutomovil() {
	cout << "Destructor PrestamoAutomovil: Memoria liberada" << endl;
}