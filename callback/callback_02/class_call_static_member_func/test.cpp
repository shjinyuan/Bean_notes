/*
 * Filename: test.cpp
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/12/23 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-12-23
 * LastChange: 2020-12-23
 *    Version: v0.0.2
 *
 */
#include <iostream>
#include <unistd.h>

class MyClass
{
	static MyClass *CurMy;//存储回调函数调用的对象
	static void *callback(void *); //回调函数
	void func();
	void setCurMy();
	pthread_t TID;

public:
	bool startThread();
};

MyClass *MyClass::CurMy = NULL;

void *MyClass::callback(void *)
{
	CurMy->func();
	return NULL;
}

bool MyClass::startThread()
{
	//启动子线程
	setCurMy();
	int ret = pthread_create(&TID, NULL, MyClass::callback, NULL);
	if (ret != 0)
		return false;
	else
		return true;
}

void MyClass::func()
{
	//子线程执行代码
	printf("\n%s %s  %d\n", __FILE__, __func__, __LINE__);
}

void MyClass::setCurMy()
{
	//设置当前对象为回调函数调用的对象
	printf("\n%s %s  %d\n", __FILE__, __func__, __LINE__);
	CurMy = this;
}



int main()
{
	MyClass a;
	a.startThread();
	pause();
}
