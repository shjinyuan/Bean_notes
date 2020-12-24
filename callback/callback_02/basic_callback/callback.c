/*
 * Filename: callback.c
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/11/01 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-11-01
 * LastChange: 2020-11-01
 *    Version: v0.0.01
 *
 */
#include <stdio.h>
void printWelcome(int len)//callback1
{
       printf("欢迎欢迎 -- %d\n", len);
}

void printGoodbye(int len)//callback2
{
       printf("送客送客 -- %d\n", len);
}

void regist_callback(int times, void (* print)(int))
{
       int i;
       for (i = 0; i < times; ++i)
       {
              print(i);
       }
       printf("\n我不知道你是迎客还是送客!\n\n");
}

void main(void)
{
       regist_callback(10, printWelcome);
       regist_callback(10, printGoodbye);
       printWelcome(5);
}
