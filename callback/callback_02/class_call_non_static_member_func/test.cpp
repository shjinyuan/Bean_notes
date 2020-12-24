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
	pthread_t TID;
	void func()
	{
		//子线程执行代码
		printf("\n%s %d  %s\n", __FILE__, __LINE__, __func__);
	}
public:
	bool startThread()
	{
		//启动子线程
		//typedef void *(*FUNC)(void *); //定义FUNC类型是一个指向函数的指针，该函数参数为void*，返回值为void*
		//FUNC callback = (FUNC)&MyClass::func;//强制转换func()的类型
		using FUNC = void *(*)(void *);//c++11 method
		FUNC callback = reinterpret_cast<FUNC>(&MyClass::func);
		//FUNC callback = (FUNC)&MyClass::func;
		int ret = pthread_create(&TID, NULL, callback, this);
		if (ret != 0)
			return false;
		else
			return true;
	}
};

int main()
{
	MyClass a;
	a.startThread();
	pause();
}
