//
//  main.cpp
//  csv
//
//  Created by Daniil Buchko on 15.05.2022.
//

#include "readCsv.h"
#include <vector>


int main(int argc, const char * argv[]) {
    std::string path = "data/iris.csv";
    std::vector<Iris> data = read_iris(path);
    
    for (auto iris : data) {
        std::cout << iris << '\n';
    }
    
    return 0;
}
