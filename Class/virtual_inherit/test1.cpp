/*
 * Filename: test1.cpp
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

class A
{
public:
	A(int v = 100) : X(v) {};

	virtual void foo(void) {}

	int X;

};

class B : virtual public A
{
public:
	B(int v = 10) : Y(v), A(100) {};

	virtual void fooB(void) {}

	int Y;

};

class C : virtual public A
{
public:
	C(int v = 20) : Z(v), A(100) {}

	virtual void fooC(void) {}

	int Z;

};

class D : public B, public C
{
	D(int v = 40) : B(10), C(20), A(100), L(v) {}

	virtual void fooD(void) {}

	int L;

};


int main(int argc, char *argv[])
{

	cout  << sizeof(A) << "\t" << sizeof(B) << "\t" << sizeof(C) << "\t" << sizeof(D) << endl;

	return 0;
}
