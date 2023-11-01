#include "fraction.h"

//Init with 0,1, because 0,0 is incorrect fraction
Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(const int number) : numerator(number), denominator(1) {}

Fraction::Fraction(const int numerator, const int denominator) : numerator(numerator), denominator(denominator) {}

Fraction::Fraction(const Fraction& f) : numerator(f.numerator), denominator(f.denominator) {}

Fraction::Fraction(double number)
{
	const double precision = 1e-15;
	const int sign = number < 0 ? -1 : 1;

	number = std::abs(number);
	double decimal_part = number - static_cast<int>(number);

	size_t counter{};
	size_t cycles{ 15 };

	while (decimal_part > precision && counter < cycles)
	{
		decimal_part = number - static_cast<int>(number);
		number *= 10;
		counter++;
	}

	this->numerator = static_cast<int>(sign * number);
	this->denominator = static_cast<int>(std::pow(10, counter));
	this->simplify();
}

Fraction::operator double() const
{
	return static_cast<double>(this->get_numerator()) / static_cast<double>(this->get_denominator());
}

Fraction& Fraction::simplify()
{
	if (this->get_numerator() == 0 || this->get_denominator() == 0)
		return *this; //In future it's recommended to make an exception handling here to report an error to user

	int common_denomitator = std::gcd(this->get_numerator(), this->get_denominator());
	this->numerator /= common_denomitator;
	this->denominator /= common_denomitator;

	if (this->get_numerator() < 0 && this->get_denominator() < 0)
	{
		this->numerator = -this->get_numerator();
		this->denominator = -this->get_denominator();
	}

	return *this;
}

Fraction Fraction::operator-()
{
	this->numerator *= -1;
	this->simplify();
	return *this;
}

Fraction& Fraction::operator+=(const Fraction& f)
{
	if (this->get_denominator() == 0 || f.get_denominator() == 0)
		return *this; //In future it's recommended to make an exception handling here to report an error to user

	int lcm{ std::lcm(this->get_denominator(), f.get_denominator()) }; // least common multiple

	//Convert to common denominator
	this->numerator = this->get_numerator() * (lcm / this->get_denominator());
	this->numerator += f.get_numerator() * (lcm / f.get_denominator());
	this->denominator = lcm;

	this->simplify();
	return *this;
}

Fraction& Fraction::operator-=(const Fraction& f)
{
	if (this->get_denominator() == 0 || f.get_denominator() == 0)
		return *this; //In future it's recommended to make an exception handling here to report an error to user

	int lcm{ std::lcm(this->get_denominator(), f.get_denominator()) }; //least common multiple

	//Convert to common denominator
	this->numerator = this->get_numerator() * (lcm / this->get_denominator());
	this->numerator -= f.get_numerator() * (lcm / f.get_denominator());
	this->denominator = lcm;

	this->simplify();
	return *this;
}

Fraction& Fraction::operator*=(const Fraction& f)
{
	this->numerator *= f.get_numerator();
	this->denominator *= f.get_denominator();

	this->simplify();
	return *this;
}

Fraction& Fraction::operator/=(const Fraction& f)
{
	this->numerator *= f.get_denominator();
	this->denominator *= f.get_numerator();

	this->simplify();
	return *this;
}

Fraction Fraction::operator+(const Fraction& f)
{
	Fraction sum = *this;
	sum += f;
	sum.simplify();
	return sum;
}

Fraction Fraction::operator-(const Fraction& f)
{
	Fraction diff = *this;
	diff -= f;
	diff.simplify();
	return diff;
}

Fraction Fraction::operator*(const Fraction& f)
{
	Fraction mul = *this;
	mul *= f;
	mul.simplify();
	return mul;
}

Fraction Fraction::operator/(const Fraction& f)
{
	Fraction div = *this;
	div /= f;
	div.simplify();
	return div;
}

std::strong_ordering Fraction::operator<=>(const Fraction& f) const
{
	//if (this->get_denominator() == 0 || f.get_denominator() == 0)
		//return *this; //In future it's recommended to make an exception handling here to report an error to user
	int lcm{ std::lcm(this->get_denominator(), f.get_denominator()) };

	int lnumerator = this->get_numerator() * (lcm / this->get_denominator());
	int rnumerator = f.get_numerator() * (lcm / f.get_denominator());

	return lnumerator <=> rnumerator;
}

std::strong_ordering Fraction::operator<=>(const int i) const
{
	Fraction f1 = *this;
	Fraction f2(i, 1);
	return f1 <=> f2;
}

bool Fraction::operator==(const Fraction& f) const
{
	Fraction f1 = *this;
	Fraction f2 = f;
	f1.simplify();
	f2.simplify();
	return f1.get_numerator() == f2.get_numerator() && f1.get_denominator() == f2.get_denominator();
}

bool Fraction::operator==(const int i) const
{
	Fraction f1 = *this;
	Fraction f2(i, 1);
	f1.simplify();
	f2.simplify();
	return f1.get_numerator() == f2.get_numerator() && f1.get_denominator() == f2.get_denominator();
}

bool Fraction::operator==(const double d) const
{
	Fraction f1 = *this;
	Fraction f2(d);
	return f1 == f2;
}

void Fraction::print() const
{
	if (this->get_numerator() == 0)
	{
		std::cout << this->get_numerator();
	}
	else if (this->get_denominator() == 1)
	{
		std::cout << this->get_numerator();
	}
	else if (this->get_denominator() == -1)
	{
		std::cout << -this->get_numerator();
	}
	else
	{
		std::cout << this->get_numerator() << '/' << this->get_denominator();
	}
}
