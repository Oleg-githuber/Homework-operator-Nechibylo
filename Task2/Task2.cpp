// Task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <clocale>
#include "functions.h"
#include "Fraction.h"

int main()
{
    setlocale(LC_ALL, "Russian");   // Русская локализация

    // создание переменных числителя и знаменателя
    int numerator{};
    int denominator{};

    // Создание первой дроби
    enterFracture(1, numerator, denominator);
    Fraction fraction1(numerator, denominator);

    // Создание второй дроби
    enterFracture(2, numerator, denominator);
    Fraction fraction2(numerator, denominator);

    // Математические операции над дробями
    std::cout << fraction1 << " + " << fraction2 << " = " << fraction1 + fraction2 << std::endl;    // Сложение
    std::cout << fraction1 << " - " << fraction2 << " = " << fraction1 - fraction2 << std::endl;    // Вычитание
    std::cout << fraction1 << " * " << fraction2 << " = " << fraction1 * fraction2 << std::endl;    // Умножение
    try
    {
        std::cout << fraction1 << " / " << fraction2 << " = " << fraction1 / fraction2 << std::endl;    // Деление
    }
    catch (const std::exception& error)
    {
        std::cout << error.what() << std::endl;
    }
    std::cout << "++" << fraction1 << " * " << fraction2 << " = " << ++fraction1 * fraction2 << std::endl;  // Умножение с преинкрементом
    std::cout << "Значение дроби : " << fraction1 << std::endl;
    std::cout << fraction1 << "--" << " * " << fraction2 << " = " << fraction1-- * fraction2 << std::endl;  // Умножение с постдекрементом
    std::cout << "Значение дроби : " << fraction1 << std::endl;

    return EXIT_SUCCESS;
}
