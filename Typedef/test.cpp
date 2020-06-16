/*
 * Filename: test.cpp
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/06/16 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-06-16
 * LastChange: 2020-06-16
 *    Version: v0.0.01
 *
 */
#include<stdio.h>
#include <assert.h>

typedef int (*FP_CALC)(int, int); //注意这里不是函数声明而是函数定义，它是一个地址，你可以直接输出add看看

int add(int a, int b)
{
	printf("==%s== in file: %s called at line: %d\n",__FUNCTION__,__FILE__,__LINE__);
	return a + b;
}

int sub(int a, int b)
{
	printf("==%s== in file: %s called at line: %d\n",__FUNCTION__,__FILE__,__LINE__);
	return a - b;
}

int mul(int a, int b)
{
	printf("==%s== in file: %s called at line: %d\n",__FUNCTION__,__FILE__,__LINE__);
	return a * b;
}

int div(int a, int b)
{
	printf("==%s== in file: %s called at line: %d\n",__FUNCTION__,__FILE__,__LINE__);
	return b? a/b : -1;
}

//定义一个函数，参数为op，返回一个指针。该指针类型为 拥有两个int参数、
//返回类型为int 的函数指针。它的作用是根据操作符返回相应函数的地址
FP_CALC calc_func(char op)
{
	switch (op)
	{
	case '+': return add;//返回函数的地址
	case '-': return sub;
	case '*': return mul;
	case '/': return div;
	default:
			  return NULL;
	}
	printf("==%s== in file: %s called at line: %d\n",__FUNCTION__,__FILE__,__LINE__);
	return NULL;
}

//s_calc_func为函数，它的参数是 op，
//返回值为一个拥有 两个int参数、返回类型为int 的函数指针
int (*s_calc_func(char op)) (int, int)
{
	printf("==%s== in file: %s called at line: %d\n",__FUNCTION__,__FILE__,__LINE__);
	return calc_func(op);
}

//最终用户直接调用的函数，该函数接收两个int整数，和一个算术运算符，返回两数的运算结果
int calc(int a, int b, char op)
{
	printf("==%s== in file: %s called at line: %d\n",__FUNCTION__,__FILE__,__LINE__);
	FP_CALC fp = calc_func(op); //根据预算符得到各种运算的函数的地址
#ifdef DEBUG
	printf("Debug Message show while compile with 'Debug' option ");
	int (*s_fp)(int, int) = s_calc_func(op);//用于测试
	assert(fp == s_fp);   // 可以断言这俩是相等的
#endif
	if (fp) return fp(a, b);//根据上一步得到的函数的地址调用相应函数，并返回结果
	else return -1;
}

int main()
{
	int a = 10, b = 2;

	printf("calc(%d, %d, %c) = %d\n\n", a, b, '+', calc(a, b, '+'));
	printf("calc(%d, %d, %c) = %d\n\n", a, b, '-', calc(a, b, '-'));
	printf("calc(%d, %d, %c) = %d\n\n", a, b, '*', calc(a, b, '*'));
	printf("calc(%d, %d, %c) = %d\n\n", a, b, '/', calc(a, b, '/'));
}
