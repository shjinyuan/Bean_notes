/*
 * Filename: test.cpp
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/12/08 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-12-08
 * LastChange: 2020-12-08
 *    Version: v0.0.01
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(int argc, char *argv[])
{

	std::vector<std::string> vec1{"jin", "zhao", "li", "qian"};
	std::vector<std::string> vec2{ "wang", "zhao", "li"};

	std::string ele;
	std::vector<std::string>::iterator it1;
	std::vector<std::string>::iterator it2;

	for (it2 = vec2.begin(); it2 < vec2.end(); it2++) {
		it1 = find(vec1.begin(), vec1.end(), *it2);
		if (it1 != vec1.end()) {
			cout << *it2 << endl;
		}
	}

	return 0;
}
