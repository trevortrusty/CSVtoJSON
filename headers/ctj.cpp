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
        internal_file.open(filePath);
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
    while(internal_file.good()) {
        std::string line;
        getline(internal_file, line, ',');
        std::cout << line << std::endl; // for debugging
        rows.push_back(line);
    }
}

int CTJ::exportJSON()
{
    return 1;
}

CTJ::~CTJ()
{
    internal_file.close();
    std::cout << "source file closed" << std::endl;
}