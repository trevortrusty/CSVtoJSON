#include <iostream>
#include <fstream>
#include "headers/ctj.h"

int main(int argc, char** argv)
{
    // std::ifstream srcCSV;
    // srcCSV.open("source.csv");

    // while(srcCSV.good()) {
    //     std::string line;
    //     getline(myFile, line, ',');
    //     std::cout << line << std::endl;
    // }
    std::string srcPath(argv[1]);
    CTJ client;
    if(client.setSourceFile(srcPath))
    {
        std::cout << "Test 1 Successful" << std::endl;
    }

    return 0;
}