/*
 * Filename: copy_constructor_3.cpp
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
#include <iostream>
using namespace std;
class Rect
{
public:
	Rect()
	{
		count++;
	}
	~Rect()
	{
		count--;
	}
	static int getCount()
	{
		return count;
	}
private:
	int width;
	int height;
	static int count;
};
int Rect::count=0;
int main()
{
	Rect rect1;
	cout<<"The count of Rect:"<<Rect::getCount()<<endl;
	Rect rect2(rect1);
	cout<<"The count of Rect:"<<Rect::getCount()<<endl;
	return 0;
}
