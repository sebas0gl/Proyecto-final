#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

// Declaración de funciones
void capturarDatos(std::string&, std::string&, std::string&, int&, int&);
void capturarNotas(std::vector<float>&);
float calcularPromedio(const std::vector<float>&);
void mostrarResultados(const std::vector<std::string>&, const std::vector<std::string>&, const std::vector<int>&, const std::vector<int>&, const std::vector<float>&);

int main() {
    int cantidad;
    std::vector<std::string> nombres;
    std::vector<std::string> apellidos;
    std::vector<int> ciclos;
    std::vector<int> cedulas;
    std::vector<float> promedios;

    do {
        std::cout << "¿Cuántos alumnos desea evaluar?: ";
        std::cin >> cantidad;
        if(std::cin.fail() || cantidad <= 0) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Entrada inválida. Ingrese un número mayor a 0.\n";
        }
    } while (cantidad <= 0);

    for (int i = 0; i < cantidad; ++i) {
        std::string nombre, apellido1, apellido2;
        int ciclo, cedula;
        std::vector<float> notas;

        std::cout << "\n********** Alumno #" << (i + 1) << " **********\n";

        capturarDatos(nombre, apellido1, apellido2, ciclo, cedula);
        capturarNotas(notas);
        float promedio = calcularPromedio(notas);

        nombres.push_back(nombre + " " + apellido1 + " " + apellido2);
        ciclos.push_back(ciclo);
        cedulas.push_back(cedula);
        promedios.push_back(promedio);
    }

    mostrarResultados(nombres, apellidos, ciclos, cedulas, promedios);

    return 0;
}