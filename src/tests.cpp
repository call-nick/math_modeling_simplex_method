/*
This file contains tests for Fraction class

Tests are include:
1. Creating fraction object
	a. by default
	b. by passing 1 int args
	c. by passing 2 ints args
	d. by passing other fraction
	e. by passing one double arg
2. Conversion from Fraction to double
3. Simplifying fraction
4. Overloaded operators
	a. unary minus
	b. operator +=
	c. operator -=
	d. operator *=
	e. operator /=
	f. operator +
	g. operator -
	h. operator *
	i. operator /
	g. operator <=>
	k. operator == (Fraction)
	l. operator == (double)
	m. operator == (int)

*/

#pragma once

#ifndef _TESTS_
#define _TESTS_

#ifdef DEBUG

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "fraction.h"
#include "doctest.h"

//1. CREATING FRACTION OBJECT

//a. by default
TEST_CASE("Creating fraction by default")
{
	Fraction f1;

	CHECK(f1.get_numerator() == 0);
	CHECK(f1.get_denominator() == 1);

	Fraction f2{};

	CHECK(f2.get_numerator() == 0);
	CHECK(f2.get_denominator() == 1);
}

//b. by passing 1 int arg
TEST_CASE("Creating fraction by passing 1 int arg")
{
	Fraction f1 = 0;

	CHECK(f1.get_numerator() == 0);
	CHECK(f1.get_denominator() == 1);

	Fraction f2(0);

	CHECK(f2.get_numerator() == 0);
	CHECK(f2.get_denominator() == 1);

	Fraction f3{ 0 };

	CHECK(f3.get_numerator() == 0);
	CHECK(f3.get_denominator() == 1);

	Fraction f4 = 5;

	CHECK(f4.get_numerator() == 5);
	CHECK(f4.get_denominator() == 1);

	Fraction f5{ -15 };

	CHECK(f5.get_numerator() == -15);
	CHECK(f5.get_denominator() == 1);
}

//c. by passing 2 int args
TEST_CASE("Creating fraction by passing 2 int args")
{
	Fraction f1(0, 1);

	CHECK(f1.get_numerator() == 0);
	CHECK(f1.get_denominator() == 1);

	Fraction f2(1, 2);

	CHECK(f2.get_numerator() == 1);
	CHECK(f2.get_denominator() == 2);

	Fraction f3(-1, 2);

	CHECK(f3.get_numerator() == -1);
	CHECK(f3.get_denominator() == 2);

	Fraction f4(1, -2);

	CHECK(f4.get_numerator() == 1);
	CHECK(f4.get_denominator() == -2);

	Fraction f5(4, 2);

	CHECK(f5.get_numerator() == 4);
	CHECK(f5.get_denominator() == 2);
}

//d. by passing other fraction
TEST_CASE("Creating fraction by passing other fraction")
{
	Fraction f1(0, 1);
	Fraction f2(f1);

	CHECK(f2.get_numerator() == 0);
	CHECK(f2.get_denominator() == 1);

	Fraction f3(1, 2);
	Fraction f4{ f3 };

	CHECK(f4.get_numerator() == 1);
	CHECK(f4.get_denominator() == 2);

	Fraction f5(-1, 2);
	Fraction f6(f5);

	CHECK(f6.get_numerator() == -1);
	CHECK(f6.get_denominator() == 2);

	Fraction f7(1, -2);
	Fraction f8(f7);

	CHECK(f8.get_numerator() == 1);
	CHECK(f8.get_denominator() == -2);

	Fraction f9(4, 2);
	Fraction f10{ f9 };

	CHECK(f10.get_numerator() == 4);
	CHECK(f10.get_denominator() == 2);
}

//e. by passing one double arg

