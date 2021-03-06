/*
 * Filename: test.cpp
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
#include <iostream>
#include <unistd.h>

using namespace std;

class A
{
public:
	A() : m_data1(0), m_data2(0) {}
	virtual void vfunc1()
	{
		cout << "A::vfunc1" << endl;
	};
	virtual void vfunc2()
	{
		cout << "A::vfunc2" << endl;
	};
	void func1()
	{
		cout << "A::func1" << endl;
	};
	void func2()
	{
		cout << "A::func2" << endl;
	};
private:
	int m_data1, m_data2;
};

class B : public A
{
public:
	B() : A(), m_data3(0) {}
	virtual void vfunc1()
	{
		cout << "B::vfunc1" << endl;
	};
	void func1()
	{
		cout << "B::func1" << endl;
	};
private:
	int m_data3;
};

class C: public B
{
public:
	C() : B(), m_data1(0), m_data4(0) {}
	virtual void vfunc2()
	{
		cout << "C::vfunc2" << endl;
	};
	void func2()
	{
		cout << "C::func2" << endl;
	};
private:
	int m_data1, m_data4;
};


int main()
{
	B bObject;
	A *p = &bObject;
	p->vfunc1();

	A aObject = (A)bObject;
	aObject.vfunc1();

	C cObject;
	p = &cObject;
	p->vfunc1();
	p->vfunc2();

	cObject.A::func1();
	pause();
}
