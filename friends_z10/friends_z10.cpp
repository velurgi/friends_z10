﻿
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
    unsigned int items = 1;
    std::cin >> items;
    items = intCheck(items);

    std::vector <int> weight;

    //Ввод масс вещей
    for (int i = 1; i < items + 1; i++) {
        std::cout << "Масса вещи " << i << ": ";
        int j = 1;
        std::cin >> j;
        j = intCheck(j);
        weight.push_back(j);
    }

    sort(weight.begin(), weight.end());// Сортировка масс от наименьшей к наибольшей


    std::vector <int> packages;
    int sumWeight = 0;
    // ОТЛАДКА, ВЫВОД СУММАРНОГО ВЕСА
    for (int i = 0; i < items; i++) {
        sumWeight += weight[i];
    }
    std::cout << "Суммарный вес до распределения: " << sumWeight << std::endl;
    if (friends < items) {
        // Заполняю каждый рюкзак наибольшей по весу вещью
        for (int i = 0; i < friends; i++) {
            packages.push_back(weight[items - i - 1]);
        }
        for (int i = friends - 1; i < items - 1; i++) {
            sort(packages.begin(), packages.end());
            packages[0] += weight[items - i - 2]; // <== Здесь было -1, сделал -2, терь работает
        }
        std::cout << std::endl << std::endl << "Итоговое распределение: " << std::endl;
        for (int i = 0; i < friends; i++) {
            std::cout << "Вес рюкзака " << i + 1 << ": " << packages[i] << std::endl;
        }
        // ОТЛАДКА, ВЫВОД СУММАРНОГО ВЕСА
        sumWeight = 0;
        for (int i = 0; i < friends; i++) {
            sumWeight += packages[i];
        }
        std::cout << "Суммарный вес после: " << sumWeight << std::endl;
    }
    else {
        for (int i = 0; i < items; i++) {
            packages.push_back(weight[i]);
        }
        std::cout << std::endl << std::endl << "Итоговое распределение: " << std::endl;
        for (int i = 0; i < items; i++) {
            std::cout << "Вес рюкзака " << i + 1 << ": " << packages[i] << std::endl;
        }
        std::cout << "У остальных рюкзаки пустые.";
    }
    std::cin >> packages[0];

    return 0;
}