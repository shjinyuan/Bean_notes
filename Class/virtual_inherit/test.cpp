/*
 * Filename: test.c
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2021/03/24 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2021-03-24
 * LastChange: 2021-03-24
 *    Version: v0.0.01
 *
 */
#include <iostream>
using namespace std;

#define CASE1

#ifdef CASE1
//第一种情况
	class a
	{
		virtual void func();
	};

	class b: public virtual a
	{
		virtual void foo();
	};
#endif
#ifdef CASE2
//第二种情况
	class a
	{
		virtual void func();
	};

	class b : public a
	{
		virtual void foo();
	};
	break;
#endif
#ifdef CASE3
//第三种情况
	class a
	{
		virtual void func();
		char x;
	};

	class b: public virtual a
	{
		virtual void foo();
	};
	break;
#endif
#ifdef CASE4
//第四种情况
	class a
	{
		virtual void func();
		char x;
	};

	class b: public a
	{
		virtual void foo();
	};
#endif
//int main(int argc, char *argv[])
int main()
{

	cout << "a:" << sizeof(a) << endl;
	cout << "b:" << sizeof(b) << endl;
	return 0;
}