TEST_CASE("Creating fraction by passing one double arg")
{
	Fraction f1 = 5.5;

	CHECK(f1.get_numerator() == 11);
	CHECK(f1.get_denominator() == 2);

	Fraction f2(22.5);

	CHECK(f2.get_numerator() == 45);
	CHECK(f2.get_denominator() == 2);

	Fraction f3{ 12 };

	CHECK(f3.get_numerator() == 12);
	CHECK(f3.get_denominator() == 1);

	Fraction f4 = 6.4;

	CHECK(f4.get_numerator() == 32);
	CHECK(f4.get_denominator() == 5);

	Fraction f5(-7.6);

	CHECK(f5.get_numerator() == -38);
	CHECK(f5.get_denominator() == 5);

	Fraction f6(0.0);

	CHECK(f6.get_numerator() == 0);
	CHECK(f6.get_denominator() == 1);

	Fraction f7(-44.2);

	CHECK(f7.get_numerator() == -221);
	CHECK(f7.get_denominator() == 5);

	Fraction f8(-0.333);

	CHECK(f8.get_numerator() == -333);
	CHECK(f8.get_denominator() == 1000);
}


//2. CONVERSION FROM FRACTION TO DOUBLE

TEST_CASE("Conversion from fraction fo double")
{
	Fraction f1(11, 2);
	double d = f1;

	CHECK(d == 5.5);

	Fraction f2(45, 2);
	d = f2;

	CHECK(d == 22.5);

	Fraction f3{ 12 };
	d = f3;

	CHECK(d == 12);

	Fraction f4(32, 5);
	d = f4;

	CHECK(d == 6.4);

	Fraction f5(-38, 5);
	d = f5;

	CHECK(d == -7.6);

	Fraction f6(0.0);
	d = f6;


	Fraction f7(-221, 5);
	d = f7;

	CHECK(d == -44.2);

	Fraction f8(-333, 1000);
	d = f8;

	CHECK(d == -0.333);

}

//3. SIMPLIFYING FRACTION

TEST_CASE("Simplifying fraction")
{
	Fraction f1;
	f1.simplify();

	CHECK(f1.get_numerator() == 0);
	CHECK(f1.get_denominator() == 1);

	Fraction f2(1, 2);
	f2.simplify();

	CHECK(f2.get_numerator() == 1);
	CHECK(f2.get_denominator() == 2);

	Fraction f3(2, 4);
	f3.simplify();

	CHECK(f3.get_numerator() == 1);
	CHECK(f3.get_denominator() == 2);

	Fraction f4(-8, 4);
	f4.simplify();

	CHECK(f4.get_numerator() == -2);
	CHECK(f4.get_denominator() == 1);

	Fraction f5(17, 5);
	f5.simplify();

	CHECK(f5.get_numerator() == 17);
	CHECK(f5.get_denominator() == 5);
}

//4. OVERLOADED OPERATORS

TEST_CASE("Unary minus operator")
{
	Fraction f1(0, 1);
	f1 = -f1;

	CHECK(f1.get_numerator() == 0);
	CHECK(f1.get_denominator() == 1);

	Fraction f2(1, 2);
	f2 = -f2;

	CHECK(f2.get_numerator() == -1);
	CHECK(f2.get_denominator() == 2);

	Fraction f3(-1, 2);
	f3 = -f3;

	CHECK(f3.get_numerator() == 1);
	CHECK(f3.get_denominator() == 2);

	Fraction f4(1, -2);
	f4 = -f4;

	CHECK(f4.get_numerator() == 1);
	CHECK(f4.get_denominator() == 2);

	Fraction f5(4, 2);
	f5 = -f5;

	CHECK(f5.get_numerator() == -2);
	CHECK(f5.get_denominator() == 1);
}

TEST_CASE("fraction+= operator")
{

	Fraction f1(1, 1);
	Fraction f2(1, 1);
	f1 += f2;

	CHECK(f1.get_numerator() == 2);
	CHECK(f1.get_denominator() == 1);

	Fraction f3(1, -1);
	Fraction f4(1, 1);
	f3 += f4;

	CHECK(f3.get_numerator() == 0);
	CHECK(f3.get_denominator() == 1);

	Fraction f5(5, 3);
	Fraction f6(-4, 4);
	f5 += f6;

	CHECK(f5.get_numerator() == 2);
	CHECK(f5.get_denominator() == 3);
}

TEST_CASE("fraction-= operator")
{

	Fraction f1(1, 1);
	Fraction f2(1, 1);
	f1 -= f2;

	CHECK(f1.get_numerator() == 0);
	CHECK(f1.get_denominator() == 1);

	Fraction f3(1, -1);
	Fraction f4(1, 1);
	f3 -= f4;

	CHECK(f3.get_numerator() == -2);
	CHECK(f3.get_denominator() == 1);

	Fraction f5(5, 3);
	Fraction f6(-4, 4);
	f5 -= f6;

	CHECK(f5.get_numerator() == 8);
	CHECK(f5.get_denominator() == 3);
}

