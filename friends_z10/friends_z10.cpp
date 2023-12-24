// Поход 
#include <vector>
#include <iostream>
#include <algorithm>

int intCheck(int integer) {
    while (std::cin.fail() || integer < 0) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Ошибка, вы должны ввести целое неотрицательное число." << std::endl << "Введите ещё раз: " << std::endl;
        std::cin >> integer;
    }
    return integer;
}

int main()
{
    setlocale(LC_ALL, "ru");
    std::cout << "Введите количество участников похода: " << std::endl;
    unsigned int friends = 1;
    std::cin >> friends;
    friends = intCheck(friends);
    std::cout << "Введите количество вещей: " << std::endl;
    unsigned int things = 1;
    std::cin >> things;
    things = intCheck(things);
    std::vector <int> weight;
    //Ввод масс вещей
    for (int i = 1; i < things+1; i++) { 
        std::cout << "Масса вещи " << i << ": ";
        int j = 1;
        std::cin >> j;
        j = intCheck(j);
        weight.push_back(j);
    }
    sort(weight.begin(zz), weight.end());  // Сортировка масс от наименьшей к наибольшей
    



    return 0;
}

