#include <fstream>
#include <string>


class CTJ
{
    private:
        std::fstream internal_file;
        bool checkFileExtension(std::string &);
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