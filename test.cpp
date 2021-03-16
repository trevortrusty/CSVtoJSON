#include <iostream>
#include <string>

int main()
{
    char a = 'a';
    std::string s = std::string(1, a);
    std::cout << s << std::endl;
    return 0;
}