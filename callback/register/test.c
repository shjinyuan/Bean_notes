/*
 * Filename: test.c
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/12/24 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-12-24
 * LastChange: 2020-12-24
 *    Version: v0.0.01
 *
 */
#include <stdio.h>

int (*p[5])() = {NULL};  // 创建一个函数指针数组

int hook()  // 官方封装起来
{
	int i = 0;
	for (i = 0; i < 5; i++) {
		if (p[i] != NULL) {
			p[i]();
		}
	}
}

int register_hook_callback(int (*p_callback)())  // 只是提供一个注册函数
{
	int i = 0;
	for (i = 0; i < 5; i++) {
		if (p[i] == NULL) {
			p[i] = p_callback;
			break;
		}
	}
}


int test01()  // 用户自己要添加的注册函数的函数
{
	printf("\ntest01 callback\n");
}
int test02()
{
	printf("\ntest02 callback\n");
}
int test03()
{
	printf("\ntest03 callback\n");
}

int test04()
{
	printf("\ntest04 callback\n");
}

int test05()
{
	printf("\ntest05 callback\n");
}

int test06()
{
	printf("\ntest06 callback\n");
}

int main(int argc, char *argv[])   // 这个一般情况时官方封装成一个库函数，上电就会一直运行，类似守护进程
{
	register_hook_callback(test01);
	register_hook_callback(test02);
	register_hook_callback(test04);
	register_hook_callback(test05);
	register_hook_callback(test06);
	while (1) {
		hook();
		printf("=====运行========\n");
		sleep(1);
	}
}