TEST_CASE("fraction*= operator")
{
	Fraction f1;
	Fraction f2(2, -3);

	f1 *= f2;

	CHECK(f1.get_numerator() == 0);
	CHECK(f1.get_denominator() == -3);

	Fraction f3(5, 6);
	Fraction f4(3, 9);

	f3 *= f4;

	CHECK(f3.get_numerator() == 5);
	CHECK(f3.get_denominator() == 18);

	Fraction f5(0, 1);
	Fraction f6(12, -3);

	f5 *= f6;

	CHECK(f5.get_numerator() == 0);
	CHECK(f5.get_denominator() == -3);
}

TEST_CASE("fraction/= operator")
{
	Fraction f1;
	Fraction f2(2, -3);

	f1 /= f2;

	CHECK(f1.get_numerator() == 0);
	CHECK(f1.get_denominator() == 2);

	Fraction f3(5, 6);
	Fraction f4(3, 9);

	f3 /= f4;

	CHECK(f3.get_numerator() == 5);
	CHECK(f3.get_denominator() == 2);

	Fraction f5(0, 1);
	Fraction f6(12, -3);

	f5 /= f6;

	CHECK(f5.get_numerator() == 0);
	CHECK(f5.get_denominator() == 12);
}

TEST_CASE("fraction+ operator")
{

	Fraction f1(1, 1);
	Fraction f2(1, 1);

	Fraction f3 = f1 + f2;

	CHECK(f3.get_numerator() == 2);
	CHECK(f3.get_denominator() == 1);

	Fraction f4(1, -1);
	Fraction f5(1, 1);

	Fraction f6 = f4 + f5;

	CHECK(f6.get_numerator() == 0);
	CHECK(f6.get_denominator() == 1);

	Fraction f7(5, 3);
	Fraction f8(-4, 4);

	Fraction f9 = f7 + f8;

	CHECK(f9.get_numerator() == 2);
	CHECK(f9.get_denominator() == 3);
}

TEST_CASE("fraction- operator")
{

	Fraction f1(1, 1);
	Fraction f2(1, 1);

	Fraction f3 = f1 - f2;

	CHECK(f3.get_numerator() == 0);
	CHECK(f3.get_denominator() == 1);

	Fraction f4(1, -1);
	Fraction f5(1, 1);

	Fraction f6 = f4 - f5;

	CHECK(f6.get_numerator() == -2);
	CHECK(f6.get_denominator() == 1);

	Fraction f7(5, 3);
	Fraction f8(-4, 4);

	Fraction f9 = f7 - f8;

	CHECK(f9.get_numerator() == 8);
	CHECK(f9.get_denominator() == 3);
}

TEST_CASE("fraction* operator")
{
	Fraction f1;
	Fraction f2(2, -3);

	Fraction f3 = f1 * f2;
	CHECK(f3.get_numerator() == 0);
	CHECK(f3.get_denominator() == -3);

	Fraction f4(5, 6);
	Fraction f5(3, 9);

	Fraction f6 = f4 * f5;

	CHECK(f6.get_numerator() == 5);
	CHECK(f6.get_denominator() == 18);

	Fraction f7(0, 1);
	Fraction f8(12, -3);

	Fraction f9 = f7 * f8;

	CHECK(f9.get_numerator() == 0);
	CHECK(f9.get_denominator() == -3);
}

TEST_CASE("fraction/ operator")
{
	Fraction f1;
	Fraction f2(2, -3);

	Fraction f3 = f1 / f2;

	CHECK(f3.get_numerator() == 0);
	CHECK(f3.get_denominator() == 2);

	Fraction f4(5, 6);
	Fraction f5(3, 9);

	Fraction f6 = f4 / f5;

	CHECK(f6.get_numerator() == 5);
	CHECK(f6.get_denominator() == 2);

	Fraction f7(0, 1);
	Fraction f8(12, -3);

	Fraction f9 = f7 / f8;

	CHECK(f9.get_numerator() == 0);
	CHECK(f9.get_denominator() == 12);
}

