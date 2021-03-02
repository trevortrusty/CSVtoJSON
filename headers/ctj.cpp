#include "ctj.h"
#include <string>
#include <iostream>
#include <fstream>

int CTJ::setSourceFile(std::string filePath)
{
    internal_file.open(filePath);
    return 1;
}

int CTJ::exportJSON()
{
    return 1;
}

CTJ::~CTJ()
{
    internal_file.close();
    std::cout << "file closed" << std::endl;
}