#include <iostream>
#include "ComplexNumber.h"


int main(int argc, char** argv) {

    if(argc < 2){
        throw std::invalid_argument("Additional argument required");
    } else if(argc > 2){
        throw std::invalid_argument("Too many arguments");
    }

    std::string level = argv[1];

    if (level != "easy" && level != "hard"){
        throw std::invalid_argument("Unknown argument");
    }

    ComplexNumber Com (10,0);
    std::cout << argv[1] << "; \n" << argc << std::endl;

}