#pragma once
#include "Prestamo.h"
#include <chrono>

class PrestamoAutomovil:public Prestamo
{
private:
	float cuotaMensual = 0;
	int capitalResultante = 0;
public:
	PrestamoAutomovil(int capitalInicial, int plazoMeses, float tasaInteres);
	//
	void calcularInteres() override;
	//
	void obtenerPrestamo() override;
	//
	void abonarCapital(float abono) override;
	//
	float obtenerInteres() override;
	//
	~PrestamoAutomovil();
};

