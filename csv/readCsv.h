//
//  read_csv.h
//  csv
//
//  Created by Daniil Buchko on 15.05.2022.
//

#ifndef read_csv_h
#define read_csv_h

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

struct Iris {
    Iris(std::stringstream& stream)
     {
        std::string line = "";
        std::getline(stream, line, ',');
        sepalLength = std::atof(line.c_str());
        std::getline(stream,  line, ',');
        sepalWidth = std::atof(line.c_str());
        std::getline(stream,  line, ',');
        petalLength = std::atof(line.c_str());
        std::getline(stream,  line, ',');
        petalWidth = std::atol(line.c_str());
        std::getline(stream, variety);
     };
    
    friend std::ostream& operator<<(std::ostream& ostream, const Iris& iris) {
        return ostream << "Length: " << iris.sepalLength << " Variety: " << iris.variety;
    }
    
    float sepalLength;
    float sepalWidth;
    float petalLength;
    float petalWidth;
    std::string variety;
    
};

std::vector<Iris> read_iris(std::string path) {
    std::string line = "";
    std::ifstream file(path);
    std::stringstream inputStream;
    
    assert(file.is_open());
    std::getline(file, line);  // header
    std::cout << inputStream.str();
    std::vector<Iris> data;
    
    while (!file.eof()) {
        std::getline(file, line);
        inputStream << line;
        
        Iris iris(inputStream);
        data.push_back(iris);
        
        inputStream.str(std::string());
        inputStream.clear();
    }
    return data;
    
}



#endif /* read_csv_h */
