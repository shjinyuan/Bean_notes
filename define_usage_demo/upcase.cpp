/*
 * Filename: upcase.cpp
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/11/03 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-11-03
 * LastChange: 2020-11-03
 *    Version: v0.0.01
 *
 */
#include <iostream>

#include <stdio.h>
#include <string.h>
using namespace std;

#define UPCASE(c) (((c) >= 'a' && (c) <= 'z') ? ((c) + 'A' - 'a') : (c))
#define LOCASE(c) (((c) >= 'A' && (c) <= 'Z') ? ((c) + 'a' - 'A') : (c))


#define UPcaseStr(str) UpcaseStr_case3(str)

void UpcaseStr_case1()
{
	char str[20] = "test_upcase_lowcase";
	for (int i = 0; i < sizeof(str); i++) {
		str[i] = UPCASE(str[i]);
	}
	cout << __func__ << endl << str << endl;
}


void UpcaseStr_case2(std::string str)
{
	char tmp[20];
	strcpy(tmp, str.c_str());
	for (int i = 0; i < sizeof(tmp); i++) {
		tmp[i] = UPCASE(tmp[i]);
	}
	cout << __func__ << endl << tmp << endl;
}

void UpcaseStr_case3(char *str)
{
	char tmp[20];
	strcpy(tmp, str);
	for (int i = 0; i < sizeof(tmp); i++) {
		tmp[i] = UPCASE(tmp[i]);
	}
	cout << __func__ << endl << tmp << endl;
}

int main()
{
	UpcaseStr_case1();

	std::string test = "test_hello";
	UpcaseStr_case2(test);

	char *test1 = "welcome";
	//char *test1=(char*)"welcome";
	UpcaseStr_case3(test1);

#if 0
	char s = 'a';
	cout << UPCASE(s) << endl;
	cout << (char)UPCASE(s) << endl;
	cout << LOCASE(s) << endl;
	cout << (char)LOCASE(s) << endl;
#endif
	return 0;
}
