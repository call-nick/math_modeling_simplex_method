#pragma once

#ifndef SMATRIX_H
#define SMATRIX_H

#include <iostream> 	//for "print" method
#include <utility> 	//for std::pair
#include <compare> 	//for <=> operator
#include <vector>
#include <string>
#include <format>
#include "fraction.h"

using std::vector;

class Smatrix
{
private:
	const size_t ROWS, COLS;
	vector<vector<Fraction>> matrix;
	vector<char> table_header_cols; //for "print" method
	vector<char> table_header_rows;

	//return -1 if key column doesn't exist
	int find_key_column() const;

	//return -1 key column doesn't exist
	int find_key_column_by_min_index() const;

	//return -1 if key row doesn't exist
	int find_key_row(const size_t COL);

	//make jordans permutation
	void make_permutation(const size_t ROW, const size_t COL, bool all_steps);

public:
	Smatrix(vector<vector<Fraction>> matrix);
	~Smatrix();

	void show_solution_with_steps(bool all_steps);

	void print() const;
};

#endif

/* The algorytm
 * create s table (then print)
 * start:
 * check negative element
 * if negative element doesn't exist then stop the algorytm
 * else find key column (then print)
 * find key row (then print)
 * find key element (then print)
 * if key element doesn't exist stop the algorythm
 * else make an Jordans permutation with row and col where is placed key element
 * goto start;
 */