TEST_CASE("fraction<=> operator")
{
	Fraction f1;
	Fraction f2;

	std::strong_ordering o1{ f1 <=> f2 };

	CHECK(o1 == std::strong_ordering::equal);

	Fraction f3(1, 2);
	Fraction f4(2, 4);
	std::strong_ordering o2{ f3 <=> f4 };

	CHECK(o2 == std::strong_ordering::equal);

	Fraction f5(-1, 2);
	Fraction f6(2, 7);
	std::strong_ordering o3{ f5 <=> f6 };

	CHECK(o3 == std::strong_ordering::less);

	Fraction f7(2, 9);
	Fraction f8(1, 9);
	std::strong_ordering o4{ f7 <=> f8 };

	CHECK(o4 == std::strong_ordering::greater);

	Fraction f9(3, 1);
	std::strong_ordering o5{ f9 <=> static_cast<Fraction>(3) };

	CHECK(o5 == std::strong_ordering::equal);
}

TEST_CASE("fraction== operator (Fraction)")
{

	Fraction f1;
	Fraction f2;

	CHECK((f1 == f2) == true);

	Fraction f3(1, 2);
	Fraction f4(2, 4);

	CHECK((f3 == f4) == true);

	Fraction f5(-1, -3);
	Fraction f6(3, 9);

	CHECK((f5 == f6) == true);
}

TEST_CASE("fraction== operator (int)")
{
	Fraction f1;

	CHECK((f1 == 0) == true);

	Fraction f2(6, 3);

	CHECK((f2 == 2) == true);


	Fraction f3(-4, 2);

	CHECK((f3 == -2) == true);
}

TEST_CASE("fraction== operator (double)")
{
	Fraction f1;

	CHECK((f1 == 0.0) == true);

	Fraction f2(4, 5);

	CHECK((f2 == 0.8) == true);


	Fraction f3(-4, 8);

	CHECK((f3 == -0.5) == true);

	Fraction f4(-5, 2);

	CHECK((f4 == -2.5) == true);
}

#endif
#endif
/*
This file contains tests for Fraction class

Tests are include:
1. Creating fraction object
	a. by default
	b. by passing 1 int args
	c. by passing 2 ints args
	d. by passing other fraction
	e. by passing one double arg
2. Conversion from Fraction to double
3. Simplifying fraction
4. Overloaded operators
	a. unary minus
	b. operator +=
	c. operator -=
	d. operator *=
	e. operator /=
	f. operator +
	g. operator -
	h. operator *
	i. operator /
	g. operator <=>
	k. operator == (Fraction)
	l. operator == (double)
	m. operator == (int)

*/

#pragma once

#ifndef _TESTS_
#define _TESTS_

#ifdef DEBUG

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "fraction.h"
#include "doctest.h"

//1. CREATING FRACTION OBJECT

//a. by default
TEST_CASE("Creating fraction by default")
{
	Fraction f1;

	CHECK(f1.get_numerator() == 0);
	CHECK(f1.get_denominator() == 1);

	Fraction f2{};

	CHECK(f2.get_numerator() == 0);
	CHECK(f2.get_denominator() == 1);
}

//b. by passing 1 int arg
TEST_CASE("Creating fraction by passing 1 int arg")
{
	Fraction f1 = 0;

	CHECK(f1.get_numerator() == 0);
	CHECK(f1.get_denominator() == 1);

	Fraction f2(0);

	CHECK(f2.get_numerator() == 0);
	CHECK(f2.get_denominator() == 1);

	Fraction f3{ 0 };

	CHECK(f3.get_numerator() == 0);
	CHECK(f3.get_denominator() == 1);

	Fraction f4 = 5;

	CHECK(f4.get_numerator() == 5);
	CHECK(f4.get_denominator() == 1);

	Fraction f5{ -15 };

	CHECK(f5.get_numerator() == -15);
	CHECK(f5.get_denominator() == 1);
}

