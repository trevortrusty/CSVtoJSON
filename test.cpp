#include <iostream>
#include <string>

int main()
{
    std::string str = "hello\n";
    bool test = str[5] == '\n';
    std::cout << test;
    //std::cout << str.find("\n");
    return 0;
}