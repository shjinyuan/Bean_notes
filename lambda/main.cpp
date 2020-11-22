/*
 * Filename: main.cpp
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/11/13 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-11-13
 * LastChange: 2020-11-13
 *    Version: v0.0.01
 *
 */
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
int main(void)
{
	auto ret = [](int a, int b) {
		return a > b ? a : b;
	};

	std::vector<double> vec  {1.8,2.3,2,3,4,4,4,5,6,8,9};
	//std::vector<int> vec  {1,2,2,3,4,4,4,5,6,8,9};

	cout << accumulate(vec.begin(), vec.end(), 0) << endl;
	cout << accumulate(vec.cbegin(), vec.cend(), 0.0) << endl; // the 3rd param decide the resuslt is 48 or 49.1
	std::vector<int> myvector = {10, 20, 30, 40, 50};
	std::cout << "myvector contains:";

	for (auto it = myvector.cbegin(); it != myvector.cend(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	return 0;
}
