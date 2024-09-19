#include <iostream>
#include "Prestamo.h"
#include "PrestamoPersonal.h"
#include "PrestamoHipotecario.h"
#include "PrestamoAutomovil.h"
#include <chrono>
#include <thread>
#include <vector>

using namespace std;

vector<Prestamo*> prestamos;

void agregarPrestamoPersonal() {
	int capitalInicial, plazoAnios;
	const float interesPersonal = 0.0685;

	cout << "\n___-Nuevo Prestamo personal-___" << endl;
	cout << "Ingrese el monto del prestamo: ";
	cin >> capitalInicial;
	cout << "Ingrese el plazo en anios: ";
	cin >> plazoAnios;
	PrestamoPersonal* nuevoPrestamoPersonal = new PrestamoPersonal(capitalInicial, plazoAnios, interesPersonal);
	prestamos.push_back(nuevoPrestamoPersonal);
	cout << "\nPrestamo Personal agregado exitosamente!" << endl;
}

void agregarPrestamoHipotecario() {
	int capitalInicial, plazoAnios;
	const float interes = 0.0539f; //Diferencial + Euribor

	cout << "\n___-Nuevo Prestamo Hipotecario-___" << endl;
	cout << "Ingrese el monto del prestamo: ";
	cin >> capitalInicial;
	cout << "Ingrese el plazo en anios: ";
	cin >> plazoAnios;
	
	PrestamoHipotecario* nuevoPrestamoHipotecario = new PrestamoHipotecario(capitalInicial, plazoAnios, interes);
	prestamos.push_back(nuevoPrestamoHipotecario);
	cout << "\nPrestamo Hipotecario agregado exitosamente!" << endl;
}

void agregarPrestamoAutomovil() {
	
	int capitalInicial, plazoMeses;
	const float interes = 0.0915f;

	cout << "\n___-Nuevo Prestamo Automovil-___" << endl;
	cout << "Ingrese el monto del prestamo: ";
	cin >> capitalInicial;
	cout << "Ingrese el plazo en meses: ";
	cin >> plazoMeses;

	PrestamoAutomovil* nuevoPrestamoAutomovil = new PrestamoAutomovil(capitalInicial, plazoMeses, interes);
	prestamos.push_back(nuevoPrestamoAutomovil);
	cout << "\nPrestamo Automovilistico agregado exitosamente!" << endl;
}

void agregarPrestamo() {
	int opcionAgregarPrestamo;
	bool validacion = false;
	do
	{
		cout << "\nQue tipo de prestamo desea agregar?\n1. Prestamo personal (simple 6.85%).\n2. Prestamo hipotecario (compuesto  banco 4% y FHA 1.36%).\n3. Prestamo de automovil (anual 9.15%).\n4. Salir." << endl;
		cin >> opcionAgregarPrestamo;
		switch (opcionAgregarPrestamo)
		{
		case 1:
			agregarPrestamoPersonal();
			validacion = false;
			break;
		case 2:
			agregarPrestamoHipotecario();
			validacion = false;
			break;
		case 3:
			agregarPrestamoAutomovil();
			validacion = false;
			break;
		case 4:
			validacion = false;
			break;
		default:
			cout << "Opcion ingresada invalida!" << endl;
			validacion = true;
			break;
		}
	} while (validacion);
}

void eliminarPrestamo() {
	if (!prestamos.empty())
	{
		int index;
		cout << "Ingrese el indice del prestamo a eliminar: ";
		cin >> index;
		if (index >= 0 && index < prestamos.size()) {
			delete prestamos[index];
			prestamos.erase(prestamos.begin() + index);
			cout << "\nPrestamo eliminado exitosamente!" << endl;
		}
		else {
			cout << "Indice invalido!" << endl;
		}
	}
	else {
		cout << "No hay prestamos para mostrar." << endl;
	}
}

