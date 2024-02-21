#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
// Функция для получения ввода от пользователя
std::string getInput() {
    std::cout << "Введите элементы массива через запятую и пробел:\n";
    std::string line;
    std::getline(std::cin, line);
    return line;
}