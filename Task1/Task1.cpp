// В этом задании вы переопределите операторы сравнения для дробей.
// Ваша задача — дописать класс Fraction так, чтобы программа компилировалась и работала корректно.

#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	explicit operator double() const
	{
		return static_cast<double>(numerator_) / static_cast<double>(denominator_);
	}

	bool operator==(const Fraction& other)
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

	bool operator!=(const Fraction& other)
	{
		return !(operator==(other));
	}

	bool operator>(const Fraction& other)
	{
		double dThis = operator double();
		double dOther = other.operator double();
		if (dThis > dOther)
		{
			return true;
		}
		return false;
	}

	bool operator<(const Fraction& other)
	{
		return !(operator>(other) || (operator==(other)));
	}

	bool operator>=(const Fraction& other)
	{
		return (operator>(other) || (operator==(other)));
	}

	bool operator<=(const Fraction& other)
	{
		return (operator<(other) || (operator==(other)));
	}
};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}