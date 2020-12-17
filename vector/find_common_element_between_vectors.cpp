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

	std::string first[]  {"jin", "zhao", "li"};
	std::string second[] {"Lin", "hao", "li", "bai"};

	std::sort(first,first+3);
	std::sort(second,second+4);

	return 0;
}
