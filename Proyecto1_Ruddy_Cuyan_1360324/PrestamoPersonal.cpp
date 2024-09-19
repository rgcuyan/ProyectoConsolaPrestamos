#include "PrestamoPersonal.h"
#include "Prestamo.h"
#include <iostream>
#include <iomanip> 
#include <chrono>
#include <string>

using namespace std;

PrestamoPersonal::PrestamoPersonal(int capitalInicial, int plazoEnAnios, float tasaInteres)
	:Prestamo(capitalInicial, plazoEnAnios, tasaInteres) {
	calcularInteres();
	this->saldoPendiente = this->capitalInicial;
}

void PrestamoPersonal::reiniciarDiasTranscurridos() {
	auto ahora = chrono::steady_clock::now();
	ultimoPago = ahora;
}
	
void PrestamoPersonal::calcularDiasTranscurridos() {
	auto ahora = chrono::steady_clock::now();
	auto duracion = chrono::duration_cast<chrono::seconds>(ahora - ultimoPago);
	cout << "Dias: " << duracion.count() << endl;
	this->diasTranscurridos = duracion.count();
	//ultimoPago = ahora;
}

void PrestamoPersonal::aniosAMeses(int anios) {
	this->meses = anios * 12;
}

void PrestamoPersonal::calcularInteres() {
	PrestamoPersonal::calcularDiasTranscurridos();
	this->interesMensual = (capitalInicial * tasaInteres * diasTranscurridos) / 360;
	//cout << capitalInicial <<tasaInteres << diasTranscurridos;
	PrestamoPersonal::aniosAMeses(plazoEnAnios);
	this->cuotaMensual = interesMensual + (capitalInicial / meses);
}

void PrestamoPersonal::obtenerPrestamo() {
	//PrestamoPersonal::calcularInteres();
	Prestamo::obtenerPrestamo();
	cout << fixed << setprecision(2);
	cout << "El interes a pagar es de: Q" << this->interesMensual << endl;
	cout << "El saldo pendiente es de: Q" << this->saldoPendiente << endl;
	//cout << "La cuota mensual que debe pagar es de: Q" << this->cuotaMensual << endl;
}

float PrestamoPersonal::obtenerInteres() {
	calcularInteres();
	return this->interesMensual;
}

void PrestamoPersonal::abonarCapital(float abono) {
	this->saldoPendiente -= abono;
}


PrestamoPersonal::~PrestamoPersonal() {
	cout << "Destructor PrestamoPersonal: Memoria liberada" << endl;
}