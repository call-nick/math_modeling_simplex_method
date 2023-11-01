#ifndef DEBUG

#include <iostream>
#include <vector>
#include "fraction.h"
#include "smatrix.h"

using std::vector;
using std::cin;
using std::cout;
using std::format;
using std::endl;

void enter_smatrix_with_fraction(vector<vector<Fraction>>& matrix, const size_t ROWS, const size_t COLS)
{
	int numerator{};
	int denominator{};

	for (size_t i{}; i < ROWS; ++i)
	{
		for (size_t j{}; j < COLS; ++j)
		{
			cout << format("Input numerator (row {}, col {})", i + 1, j + 1) << endl;
			cin >> numerator;
			cout << "Input denominator:" << endl;
			cin >> denominator;
			Fraction f(numerator, denominator);
			matrix[i].push_back(f);
		}
	}
}

void enter_smatrix(vector<vector<Fraction>>& matrix, const size_t ROWS, const size_t COLS)
{
	double number{};

	for (size_t i{}; i < ROWS; ++i)
	{
		for (size_t j{}; j < COLS; ++j)
		{
			cout << format ("Input number (row {}, col {})", i + 1, j + 1) << endl;
			cin >> number;
			Fraction f = number;
			matrix[i].push_back(f);
		}
	}
}

int main(int argc, char* argv[])
{
	std::cout << "Welcome to the matmod program" << endl;
	std::cout << "Version 0.2.1" << endl << endl;

	size_t ROWS;
	size_t COLS;
	bool need_fraction = false;
	bool need_all_calculations = false;

	std::cout << "How many rows in STable:" << endl;
	cin >> ROWS;
	cout << "How many cols in STable:" << endl;
	cin >> COLS;

	cout << "Are there number in your STable that can only be represented by a fraction?(y/n)" << endl;
	{
		char user_answer;
		cin >> user_answer;
		if (user_answer == 'y' || user_answer == 'Y') need_fraction = true;
	}


	cout << "Do you want to see ALL calculations?(y/n). Recommended to disable" << endl;
	{
		char user_answer;
		cin >> user_answer;
		if (user_answer == 'y' || user_answer == 'Y') need_all_calculations = true;
	}


	vector<vector<Fraction>> matrix(ROWS, vector <Fraction>());

	if (need_fraction)
		enter_smatrix_with_fraction(matrix, ROWS, COLS);
	else
		enter_smatrix(matrix, ROWS, COLS);

	Smatrix smatrix(matrix);

	smatrix.show_solution_with_steps(need_all_calculations);

	system("pause");
	
	return 0;
}
#endif
