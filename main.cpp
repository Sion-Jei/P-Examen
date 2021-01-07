#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "omp.h"
#include <algorithm>
#include <list>
#include <string>
#include <map>
#include <numeric>
#include <math.h>

std::vector<int> vectore;
std::map<int, int> user;
std::list<double> list;

std::string chrs (std::string pors) {
    int porsi = std::stoi(pors);
    if (porsi < 10) {
        pors = "0" + pors;       
    }
    return pors;
}

std::map<int, unsigned int> counter(const std::vector<int>& vals) {
    std::map<int, unsigned int> rv;

    for (auto val = vals.begin(); val != vals.end(); ++val) {
        rv[*val]++;
    }

    return rv;
}

void display(const std::map<int, unsigned int>& counts) {
    std::ofstream csv;
    csv.open("resultado.csv"); //abre archivo desde ruta
    std::string line; //crea string para guardar linea de txt
    for (auto count = counts.begin(); count != counts.end(); ++count) {
        std::string key = std::to_string(count->first);
        std::string value = std::to_string(count->second);
        line = chrs(key) + ";" + value;
        csv << line << std::endl;
        //std::cout << "Value " << count->first << " has count "
        //          << count->second << std::endl;
    }
    csv.close();
}

auto lectura(std::string path) {
    std::vector<int> vec;
    std::string file_path = path; //se crea ruta
    std::ifstream csv; // crea variable para abrir txt
    csv.open(file_path); //abre archivo desde ruta
    std::string line; //crea string para guardar linea de txt
    while (csv.peek() != EOF) {
        getline(csv, line);
        line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
        std::string ext = line.substr(line.find(":")+1, 2);
        int exti = std::stoi(ext);
        vec.push_back(exti);
    }
    csv.close();
    return vec;     
}
int main() {
    vectore = lectura("prueba.txt");
    display(counter(vectore));
    return 0;
}