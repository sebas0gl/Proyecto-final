#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

// Declaración de funciones
void capturarDatos(std::string&, std::string&, std::string&, int&, int&);
void capturarNotas(std::vector<float>&);
float calcularPromedio(const std::vector<float>&);
void mostrarResultados(const std::vector<std::string>&, const std::vector<int>&, const std::vector<int>&, const std::vector<float>&);

// Función principal
int main() {
    int cantidad;
    std::vector<std::string> nombresCompletos;
    std::vector<int> ciclos;
    std::vector<int> cedulas;
    std::vector<float> promedios;

    do {
        std::cout << "¿Cuántos alumnos desea evaluar?: ";
        std::cin >> cantidad;
        if (std::cin.fail() || cantidad <= 0) {
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

        nombresCompletos.push_back(nombre + " " + apellido1 + " " + apellido2);
        ciclos.push_back(ciclo);
        cedulas.push_back(cedula);
        promedios.push_back(promedio);
    }

    mostrarResultados(nombresCompletos, ciclos, cedulas, promedios);

    return 0;
}

// Función para capturar los datos personales
void capturarDatos(std::string& nombre, std::string& apellido1, std::string& apellido2, int& ciclo, int& cedula) {
    std::cout << "Ingrese el primer nombre: ";
    std::getline(std::cin >> std::ws, nombre);

    std::cout << "Ingrese el primer apellido: ";
    std::getline(std::cin >> std::ws, apellido1);

    std::cout << "Ingrese el segundo apellido: ";
    std::getline(std::cin >> std::ws, apellido2);

    do {
        std::cout << "Ingrese el ciclo de estudio: ";
        std::cin >> ciclo;
        if (std::cin.fail() || ciclo <= 0) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Error: ciclo debe ser un número positivo.\n";
        }
    } while (ciclo <= 0);

    do {
        std::cout << "Ingrese el número de cédula: ";
        std::cin >> cedula;
        if (std::cin.fail() || cedula <= 0) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Error: cédula debe ser un número positivo.\n";
        }
    } while (cedula <= 0);
}

// Función para capturar notas de exámenes
void capturarNotas(std::vector<float>& notas) {
    float nota;
    for (int i = 0; i < 5; ++i) {
        do {
            std::cout << "Ingrese la nota del examen #" << (i + 1) << ": ";
            std::cin >> nota;
            if (std::cin.fail() || nota < 0.0 || nota > 100.0) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Error: nota debe estar entre 0 y 100.\n";
            }
        } while (nota < 0.0 || nota > 100.0);
        notas.push_back(nota);
    }
}

// Función para calcular el promedio
float calcularPromedio(const std::vector<float>& notas) {
    float suma = 0.0;
    for (float n : notas) suma += n;
    return suma / notas.size();
}

// Función para mostrar resultados finales
void mostrarResultados(const std::vector<std::string>& nombres, const std::vector<int>& ciclos, const std::vector<int>& cedulas, const std::vector<float>& promedios) {
    std::cout << "\n********** RESULTADOS FINALES **********\n";
    std::cout << std::left << std::setw(30) << "Nombre completo"
              << std::setw(10) << "Ciclo"
              << std::setw(15) << "Cédula"
              << std::setw(10) << "Promedio"
              << std::setw(12) << "Estado" << "\n";
    std::cout << std::string(77, '-') << "\n";

    for (size_t i = 0; i < nombres.size(); ++i) {
        std::string estado = promedios[i] >= 70.0 ? "Aprobado" : "Reprobado";
        std::cout << std::left << std::setw(30) << nombres[i]
                  << std::setw(10) << ciclos[i]
                  << std::setw(15) << cedulas[i]
                  << std::setw(10) << std::fixed << std::setprecision(2) << promedios[i]
                  << std::setw(12) << estado << "\n";
    }
}