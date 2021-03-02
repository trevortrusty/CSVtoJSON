#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
    std::ifstream srcCSV;
    srcCSV.open("source.csv");

    while(srcCSV.good()) {
        std::string line;
        getline(myFile, line, ',');
        std::cout << line << std::endl;
    }

    return 0;
}