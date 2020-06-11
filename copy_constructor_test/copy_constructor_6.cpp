/*
 * Filename: copy_constructor_6.cpp
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/06/10 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-06-10
 * LastChange: 2020-06-10
 *    Version: v0.0.01
 *
 */
#include<iostream>
#include<assert.h>
using namespace std;
class Rect
{
public:
	Rect()
	{
		cout <<"Rect()"<<endl;
		p=new int(100);
	}

	Rect(const Rect& r)
	{
		cout <<"copy Rect()"<<endl;
		width=r.width;
		height=r.height;
		p=new int(100);
		*p=*(r.p);
	}

	~Rect()
	{
		cout <<"~Rect()"<<endl;
		cout <<p<<endl;
		assert(p!=NULL);
		delete p;
	}
private:
	int width;
	int height;
	int *p;
};
int main()
{
	Rect rect1;
	Rect rect2(rect1);
	return 0;
}
