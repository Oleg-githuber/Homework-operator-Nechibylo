#include "functions.h"

// ���� �����
int enterNumber()
{
	int number{};
	while (true)
	{
		if (std::cin >> number)		// ���� ������������ ��� ������������ ������
		{
			break;
		}
		std::cout << std::flush << "�� ����� ������������ ��������!" << std::endl;
		clearStream();	// ������� ������
	}
	return number;
}

/// <summary>
/// ���� ��������� � ����������� ��� �������� ����� �����
/// </summary>
/// <param name="number">
/// ���������� ����� �����
/// </param>
/// <param name="numerator">
/// ���������
/// </param>
/// <param name="denominator">
/// �����������
/// </param>
void enterFracture(int number, int& numerator, int& denominator)
{
	std::cout << "������� ��������� ����� " << number << ": ";
	numerator = enterNumber();

	std::cout << "������� ����������� ����� " << number << ": ";
	while (true)
	{
		denominator = enterNumber();
		if (denominator)
		{
			break;
		}
		std::cout << "����������� �� ����� ���� ����� 0!" << std::endl;
		clearStream();
	}
}

/// <summary>
/// ������� ������ ��� ������� ����� �������� � ������� � �����
/// </summary>
void clearStream()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "������� ����� ��� ���: ";
}