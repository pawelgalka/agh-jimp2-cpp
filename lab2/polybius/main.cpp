//
// Created by pawel on 09.03.18.
//
#include <iostream>
#include <cstring>
#include <fstream>
#include "Polybius.h"

int main(int argv, char** argc){
    if (argv!=4){
        perror("Not enough arguments. Valid arguments : input_file output_file mode (0-decrypt 1-encrypt)");
        exit(-1);
    }
    std::cout << argc[1] << std::endl;
    std::ifstream input(argc[1]);
    if (!input) {return -1;}
    std::string message, data;
    while (!input.eof()){
        input >> data;
        message += data;
    }
    input.close();
    if (!std::strcmp(argc[3],"0")){
        std::ofstream output(argc[2], std::ios_base::in | std::ios_base::app );
        output << PolybiusDecrypt(message) << std::endl;
        output.close();
    }
    else if (!std::strcmp(argc[3],"1")){
        std::ofstream output(argc[2], std::ios_base::in | std::ios_base::app );
        output << PolybiusCrypt(message) << std::endl;
        output.close();
    }
    else {
        std::cerr << "Invalid mode" << std::endl;
    }
    return 0;
}
