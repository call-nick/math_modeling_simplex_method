#include "smatrix.h"

Smatrix::Smatrix(vector<vector<Fraction>> matrix) : matrix(matrix), ROWS(matrix.size()), COLS(matrix[0].size())
{
	for (size_t i{ 1 }; i < COLS; ++i)
	{
		table_header_cols.push_back(i + '0');
	}

	//table_header_rows.push_back('0');

	for (size_t i{ COLS }; i < ROWS + COLS; ++i)
	{
		table_header_rows.push_back(i + '0');
	}
}

Smatrix::~Smatrix() {}

int Smatrix::find_key_column_by_min_index() const
{
	for (size_t i{}; i < this->COLS; ++i)
	{
		if (matrix[ROWS - 1][i] < 0)
			return i;
	}
	return -1;
}

int Smatrix::find_key_column() const
{
	Fraction min_element = matrix[ROWS - 1][0]; //the first element of the last row
	size_t col{};

	for (size_t i{}; i < this->COLS; ++i)
	{
		if (matrix[ROWS - 1][i] < min_element)
		{
			min_element = matrix[ROWS - 1][i];
			col = i;
		}
	}

	return min_element < 0 ? col : -1;
}

//Need to do this method `const`
int Smatrix::find_key_row(const size_t COL)
{
	Fraction min_divisor(-1, 1);

	size_t row{};

	for (size_t i{}; i < this->ROWS; ++i)
	{
		if (matrix[i][COL].get_numerator() == 0) continue; //can't divide by zero
		Fraction ratio = matrix[i][0] / matrix[i][COL];
		if (min_divisor > 0 && ratio < min_divisor && ratio > 0)
		{
			min_divisor = ratio;
			row = i;
		}
		else if (min_divisor < 0)
		{
			min_divisor = ratio;
			row = i;
		}
	}

	return min_divisor > 0 ? row : -1;

}

void Smatrix::make_permutation(const size_t ROW, const size_t COL, bool all_steps)
{
	auto old_matrix = this->matrix;

	for (size_t i{}; i < this->ROWS; ++i)
	{
		if (i == ROW) continue;
		matrix[i][COL] = -matrix[i][COL] / matrix[ROW][COL];
		matrix[i][COL].simplify();
	}

	for (size_t i{}; i < this->COLS; ++i)
	{
		if (i == COL) continue;
		matrix[ROW][i] = matrix[ROW][i] / matrix[ROW][COL];
		matrix[ROW][i].simplify();
	}

	for (size_t i{}; i < this->ROWS; ++i)
	{
		for (size_t j{}; j < this->COLS; ++j)
		{
			if (i == ROW || j == COL) continue;

if (all_steps) {
			std::cout << std::endl <<  "matrix[i][j]: ";
			matrix[i][j].print();
			std::cout << std::endl;

			std::cout << "oldmatrix[ROW][j]: ";
			old_matrix[ROW][j].print();
			std::cout << std::endl;

			std::cout << "oldmatrix[i][COL]: ";
			old_matrix[i][COL].print();
			std::cout << std::endl;

			std::cout << "oldmatrix[ROW][j] * oldmatrix[i][COL]: ";
			(old_matrix[ROW][j] * old_matrix[i][COL]).print();
			std::cout << std::endl;

			std::cout << "oldmatrix[ROW][j] * oldmatrix[i][COL] / key_element: ";
			((old_matrix[ROW][j] * old_matrix[i][COL]) / matrix[ROW][COL]).print();
			std::cout << std::endl;

			std::cout << "result (old_matrix[i][j] - ((old_matrix[ROW][j] * old_matrix[i][COL]) / old_matrix[ROW][COL]): ";
			(old_matrix[i][j] - ((old_matrix[ROW][j] * old_matrix[i][COL]) / old_matrix[ROW][COL])).print();
			std::cout << std::endl;
		}
			matrix[i][j] = old_matrix[i][j] - ((old_matrix[ROW][j] * old_matrix[i][COL]) / matrix[ROW][COL]);
			matrix[i][j].simplify();
			//matrix[i][j] /= old_matrix[ROW][COL];
		}
	}

	Fraction f(1, 1);

	matrix[ROW][COL] = f / matrix[ROW][COL];

	char buff{ this->table_header_rows[ROW] };
	this->table_header_rows[ROW] = table_header_cols[COL - 1];
	this->table_header_cols[COL - 1] = buff;
}

void Smatrix::show_solution_with_steps(bool all_steps = false)
{
	std::cout << std::endl << "Initial matrix:" << std::endl;
	this->print(); std::cout << std::endl;

	for (size_t i{ 1 }; ; ++i)
	{
		int key_col{}, key_row{};

		key_col = this->find_key_column();
		if (key_col == -1) break;
		std::cout << "The key column: X" << table_header_cols[key_col - 1] - '0' << std::endl;

		key_row = this->find_key_row(key_col);
		if (key_row == -1) break;
		std::cout << "The key row: X" << table_header_rows[key_row] - '0' << std::endl;

		std::cout << "The key element: ";
		this->matrix[key_row][key_col].print();
		std::cout << std::endl;

		this->make_permutation(key_row, key_col, all_steps);
		std::cout << std::endl << "S table after " << i << " permutation:" << std::endl << std::endl;
		this->print();
		std::cout << std::endl;
	}

	std::cout << "Result matrix:" << std::endl << std::endl;
	this->print(); std::cout << std::endl;
}

void Smatrix::print() const
{

	std::cout << std::format("{:>8}|{:>8}|", "0", "1");

	for (auto h : this->table_header_cols)
	{
		std::cout << std::format("{:>8}|", "-X" + std::to_string((int)h - '0'));
	}

	std::cout << std::endl;

	for (size_t i{}; i < COLS + 1; ++i)
	{
		std::cout << "---------";
	}

	std::cout << std::endl;

	for (size_t i{}; i < ROWS; ++i)
	{
		if (i == ROWS - 1)
			std::cout << std::format("{:>8}|", "f");
		else
			std::cout << std::format("{:>8}|", "X" + std::to_string((int)table_header_rows[i] - '0'));
		for (size_t j{}; j < COLS; ++j)
		{
			if (matrix[i][j].get_numerator() == 0)
			{
				std::cout << std::format("{:8}|", matrix[i][j].get_numerator());
			}
			else if (matrix[i][j].get_denominator() == 1)
			{
				std::cout << std::format("{:8}|", matrix[i][j].get_numerator());
			}
			else if (matrix[i][j].get_denominator() == -1)
			{
				std::cout << std::format("{:8}|", -matrix[i][j].get_numerator());
			}
			else
			{
				std::cout << std::format("{:>8}|", std::to_string(matrix[i][j].get_numerator()) + "/" + std::to_string(matrix[i][j].get_denominator()));
			}
		}
		std::cout << std::endl;
	}


}
