#include "ctj.h"
#include "badExtension.h"
#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include <vector>

// bool endsWithReturn(std::string arg)
// {
//     for(char : arg)
//     {

//     }
// }


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

std::vector<std::string> parseLine(std::string source)
{
    std::vector<std::string> line;
    std::string cell = "";

    for(int i = 0; i < source.size(); i++)
    {
        //std::cout << "\nsource.size: " << source.size() << std::endl;
        //std::cout << "i: " << i << std::endl;
        if(source[i] == ',')
        {
            line.push_back(cell);
            std::cout << cell << std::endl;
            cell = ""; // Reset string so next cell can be parsed from the line
            if(source[i + 1] == ' ')
                i++; // Increment counter a second time to makeup for the space following the comma, don't want arbitrary leading whitespace in the data.
        }
        else if (i == source.size() - 1)
        {
            cell += source[i];
            line.push_back(cell);
        }
        else
        {
            cell += source[i];
        }
    }
    return line;
}


void CTJ::saveFileContents()
{
    while(csv_file.good()) {
        std::vector<std::string> line;
        //std::string cell;

        /*
        
        do{
            std::getline(csv_file, cell, ',');
            line.push_back(cell);
            std::cout << cell;
            //std::cin.get();
        } while(cell.at(cell.size() - 1) != '\n' && !csv_file.eof());

        */

        // for(int i = 0; i < columns; i++)
        // {
        //     std::getline(csv_file, cell, ',');
        //     line.push_back(cell);
        //     std::cout << cell << ' ';
        // }

        std::string currentLine;
        std::getline(csv_file, currentLine);
        //std::cout << currentLine << "!!\n";

        //std::string line;
        //getline(csv_file, line, ',');
        //std::cout << "line: " << line << std::endl; // for debugging
        rows.push_back(parseLine(currentLine));
        // for(std::string c : line)
        // {
        //     std::cout << c << ',';
        // }
        //std::cout << std::endl;
        //std::cout << "**" << std::endl;
    }
    for(std::string key: rows[0])
    {
        keyNames.push_back(key);
        //std::cout << key << std::endl;
    }
    //columnNumber = rows[0].size();
    std::cout << columns << std::endl;
    //rows.erase(rows.begin()); // Remove first row from vector because it just contains the column names
}

int CTJ::exportJSON()
{
    json_file.open("dest.json", std::ios::in | std::ios::out | std::ios::app);

    // int columnCount = 1;
    // for(int i = 0; i < rows[0].size(), i++)
    // {
    //     if(row[0].at(i) == ',')
    //     {
    //         columnCount++;
    //     }
    // }

    json_file << "[\n";
    
    for(int i = 0; i < rows.size(); i++)
    {
        json_file << "\t{\n";
        for(int j = 0; j < keyNames.size(); j++)
        {
            json_file << "\t\t\"" << keyNames[j] << "\": " << '\"' << (rows[i])[j];
            //json_file << "\t\t\"" << keyNames[j] << "\": " << '\"' << (rows[i])[j] << "\",\n";
            // Do not end with a comma if current entry is last entry
            if(j == keyNames.size() - 1)
            {
                json_file << "\"\n";
            }
            else
            {
                json_file << "\",\n";
            }
        }
        if(i == rows.size() - 1)
        {
            json_file << "\t}\n";;
        }
        else
        {
            json_file << "\t},\n";
        }
        //json_file << "\t},\n";
    }

    json_file << "]";
    return 1;
}

int CTJ::setColumnNumber(int &arg)
{
    columns = arg;
    return 1;
}

CTJ::~CTJ()
{
    csv_file.close();
    std::cout << "source file closed" << std::endl;
    json_file.close();
    std::cout << "destination file closed" << std::endl;
}