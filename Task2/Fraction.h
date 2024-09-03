#ifndef MY_CLASS_FRACTION
#define MY_CLASS_FRACTION


class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator);

	// Перегрузка оператора преобразования типа
	explicit operator double() const;

	// Перегрузка операторов сравнения
	bool operator==(const Fraction& other);

	bool operator!=(const Fraction& other);

	bool operator>(const Fraction& other);

	bool operator<(const Fraction& other);

	bool operator>=(const Fraction& other);

	bool operator<=(const Fraction& other);

	// Перегрузка арифметических операторов
	Fraction operator+(const Fraction& other);

	Fraction operator-(const Fraction& other);

	Fraction operator*(const Fraction& other);

	Fraction operator/(const Fraction& other);

	// Перегрузка унарных операторов
	Fraction operator-();

	Fraction operator++();

	Fraction operator++(int);

	Fraction operator--();

	Fraction operator--(int);

	// Перегрузка оператора сдвига
	friend std::ostream& operator<<(std::ostream& os, const Fraction fraction);
};

#endif // !MY_CLASS_FRACTION