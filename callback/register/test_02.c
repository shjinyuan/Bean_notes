/*
 * Filename: test.c
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/12/25 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-12-25
 * LastChange: 2020-12-25
 *    Version: v0.0.01
 *
 */
#include <stdio.h>

typedef void(*ptrFun)(char *);//用typedef定义函数指针，也将其成为新的类型
void CallerFun(ptrFun fun)//父函数
{
	printf("==Start callback fun==\n");
	fun("Hi callback function");
	printf("==End callback fun==\n");
}

void CallbackFun(char * S)//回调函数
{
	printf("%s-----------\n", S);
}

int main()
{
	/* 调用 方法一 */
	ptrFun PP;
	PP = CallbackFun;
	CallerFun(PP);

	/* 调用方法二 */
	CallerFun(CallbackFun);//直接作为参数也是没问题的
	system("pause()");
	return 0;
}
