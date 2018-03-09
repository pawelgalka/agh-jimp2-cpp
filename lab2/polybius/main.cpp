//
// Created by pawel on 09.03.18.
//
#include <iostream>
#include <fstream>
#include "Polybius.h"

int main(char** argc, int argv){
    if (argv!=4){
        perror("Not enough arguments. Valid arguments : input_file output_file mode (0-decrypt 1-encrypt)");
        exit(-1);
    }
    std::ifstream input(argc[1]);
    std::string message;
    std::cout << PolybiusDecrypt("52241114343234431355154335111324113224");
    return 0;
}
