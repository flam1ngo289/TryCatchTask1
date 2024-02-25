#include <iostream>
#include <string>

class bad_length {}; 

long function(std::string &str, int forbidden_length) {
    long length = str.length();
    if ((length / 2) == forbidden_length) {
        throw bad_length();
    }
    return length;
}

int main() {
    int forbidden_length;
    std::cout << "Введите запретную длину: ";
    std::cin >> forbidden_length;

    std::string input;
    
    while (true) {
        std::cout << "Введите слово: ";
        std::cin >> input;

        try {
            long len = function(input, forbidden_length);
            std::cout << "Длина слова \"" << input << "\" равна " << len / 2 << std::endl;
        } catch (bad_length) {
            std::cout << "Вы ввели слово запретной длины! До свидания" << std::endl;
            break;
        }
    }

    return 0;
}
