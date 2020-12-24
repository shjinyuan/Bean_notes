/*
 * Filename: test_callback_in_class.cpp
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/11/02 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-11-02
 * LastChange: 2020-11-02
 *    Version: v0.0.01
 *
 */
#include <iostream>
#include <pthread.h>

static void *callback(void *arg);
class MyClass
{
	pthread_t TID;
public:
	void func()
	{
		//子线程执行代码
		printf("\n %s \n",__func__);
	}

	bool startThread()
	{
		//启动子线程
		printf("\n %s \n",__func__);
		int ret = pthread_create(&TID, NULL, callback, this);
		if (ret != 0)
			return false;
		else
			return true;
	}
};

static void *callback(void *arg)
{
	//回调函数
	((MyClass *)arg)->func(); //调用成员函数
	return NULL;
}

int main()
{
	MyClass a;
	a.startThread();
}
