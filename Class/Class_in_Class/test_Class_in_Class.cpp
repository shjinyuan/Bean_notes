/*
 * Filename: test_Class_in_Class.cpp
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/06/12 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-06-12
 * LastChange: 2020-06-12
 *    Version: v0.0.01
 *
 */
#include <iostream>
using namespace std;

class c1
{
public:
	int a;
	void foo();
	class c2
	{
	public:
		int a;
		void foo();
	} b;
};
void c1::foo()
{
	a = 1;
	cout<< "set a = "<< a <<endl;
}
void c1::c2::foo()
{
	a = 2;
	cout << "c2"<< "set a = "<< a <<endl;
}

int main()
{

	class c1 f;
	f.foo();
	f.b.foo();
	cout << "f.a = " << f.a << endl;
	cout << "f.b.a = " << f.b.a << endl;
	return 0;
}
