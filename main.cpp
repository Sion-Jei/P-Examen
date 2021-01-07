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
#include <time.h>


//std::map<double, double> smi;
//std::map <double, std::string> archivo;
std::vector<int> vectore;
std::map<int, int> user;
std::list<double> list;
//std::map<double, double> cash;
//std::list<double> buff;

//auto c_users(std::map<double, std::string> y) {
auto c_users(std::vector<int> vec) {
    int foo[]{1,1,1,1,4,6,4,7,4};
    std::map<int, int> bar;

    for (auto const &f : foo)
        bar[f]++;

    for (auto const &b : bar)
        std::cout << "The number " << b.first 
                  << "is repeated " << b.second 
                  << "times\n";

    std::cout << "\n";
    // while (ys != y.end()) {
    //     if(!) 
    // }
    return 0;
    
}
//DANGEROUS ZONE DANGEROUS ZONE
std::map<int, unsigned int> counter(const std::vector<int>& vals) {
    std::map<int, unsigned int> rv;

    for (auto val = vals.begin(); val != vals.end(); ++val) {
        rv[*val]++;
    }

    return rv;
}

void display(const std::map<int, unsigned int>& counts) {
    for (auto count = counts.begin(); count != counts.end(); ++count) {
        std::cout << "Value " << count->first << " has count "
                  << count->second << std::endl;
    }
}

// auto convertYear(std::map<double, double> y, std::map<std::string, double> d) {
//     std::map<double, double> cash;
//     auto years = y.begin();        
//     while (years != y.end()) {
//         buff = {};
//         auto dollars = d.begin();
//         while (dollars != d.end()) {            
//             if (years->first == std::stod(dollars->first.substr(0, 4))) {                
//                 buff.push_back(dollars->second);
//             }
//             ++dollars;
//         }
//         double sum = std::accumulate(std::begin(buff), std::end(buff), 0.0);
//         double result = sum / buff.size();
//         cash.insert(std::pair<double, double>(years->first, years->second/result));
//         ++years;
//     }
//     return cash;
// }
// auto linearRegression(std::map<double, double> m, int year) {
//     double n = m.size();
//     double sx = 0;
//     double sxx = 0;
//     double sy = 0;
//     double syy = 0;
//     double sxy = 0;
//     auto iter = m.begin();
//     while (iter != m.end()) {
//         sx += iter->first;
//         sxx += pow(iter->first, 2);
//         sy += iter->second;
//         syy += pow(iter->second, 2);
//         sxy += iter->first * iter->second;
//         ++iter;
//     }
//     double b = (n * sxy - sx * sy) / (n * sxx - sx * sx);
//     double a = (1 / n) * sy - b * (1 / n) * sx;
//     // double c = b * year + a;
//     std::cout << "y = " << b << "x " << a;
// }

// auto csv_smi(std::string path) {
//     std::map<double, double> map_tmp;
//     std::string file_path = path;
//     std::ifstream csv;
//     csv.open(file_path);
//     std::string line;
//     getline(csv, line);
//     while (csv.peek() != EOF) {        
//         getline(csv, line);
//         line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
//         size_t position = line.find(";") + 1;
//         std::string key_k = line.substr(0, line.find(";"));
//         std::string key_v = line.substr(position);
//         key_k.erase(std::remove(key_k.begin(), key_k.end(), '\"'), key_k.end());
//         key_v.erase(std::remove(key_v.begin(), key_v.end(), '\"'), key_v.end());
//         double key_kd = std::stod(key_k);
//         double key_vd = std::stod(key_v);
//         map_tmp.insert(std::pair<double, double>(key_kd, key_vd));
//     }
//     csv.close();
//     return map_tmp;
// }

auto lectura(std::string path) {
    //std::map<double, std::string> map_tmp;
    std::vector<int> vec;
    std::string file_path = path;
    std::ifstream csv;
    csv.open(file_path);
    std::string line;
    //getline(csv, line);
    double sm = 0;
    while (csv.peek() != EOF) {
        getline(csv, line);
        line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
        //size_t position = line.find(";") + 1;
        std::string ext = line.substr(line.find(":")+1, 2);
        //std::cout << "\n EXTRACTO= " << ext;
        //std::cout << "\n CONTADOR " << sm;
        int exti = std::stoi(ext);
        //std::vector<int> vec;
        vec.push_back(exti);
        // for (auto it = vec.begin(); it != vec.end(); ++it) 
        //     std::cout << ' ' << *it;

        //std::cout << "\n CONTADOR ENTERO " << sm;
        //int foo[]{1,1,1,1,4,6,4,7,4};
        //map_tmp.insert(std::pair<double, std::string>(sm, ext));
        // std::string key_v = line.substr(position);
        // key_k.erase(std::remove(key_k.begin(), key_k.end(), '\"'), key_k.end());
        // key_v.erase(std::remove(key_v.begin(), key_v.end(), '\"'), key_v.end());
        // double key_vd = std::stod(key_v);
        // map_tmp.insert(std::pair<std::string, double>(key_k, key_vd));
        sm +=1;
    }
    csv.close();
    //return map_tmp;
    return vec;     
}
int main() {

    //smi = csv_smi("smi.csv");
    vectore = lectura("prueba.txt");
    //user = c_users(vectore);
    //c_users(vectore);
    //linearRegression(cash, 2001);
    //std::vector<int> mem = {1, 1, 1, 1, 4, 6, 4, 7, 4};
    display(counter(vectore));
    return 0;
}