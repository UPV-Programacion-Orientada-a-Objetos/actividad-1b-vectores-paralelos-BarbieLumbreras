#include <iostream> 
#include <string>   
using namespace std;

// Declaramos los arreglos para almacenar la información de los productos
int codigo[100];   
string nombre[100];
float precio[100]; 
int cantidad[100]; 

int main() {
    // Inicialización de los productos 
    codigo[0] = 101;
    codigo[1] = 102;
    codigo[2] = 103;
    codigo[3] = 104;
    codigo[4] = 105;

    nombre[0] = "Martillo";
    nombre[1] = "Destornillador";
    nombre[2] = "Taladro";
    nombre[3] = "Sierra";
    nombre[4] = "Llave inglesa";

    precio[0] = 15.99;
    precio[1] = 7.49;
    precio[2] = 45.00;
    precio[3] = 22.75;
    precio[4] = 12.30;

    cantidad[0] = 50;
    cantidad[1] = 80;
    cantidad[2] = 30;
    cantidad[3] = 20;
    cantidad[4] = 60;

    int opcion = 0; //  Opción del menú seleccionada por el usuario

    // Bucle que mantiene el menú activo hasta que el usuario elija salir 
    while (opcion != 5) {
        // Mostramos el menú principal
        cout << "--- Bienvenido al Sistema de Inventario de 'El Martillo' ---\n";
        cout << "\nSeleccione una opcion:\n";
        cout << "1. Consultar producto\n";
        cout << "2. Actualizar inventario\n";
        cout << "3. Generar reporte\n";
        cout << "4. Producto más caro\n";
        cout << "5. Salir\n";

        cin >> opcion; 

        switch (opcion) {
            case 1: {
                // Consultar producto por código
                int c;
                cout << "Ingrese el código del producto a consultar: \n";
                cin >> c;
                bool encontrado = false; // Bandera para saber si el producto se encontró

                for (int i = 0; i < 5; i++) {
                    if (codigo[i] == c) {
                        cout << "Información del Producto:\n";
                        cout << "Código: " << codigo[i] << "\n";
                        cout << "Nombre: " << nombre[i] << "\n";
                        cout << "Precio unitario: $" << precio[i] << "\n";
                        cout << "Cantidad en inventario: " << cantidad[i] << "\n";
                        encontrado = true;
                        break; // Ya lo encontramos, no seguimos buscando
                    }
                }

                if (!encontrado) {
                    cout << "Producto no encontrado.\n";
                }
                break; 
            }

            case 2: {
                // Actualizar cantidad en inventario
                int c;
                cout << "Ingrese el código del producto a actualizar: \n";
                cin >> c;
                bool encontrado = false;

                for (int i = 0; i < 5; i++) {
                    if (codigo[i] == c) {
                        cout << "Ingrese la cantidad a sumar/restar (puede ser negativa): ";
                        int cambio;
                        cin >> cambio;
                        if (cantidad[i] + cambio >= 0) { // Validamos que no quede negativo
                            cantidad[i] += cambio;
                            cout << "Inventario actualizado. Nueva cantidad: " << cantidad[i] << "\n";
                        } else {
                            cout << "Error: la cantidad no puede quedar negativa.\n";
                        }
                        encontrado = true;
                        break;
                    }
                }

                if (!encontrado) {
                    cout << "Producto no encontrado.\n";
                }
                break;
            }

            case 3:
                // Generar reporte de inventario completo
                cout << "Reporte de Inventario.\n";
                cout << "Código    | Nombre            | Precio    | Cantidad\n";
                cout << "-----------------------------------------------\n";
                for (int i = 0; i < 5; i++) {
                    cout << codigo[i] << " | " << nombre[i] << " | $" << precio[i] << " | " << cantidad[i] << "\n";
                }
                break;

            case 4:
                // Mostrar el producto con el precio más alto
                float mayorPrecio = precio[0];
                int indiceMayor = 0;
                for (int i = 1; i < 5; i++) {
                    if (precio[i] > mayorPrecio) {
                        mayorPrecio = precio[i];
                        indiceMayor = i;
                    }
                }
                cout << "Producto más caro:\n";
                cout << "Código: " << codigo[indiceMayor] << "\n";
                cout << "Nombre: " << nombre[indiceMayor] << "\n";
                cout << "Precio unitario: $" << precio[indiceMayor] << "\n";
                cout << "Cantidad en inventario: " << cantidad[indiceMayor] << "\n";
                break;

            case 5:
                cout << "Saliendooooo\n";
                break;

            default:
                cout << "Opción no válida.\n";
                break;
        }
    }

    return 0;
}