//c. by passing 2 int args
TEST_CASE("Creating fraction by passing 2 int args")
{
	Fraction f1(0, 1);

	CHECK(f1.get_numerator() == 0);
	CHECK(f1.get_denominator() == 1);

	Fraction f2(1, 2);

	CHECK(f2.get_numerator() == 1);
	CHECK(f2.get_denominator() == 2);

	Fraction f3(-1, 2);

	CHECK(f3.get_numerator() == -1);
	CHECK(f3.get_denominator() == 2);

	Fraction f4(1, -2);

	CHECK(f4.get_numerator() == 1);
	CHECK(f4.get_denominator() == -2);

	Fraction f5(4, 2);

	CHECK(f5.get_numerator() == 4);
	CHECK(f5.get_denominator() == 2);
}

//d. by passing other fraction
TEST_CASE("Creating fraction by passing other fraction")
{
	Fraction f1(0, 1);
	Fraction f2(f1);

	CHECK(f2.get_numerator() == 0);
	CHECK(f2.get_denominator() == 1);

	Fraction f3(1, 2);
	Fraction f4{ f3 };

	CHECK(f4.get_numerator() == 1);
	CHECK(f4.get_denominator() == 2);

	Fraction f5(-1, 2);
	Fraction f6(f5);

	CHECK(f6.get_numerator() == -1);
	CHECK(f6.get_denominator() == 2);

	Fraction f7(1, -2);
	Fraction f8(f7);

	CHECK(f8.get_numerator() == 1);
	CHECK(f8.get_denominator() == -2);

	Fraction f9(4, 2);
	Fraction f10{ f9 };

	CHECK(f10.get_numerator() == 4);
	CHECK(f10.get_denominator() == 2);
}

//e. by passing one double arg

TEST_CASE("Creating fraction by passing one double arg")
{
	Fraction f1 = 5.5;

	CHECK(f1.get_numerator() == 11);
	CHECK(f1.get_denominator() == 2);

	Fraction f2(22.5);

	CHECK(f2.get_numerator() == 45);
	CHECK(f2.get_denominator() == 2);

	Fraction f3{ 12 };

	CHECK(f3.get_numerator() == 12);
	CHECK(f3.get_denominator() == 1);

	Fraction f4 = 6.4;

	CHECK(f4.get_numerator() == 32);
	CHECK(f4.get_denominator() == 5);

	Fraction f5(-7.6);

	CHECK(f5.get_numerator() == -38);
	CHECK(f5.get_denominator() == 5);

	Fraction f6(0.0);

	CHECK(f6.get_numerator() == 0);
	CHECK(f6.get_denominator() == 1);

	Fraction f7(-44.2);

	CHECK(f7.get_numerator() == -221);
	CHECK(f7.get_denominator() == 5);

	Fraction f8(-0.333);

	CHECK(f8.get_numerator() == -333);
	CHECK(f8.get_denominator() == 1000);
}


//2. CONVERSION FROM FRACTION TO DOUBLE

TEST_CASE("Conversion from fraction fo double")
{
	Fraction f1(11, 2);
	double d = f1;

	CHECK(d == 5.5);

	Fraction f2(45, 2);
	d = f2;

	CHECK(d == 22.5);

	Fraction f3{ 12 };
	d = f3;

	CHECK(d == 12);

	Fraction f4(32, 5);
	d = f4;

	CHECK(d == 6.4);

	Fraction f5(-38, 5);
	d = f5;

	CHECK(d == -7.6);

	Fraction f6(0.0);
	d = f6;


	Fraction f7(-221, 5);
	d = f7;

	CHECK(d == -44.2);

	Fraction f8(-333, 1000);
	d = f8;

	CHECK(d == -0.333);

}

//3. SIMPLIFYING FRACTION

TEST_CASE("Simplifying fraction")
{
	Fraction f1;
	f1.simplify();

	CHECK(f1.get_numerator() == 0);
	CHECK(f1.get_denominator() == 1);

	Fraction f2(1, 2);
	f2.simplify();

	CHECK(f2.get_numerator() == 1);
	CHECK(f2.get_denominator() == 2);

	Fraction f3(2, 4);
	f3.simplify();

	CHECK(f3.get_numerator() == 1);
	CHECK(f3.get_denominator() == 2);

	Fraction f4(-8, 4);
	f4.simplify();

	CHECK(f4.get_numerator() == -2);
	CHECK(f4.get_denominator() == 1);

	Fraction f5(17, 5);
	f5.simplify();

	CHECK(f5.get_numerator() == 17);
	CHECK(f5.get_denominator() == 5);
}

