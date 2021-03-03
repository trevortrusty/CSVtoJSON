#include "ctj.h"
#include "badExtension.h"
#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include <vector>

bool CTJ::checkFileExtension(std::string &filePath)
{
    int len = filePath.size() - 1; // store size of filepath
    // Check if there are enough characters for a name and file extension
    if(len < 4)
    {
        return false;
    }
    // Return true if file path ends with .csv, false if not.
    return ( filePath[len-3] == '.' && filePath[len-2] == 'c' && filePath[len-1] == 's' && filePath[len] == 'v' );
}


int CTJ::setSourceFile(std::string &filePath)
{
    if(!checkFileExtension(filePath))
    {
        throw badExtension();
        return 0;
    }
    try
    {
        csv_file.open(filePath);
        saveFileContents();
        return 1;
    }
    catch(std::ifstream::failure e) {
        std::cerr << "Exception opening/reading file\n";
        return 0;
    }
}

void CTJ::saveFileContents()
{
    while(csv_file.good()) {
        std::string line;
        getline(csv_file, line, ',');
        std::cout << line << std::endl; // for debugging
        rows.push_back(line);
    }
}

int CTJ::exportJSON()
{
    json_file.open("dest.json", std::ios::in | std::ios::out | std::ios::app);
    json_file << "[\n";

    

    json_file << "]";
    return 1;
}

CTJ::~CTJ()
{
    csv_file.close();
    std::cout << "source file closed" << std::endl;
    json_file.close();
    std::cout << "destination file closed" << std::endl;
}