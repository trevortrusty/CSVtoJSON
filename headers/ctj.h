#include <fstream>
#include <string>
#include <vector>

class CTJ
{
    private:
        std::fstream csv_file;
        std::ofstream json_file;
        std::vector<std::string> rows; // rows of csv data
        std::vector<std::string> keyNames; // column/key names from csv file
        bool checkFileExtension(std::string &);
        void saveFileContents();
    public:
        //===================================+=//
        //  Input: Takes string of file path
        //  Returns: If error, returns 0. Returns
        //      1 on success
        //===================================+=//
        int setSourceFile(std::string &); // sets the fstream object for the user's desired csv file

        //===================================+=//
        //  Returns: If error, returns 0. Returns
        //      1 on success
        //===================================+=//
        int exportJSON();               // converts the source csv file to json and saves new file as "json_export.json"
        ~CTJ();
};