void informacionPrestamo() {
	if (!prestamos.empty()) {
		int index;
		cout << "Ingrese el indice del prestamo a ver: ";
		cin >> index;
		if (index >= 0 && index < prestamos.size())
		{
			cout << "\n___-Informacion sobre el Prestamo #" << index << "-___" << endl;
			prestamos[index]->obtenerPrestamo();
		}
		else
		{
			cout << "Indice invalido!" << endl;
		}
	}
	else
	{
		cout << "No hay prestamos disponibles." << endl;
	}
}

void abonarCapital() {
	if (!prestamos.empty()) {
		int index;
		cout << "Ingrese el indice del prestamo a abonar: ";
		cin >> index;
		if (index >= 0 && index < prestamos.size())
		{
			cout << "Ingrese el monto a abonar: Q";
			float abono; cin >> abono;
			prestamos[index]->abonarCapital(abono);
			cout << "\nEl monto fue abonado exitosamente!" << endl;
		}
		else
		{
			cout << "Indice invalido!" << endl;
		}
	}
	else
	{
		cout << "No hay prestamos disponibles." << endl;
	}
}

void pagarInteres() {
	if (!prestamos.empty()) {
		int index;
		cout << "Ingrese el indice del prestamo: ";
		cin >> index;

		float abono = 0.00f;
		if (index >= 0 && index < prestamos.size())
		{
			float interes = prestamos[index]->obtenerInteres();
			//Redondear a 2 decimales
			interes = round(interes * 100.0f) / 100.0f;
			if (interes > 0.01) {
				cout << "El interes a pagar es de: Q" << interes << endl;
				cout << "Ingresar monto: Q";
				cin >> abono;
				if (abono == interes) {
					prestamos[index]->reiniciarDiasTranscurridos();
					cout << "\nEl interes fue solventado exitosamente!" << endl;
				}
				else
				{
					cout << "\nError! El monto debe ser igual al interes!" << endl;
				}
			}
		}
		else
		{
			cout << "\nIndice invalido!" << endl;
		}
	}
	else
	{
		cout << "No hay prestamos disponibles." << endl;
	}
}

void gestionarPrestamo() {
	int opcionGestionPrestamo;
	do
	{
		cout << "\n_____-Gestion de Prestamos-_____" << endl;
		cout << "1. Ver informacion de un prestamo.\n2. Abonar a capital.\n3. Pago de Interes.\n4. Salir\nEscriba un numero: ";
		cin >> opcionGestionPrestamo;
		switch (opcionGestionPrestamo)
		{
		case 1:
			informacionPrestamo();
			break;
		case 2:
			abonarCapital();
			break;
		case 3:
			pagarInteres();
			break;
		case 4:
			break;
		default:
			cout << "Opcion ingresada invalida!" << endl;
			break;
		}
	} while (opcionGestionPrestamo != 4);
}

void mostrarPrestamos() {
	if (!prestamos.empty()) {
		for (int i = 0; i < prestamos.size(); ++i) {
			cout << "\nPrestamo #" << i << ":" << endl;

			prestamos[i]->obtenerPrestamo();
		}
	}
	else {
		cout << "No hay prestamos para mostrar." << endl;
	}
}

void menu()
{
	int opcionMenuPrincipal;
	do
	{
		cout << endl;
		cout << "\n___________________-Menu-___________________" << endl;
		cout << "1. Agregar un nuevo prestamo.\n2. Eliminar un prestamo.\n3. Gestionar un prestamo.\n4. Mostrar todos los prestamos.\n5. Salir.\nEscriba un numero: ";
		cin >> opcionMenuPrincipal;
		switch (opcionMenuPrincipal)
		{
		case 1:
			agregarPrestamo();
			break;
		case 2:
			eliminarPrestamo();
			break;
		case 3:
			gestionarPrestamo();
			break;
		case 4:
			mostrarPrestamos();
			break;
		case 5:
			cout << "Saliendo del programa!" << endl;
			break;
		default:
			cout << "Opcion ingresada invalida!" << endl;
			break;
		}


	} while (opcionMenuPrincipal != 5);
}

int main()
{
	menu();
	return 0;
}