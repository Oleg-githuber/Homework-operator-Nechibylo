#include <iostream>
#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator) : numerator_{numerator}, denominator_{denominator}
{
	
}

// Перегрузка оператора преобразования типов
Fraction::operator double() const
{
	return static_cast<double>(numerator_) / static_cast<double>(denominator_);
}

// Перегрузка операторов сравнения

bool Fraction::operator==(const Fraction& other)
{
	if (numerator_ == other.numerator_ && denominator_ == other.denominator_)
	{
		return true;
	}

	double dThis = operator double();
	double dOther = other.operator double();

	if (dThis == dOther)
	{
		return true;
	}

	return false;
}

bool Fraction::operator!=(const Fraction& other)
{
	return !(operator==(other));
}

bool Fraction::operator>(const Fraction& other)
{
	double dThis = operator double();
	double dOther = other.operator double();
	if (dThis > dOther)
	{
		return true;
	}
	return false;
}

bool Fraction::operator<(const Fraction& other)
{
	return !(operator>(other) || (operator==(other)));
}

bool Fraction::operator>=(const Fraction& other)
{
	return (operator>(other) || (operator==(other)));
}

bool Fraction::operator<=(const Fraction& other)
{
	return (operator<(other) || (operator==(other)));
}

// Перегрузка арифметических операторов

Fraction Fraction::operator+(const Fraction& other)
{
	if (this->denominator_ == other.denominator_)
	{
		return { this->numerator_ + other.numerator_, this->denominator_};
	}
	return { this->numerator_ * other.denominator_ + other.numerator_ * this->denominator_, other.denominator_ * this->denominator_ };
}

Fraction Fraction::operator-(const Fraction& other)
{
	if (this->denominator_ == other.denominator_)
	{
		return { this->numerator_ - other.numerator_, this->denominator_ };
	}
	return { this->numerator_ * other.denominator_ - other.numerator_ * this->denominator_, other.denominator_ * this->denominator_ };
}

Fraction Fraction::operator*(const Fraction& other)
{
	if (this->denominator_ == other.numerator_)
	{
		return { this->numerator_, other.denominator_ };
	}
	return { this->numerator_ * other.numerator_, this->denominator_ * other.denominator_ };
}

Fraction Fraction::operator/(const Fraction& other)
{
	if (!other.numerator_)
	{
		throw std::exception("Попытка деления на ноль!");
	}
	if (this->denominator_ == other.denominator_)
	{
		return { this->numerator_, other.numerator_ };
	}
	return { this->numerator_ * other.denominator_, this->denominator_ * other.numerator_ };
}

Fraction Fraction::operator-()
{
	return { -numerator_, denominator_ };
}

Fraction Fraction::operator++()
{
	numerator_ += denominator_;
	return *this;
}

Fraction Fraction::operator++(int)
{
	Fraction tempFraction{ *this };
	++(*this);
	return tempFraction;
}

Fraction Fraction::operator--()
{
	numerator_ -= denominator_;
	return *this;
}

Fraction Fraction::operator--(int)
{
	Fraction tempFraction{ *this };
	--(*this);
	return tempFraction;
}

std::ostream& operator<<(std::ostream& os, const Fraction fraction)
{
	return (os << fraction.numerator_ << '/' << fraction.denominator_);
}