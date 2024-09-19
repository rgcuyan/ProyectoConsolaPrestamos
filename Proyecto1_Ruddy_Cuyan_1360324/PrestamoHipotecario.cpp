#include "PrestamoHipotecario.h"
#include <iostream>
#include <iomanip> 

using namespace std;

PrestamoHipotecario::PrestamoHipotecario(int capitalInicial, int plazoEnAnios, float tasaInteres)
	:Prestamo(capitalInicial, plazoEnAnios, tasaInteres) 
{
	this->capitalPendiente = capitalInicial;
	calcularInteres();
}

void PrestamoHipotecario::calcularInteres() {
	//Intereses = Capital pendiente x (Euríbor + Diferencial) / 12
	this->interesMensual = this->capitalPendiente * (this->tasaInteres) / 12;
	this->capitalPendiente += this->interesMensual;
	//cout << this->tasaInteres << this->capitalPendiente;
}

void PrestamoHipotecario::obtenerPrestamo() {
	Prestamo::obtenerPrestamo();
	cout << std::fixed << std::setprecision(2);
	//cout << "El interes a pagar es de: Q" << this->interesMensual << endl;
	cout << "El saldo pendiente a pagar es de: Q" << this->capitalPendiente << endl;
}

void PrestamoHipotecario::abonarCapital(float abono) {
	calcularInteres();
	this->capitalPendiente -= abono;
}

float PrestamoHipotecario::obtenerInteres() {
	cout << "No es posible pagar directamente al interes en los prestamos hipotecarios!" << endl;
	return 0.00f;
}

PrestamoHipotecario::~PrestamoHipotecario() {
	cout << "Destructor PrestamoHipotecario: Memoria liberada" << endl;
}