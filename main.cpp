#include <iostream>
#include <fstream>
#include "headers/ctj.h"
#include "headers/badExtension.h"

int main(int argc, char** argv)
{
    // std::ifstream srcCSV;
    // srcCSV.open("source.csv");

    // while(srcCSV.good()) {
    //     std::string line;
    //     getline(myFile, line, ',');
    //     std::cout << line << std::endl;
    // }
    int inputColumnNumber = atoi(argv[2]);
    try{
        std::string srcPath(argv[1]);
        CTJ client;
        client.setColumnNumber(inputColumnNumber);
        if(client.setSourceFile(srcPath))
        {
            std::cout << "Test 1 Successful" << std::endl;
            client.exportJSON();
        }
    }
    catch (badExtension ex)
    {
        std::cerr << ex.what() << std::endl;
    }


    return 0;
}