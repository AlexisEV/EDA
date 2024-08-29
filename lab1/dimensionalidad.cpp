#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <fstream>
#include <string>

double calcularDistancia(std::vector<double> punto_a, std::vector<double> punto_b) {
    double dist_c = 0;
    for (int i = 0; i < punto_a.size(); i++) {
        dist_c += pow(punto_a[i] - punto_b[i],2);
    }
    return sqrt(dist_c);
}

std::vector<double> calcularDistancias(std::vector<std::vector<double>> puntos) {
    std::vector<double> distancias;
    for (int i = 0; i < puntos.size(); i++) {
        for (int j = i+1; j < puntos.size(); j++) {
            distancias.push_back(calcularDistancia(puntos[i], puntos[j]));
        }
    }
    return distancias;
}

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    std::vector<int> dims = { 10,50,100,500,1000,2000,5000 };
    std::vector<std::vector<std::vector<double>>> vec_dim(dims.size());
    std::vector<std::vector<double>> vec_dist;

    //Inicializar vectores de puntos
    for (int i = 0; i < dims.size(); i++) {
        vec_dim[i].resize(100);

        for (int j = 0; j < 100; j++) {
            vec_dim[i][j].resize(dims[i]);

            for (int k = 0; k < dims[i]; k++) {
                vec_dim[i][j][k] = dis(gen);
            }
        }
    }

    //Calcular distancias
    for (int i = 0; i < vec_dim.size(); i++) {
        vec_dist.push_back(calcularDistancias(vec_dim[i]));
        std::cout << vec_dist[i].size() << "\n";
    }

    //Guardar las distancias en archivos csv
    for (int i = 0; i < vec_dist.size(); i++) {
        std::ofstream nuevoArchivo ("dim_" + std::to_string(dims[i]) + ".csv");

        if (nuevoArchivo.is_open()) {
            for (int j = 0; j < vec_dist[i].size(); j++) {
                nuevoArchivo << vec_dist[i][j] << "\n";
            }
            nuevoArchivo.close();
        }
        else {
            std::cerr << "ERROR";
        }
    }

    std::cout << "Datos guardados correctamente";
}

