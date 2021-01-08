/*
 * Filename: test.cpp
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2021/01/07 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2021-01-07
 * LastChange: 2021-01-07
 *    Version: v0.0.01
 *
 */

/*atoi		Convert string to integer*/
/*atol		Convert string to long integer*/
/*atof		Convert string to double*/
/*strtol	Convert string to long integer*/
/*strtoul	Convert string to unsigned long integer*/
/*strtod	Convert string to double*/

#include<iostream>
#include<string>
#include <sstream>

using namespace std;
int main()
{

//c风格字符串转int
	const char *c ="1024";
	int a =  atoi(c);
	cout << a << endl;


//int转c风格字符串
	int number = 100;
	char str[7];
	sprintf(str,"%d",number);
	cout << str << endl;


//string 转int
	/*方法1：atoi   c_str()   */
	string str2 = "1000";
	int n = atoi(str2.c_str());
	cout << n << endl;


	/*方法2： 流实现*/
	stringstream ss2;
	int n4;
	string str4 = "1235466";
	ss2 << str4;
	ss2 >> n4;
	cout << n4 << endl;




//int 转string
	/* 方法1：   to_string             */
	int i = 12;
	cout << std::to_string(i) << endl;


	/* 方法2： 流实现*/
	stringstream ss;
	int n1 = 123;
	string str3;
	ss << n1;
	ss >> str3;
	cout << str3 << endl;
	system("pause");
}
