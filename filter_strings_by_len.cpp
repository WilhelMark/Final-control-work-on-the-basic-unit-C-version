#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
// Функция для получения ввода от пользователя
std::string getInput()
{
    std::cout << "Введите элементы массива через запятую и пробел:\n";
    std::string line;
    std::getline(std::cin, line);
    return line;
}
// Функция для разделения строки на массив строк
void splitString(const std::string &inputStr, std::vector<std::string> &result)
{
    std::istringstream iss(inputStr);
    std::string token;
    while (std::getline(iss, token, ','))
    {
        // Удаляем пробелы в начале и конце строки
        token.erase(0, token.find_first_not_of(' '));
        token.erase(token.find_last_not_of(' ') + 1);
        result.push_back(token);
    }
}

// Функция для фильтрации строк по длине и формирования нового массива
void filterStringsByLength(const std::vector<std::string> &input, std::vector<std::string> &result)
{
    for (const auto &str : input)
    {
        if (str.length() <= 3)
        {
            result.push_back(str);
        }
    }
}

// Функция для вывода результата на экран
void printResult(const std::vector<std::string> &result)
{
    std::cout << "\nРезультат:\n";
    bool firstElementPrinted = false;
    for (const auto &s : result)
    {
        if (!firstElementPrinted)
        {
            firstElementPrinted = true;
        }
        else
        {
            std::cout << ',';
        }
        std::cout << s;
    }
    std::cout << '\n';
}

int main()
{
    std::string inputStr = getInput();
    std::vector<std::string> result;
    splitString(inputStr, result);
    std::vector<std::string> filteredResult;
    filterStringsByLength(result, filteredResult);
    printResult(filteredResult);
    return 0;
}