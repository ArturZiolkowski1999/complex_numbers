#include <iostream>
#include "ComplexNumber.h"

std::string argErrorHandling(int argc, char **argv);

int main(int argc, char** argv) {

    std::string level = argErrorHandling(argc, argv);

    ComplexNumber Com;
    std::cout << "podaj complex \n";
    std::cin >> Com;
    std::cout << argv[1] << "; \n" << Com << std::endl;

}

std::string argErrorHandling(int argc, char **argv){
    if(argc < 2){
        throw std::invalid_argument("Additional argument required");
    } else if(argc > 2){
        throw std::invalid_argument("Too many arguments");
    }

    std::string level = argv[1];

    if (level != "easy" && level != "hard"){
        throw std::invalid_argument("Unknown argument");
    }

    return level;
}