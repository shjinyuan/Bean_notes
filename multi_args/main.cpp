/*
 * Filename: main.cpp
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/11/29 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-11-29
 * LastChange: 2020-11-29
 *    Version: v0.0.01
 *
 */
#include <iostream>
#include <bitset>
#include "test.h"



int main()
{
	A_Test a;
	a.print(1, 3.1415, "Hello, world!", 1.618, true, std::bitset<16>(377), 40);
	return 0;
}
