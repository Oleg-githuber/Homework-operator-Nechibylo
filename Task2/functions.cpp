#include "functions.h"

// Ввод числа
int enterNumber()
{
	int number{};
	while (true)
	{
		if (std::cin >> number)		// Если пользователь ввёл некорректные данные
		{
			break;
		}
		std::cout << std::flush << "Вы ввели недопустимое значение!" << std::endl;
		clearStream();	// Очистка потока
	}
	return number;
}

/// <summary>
/// Ввод числителя и знаменателя для создания новой дроби
/// </summary>
/// <param name="number">
/// Порядковый номер дроби
/// </param>
/// <param name="numerator">
/// Числитель
/// </param>
/// <param name="denominator">
/// Знаменатель
/// </param>
void enterFracture(int number, int& numerator, int& denominator)
{
	std::cout << "Введите числитель дроби " << number << ": ";
	numerator = enterNumber();

	std::cout << "Введите знаметатель дроби " << number << ": ";
	while (true)
	{
		denominator = enterNumber();
		if (denominator)
		{
			break;
		}
		std::cout << "Знаменатель не может быть равен 0!" << std::endl;
		clearStream();
	}
}

/// <summary>
/// Очистка потока для попыток ввода значения в консоль в цикле
/// </summary>
void clearStream()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Введите число ещё раз: ";
}