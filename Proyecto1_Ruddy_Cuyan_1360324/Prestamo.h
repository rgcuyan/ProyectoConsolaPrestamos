#pragma once
class Prestamo
{
protected:	//Propiedades de la clase padre (Prestamo).
	int capitalInicial = 0, plazoEnAnios = 0;
	float tasaInteres = 0.00f;

public:
	Prestamo();
	Prestamo(int capitalInicial, int plazoEnAnios, float tasaInteres);	//Metodo para asignarle valores a las propiedades de la clase Prestamo. (Metodo Set)
	virtual void obtenerPrestamo();	//metodo para mostrar las propiedades de la clase Prestamo. (Metodo Get)
	virtual void calcularInteres();
	virtual void abonarCapital(float abono);
	virtual float obtenerInteres();
	virtual void reiniciarDiasTranscurridos();
	~Prestamo();
};