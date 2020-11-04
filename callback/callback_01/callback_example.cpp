/*
 * Filename: callback_example.cpp
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/10/22 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-10-22
 * LastChange: 2020-10-22
 *    Version: v0.0.01
 *
 */
#include <stdio.h>
#include <algorithm>

bool cmp(int a, int b)
{
	printf("%d > %d ? %s \n", a, b, a > b ? "true" : "false");
	return a > b;
}

int main(void)
{
	int a[8] = {5, 43, 1, 7, 8, 13, 0, 74};
	std::sort(a, a + 8, cmp); //callback
	return 0;
}
