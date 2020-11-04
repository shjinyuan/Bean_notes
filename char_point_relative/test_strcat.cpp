/*
 * Filename: test_strcat.cpp
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/10/27 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-10-27
 * LastChange: 2020-10-27
 *    Version: v0.0.01
 *
 */
#include <iostream>
#include <string.h>

int main()
{
	std::string origin_char = "\"";
	std::string str_test = "for_test";

	char *test_char1 = (char *)origin_char.c_str();
	char *test_char2 = (char *)str_test.c_str();
	strcat(strcat(test_char1, test_char2),"\"");
	//strcat(test_char1, "\"");
	printf("test char* =%s\n", test_char1);
	printf("%ld\n",strlen(test_char1));
}