//4. OVERLOADED OPERATORS

TEST_CASE("Unary minus operator")
{
	Fraction f1(0, 1);
	f1 = -f1;

	CHECK(f1.get_numerator() == 0);
	CHECK(f1.get_denominator() == 1);

	Fraction f2(1, 2);
	f2 = -f2;

	CHECK(f2.get_numerator() == -1);
	CHECK(f2.get_denominator() == 2);

	Fraction f3(-1, 2);
	f3 = -f3;

	CHECK(f3.get_numerator() == 1);
	CHECK(f3.get_denominator() == 2);

	Fraction f4(1, -2);
	f4 = -f4;

	CHECK(f4.get_numerator() == 1);
	CHECK(f4.get_denominator() == 2);

	Fraction f5(4, 2);
	f5 = -f5;

	CHECK(f5.get_numerator() == -2);
	CHECK(f5.get_denominator() == 1);
}

TEST_CASE("fraction+= operator")
{

	Fraction f1(1, 1);
	Fraction f2(1, 1);
	f1 += f2;

	CHECK(f1.get_numerator() == 2);
	CHECK(f1.get_denominator() == 1);

	Fraction f3(1, -1);
	Fraction f4(1, 1);
	f3 += f4;

	CHECK(f3.get_numerator() == 0);
	CHECK(f3.get_denominator() == 1);

	Fraction f5(5, 3);
	Fraction f6(-4, 4);
	f5 += f6;

	CHECK(f5.get_numerator() == 2);
	CHECK(f5.get_denominator() == 3);
}

TEST_CASE("fraction-= operator")
{

	Fraction f1(1, 1);
	Fraction f2(1, 1);
	f1 -= f2;

	CHECK(f1.get_numerator() == 0);
	CHECK(f1.get_denominator() == 1);

	Fraction f3(1, -1);
	Fraction f4(1, 1);
	f3 -= f4;

	CHECK(f3.get_numerator() == -2);
	CHECK(f3.get_denominator() == 1);

	Fraction f5(5, 3);
	Fraction f6(-4, 4);
	f5 -= f6;

	CHECK(f5.get_numerator() == 8);
	CHECK(f5.get_denominator() == 3);
}

TEST_CASE("fraction*= operator")
{
	Fraction f1;
	Fraction f2(2, -3);

	f1 *= f2;

	CHECK(f1.get_numerator() == 0);
	CHECK(f1.get_denominator() == -3);

	Fraction f3(5, 6);
	Fraction f4(3, 9);

	f3 *= f4;

	CHECK(f3.get_numerator() == 5);
	CHECK(f3.get_denominator() == 18);

	Fraction f5(0, 1);
	Fraction f6(12, -3);

	f5 *= f6;

	CHECK(f5.get_numerator() == 0);
	CHECK(f5.get_denominator() == -3);
}

TEST_CASE("fraction/= operator")
{
	Fraction f1;
	Fraction f2(2, -3);

	f1 /= f2;

	CHECK(f1.get_numerator() == 0);
	CHECK(f1.get_denominator() == 2);

	Fraction f3(5, 6);
	Fraction f4(3, 9);

	f3 /= f4;

	CHECK(f3.get_numerator() == 5);
	CHECK(f3.get_denominator() == 2);

	Fraction f5(0, 1);
	Fraction f6(12, -3);

	f5 /= f6;

	CHECK(f5.get_numerator() == 0);
	CHECK(f5.get_denominator() == 12);
}

TEST_CASE("fraction+ operator")
{

	Fraction f1(1, 1);
	Fraction f2(1, 1);

	Fraction f3 = f1 + f2;

	CHECK(f3.get_numerator() == 2);
	CHECK(f3.get_denominator() == 1);

	Fraction f4(1, -1);
	Fraction f5(1, 1);

	Fraction f6 = f4 + f5;

	CHECK(f6.get_numerator() == 0);
	CHECK(f6.get_denominator() == 1);

	Fraction f7(5, 3);
	Fraction f8(-4, 4);

	Fraction f9 = f7 + f8;

	CHECK(f9.get_numerator() == 2);
	CHECK(f9.get_denominator() == 3);
}

