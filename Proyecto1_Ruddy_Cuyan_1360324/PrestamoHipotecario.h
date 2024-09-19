#pragma once
#include "Prestamo.h"
#include <chrono>

using namespace std;

class PrestamoHipotecario : public Prestamo
{
private:
	float interesMensual = 0.00f, capitalPendiente = 0.00f;
public:
	PrestamoHipotecario(int capitalInicial, int plazoEnAnios, float tasaInteres);
	//
	void calcularInteres() override;
	//
	void obtenerPrestamo() override;
	//
	void abonarCapital(float abono) override;
	//
	float obtenerInteres() override;
	//
	~PrestamoHipotecario();
};

