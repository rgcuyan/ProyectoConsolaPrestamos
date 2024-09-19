#pragma once
#include "Prestamo.h"
#include <chrono>

using namespace std;

//Herencia de la clase Prestamo a la clase PrestamoPersonal.
class PrestamoPersonal :public Prestamo	
{
private:
	//Propiedades de la clase PrestamoPersonal.
	float interesMensual = 0, cuotaMensual = 0, saldoPendiente = 0;
	int meses = 0, diasTranscurridos = 0;
	//
	chrono::steady_clock::time_point ultimoPago = chrono::steady_clock::now();
public:
	//Metodo para asignarle valores a las propiedades de la clase PrestamoPersonal. (Metodo Set)
	PrestamoPersonal(int capitalInicial, int plazoEnAnios, float tasaInteres);	
	//Metodo para calcular el interes simple. (6.85% anual)
	void calcularInteres() override;
	//metodo para mostrar las propiedades de la clase PrestamoPersonal. (Metodo Get)
	void obtenerPrestamo() override;
	//metodo para obtener el interes
	float obtenerInteres() override;
	//metodo para abonar a capital
	void abonarCapital(float abono) override;
	//metodo para reiniciar el conteo de los dias pendientes.
	void reiniciarDiasTranscurridos() override;
	//Calcula los dias transcurridos.
	void calcularDiasTranscurridos();
	//Metodo para convertir los anios en meses.
	void aniosAMeses(int anios);
	//metodo 
	void mostrarInteres();
	


	~PrestamoPersonal();
};