TEST_CASE("fraction- operator")
{

	Fraction f1(1, 1);
	Fraction f2(1, 1);

	Fraction f3 = f1 - f2;

	CHECK(f3.get_numerator() == 0);
	CHECK(f3.get_denominator() == 1);

	Fraction f4(1, -1);
	Fraction f5(1, 1);

	Fraction f6 = f4 - f5;

	CHECK(f6.get_numerator() == -2);
	CHECK(f6.get_denominator() == 1);

	Fraction f7(5, 3);
	Fraction f8(-4, 4);

	Fraction f9 = f7 - f8;

	CHECK(f9.get_numerator() == 8);
	CHECK(f9.get_denominator() == 3);
}

TEST_CASE("fraction* operator")
{
	Fraction f1;
	Fraction f2(2, -3);

	Fraction f3 = f1 * f2;
	CHECK(f3.get_numerator() == 0);
	CHECK(f3.get_denominator() == -3);

	Fraction f4(5, 6);
	Fraction f5(3, 9);

	Fraction f6 = f4 * f5;

	CHECK(f6.get_numerator() == 5);
	CHECK(f6.get_denominator() == 18);

	Fraction f7(0, 1);
	Fraction f8(12, -3);

	Fraction f9 = f7 * f8;

	CHECK(f9.get_numerator() == 0);
	CHECK(f9.get_denominator() == -3);
}

TEST_CASE("fraction/ operator")
{
	Fraction f1;
	Fraction f2(2, -3);

	Fraction f3 = f1 / f2;

	CHECK(f3.get_numerator() == 0);
	CHECK(f3.get_denominator() == 2);

	Fraction f4(5, 6);
	Fraction f5(3, 9);

	Fraction f6 = f4 / f5;

	CHECK(f6.get_numerator() == 5);
	CHECK(f6.get_denominator() == 2);

	Fraction f7(0, 1);
	Fraction f8(12, -3);

	Fraction f9 = f7 / f8;

	CHECK(f9.get_numerator() == 0);
	CHECK(f9.get_denominator() == 12);
}

TEST_CASE("fraction<=> operator")
{
	Fraction f1;
	Fraction f2;

	std::strong_ordering o1{ f1 <=> f2 };

	CHECK(o1 == std::strong_ordering::equal);

	Fraction f3(1, 2);
	Fraction f4(2, 4);
	std::strong_ordering o2{ f3 <=> f4 };

	CHECK(o2 == std::strong_ordering::equal);

	Fraction f5(-1, 2);
	Fraction f6(2, 7);
	std::strong_ordering o3{ f5 <=> f6 };

	CHECK(o3 == std::strong_ordering::less);

	Fraction f7(2, 9);
	Fraction f8(1, 9);
	std::strong_ordering o4{ f7 <=> f8 };

	CHECK(o4 == std::strong_ordering::greater);

	Fraction f9(3, 1);
	std::strong_ordering o5{ f9 <=> static_cast<Fraction>(3) };

	CHECK(o5 == std::strong_ordering::equal);
}

TEST_CASE("fraction== operator (Fraction)")
{

	Fraction f1;
	Fraction f2;

	CHECK((f1 == f2) == true);

	Fraction f3(1, 2);
	Fraction f4(2, 4);

	CHECK((f3 == f4) == true);

	Fraction f5(-1, -3);
	Fraction f6(3, 9);

	CHECK((f5 == f6) == true);
}

TEST_CASE("fraction== operator (int)")
{
	Fraction f1;

	CHECK((f1 == 0) == true);

	Fraction f2(6, 3);

	CHECK((f2 == 2) == true);


	Fraction f3(-4, 2);

	CHECK((f3 == -2) == true);
}

TEST_CASE("fraction== operator (double)")
{
	Fraction f1;

	CHECK((f1 == 0.0) == true);

	Fraction f2(4, 5);

	CHECK((f2 == 0.8) == true);


	Fraction f3(-4, 8);

	CHECK((f3 == -0.5) == true);

	Fraction f4(-5, 2);

	CHECK((f4 == -2.5) == true);
}

#endif
#endif
