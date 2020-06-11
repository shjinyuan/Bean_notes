/*
 * Filename: copy_constructor_2.cpp
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/06/09 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-06-09
 * LastChange: 2020-06-09
 *    Version: v0.0.01
 *
 */
#include <iostream>
using namespace std;

class Line
{
public:
	int getLength( void );
	Line( int len );             // 简单的构造函数
	Line( const Line &obj);      // 拷贝构造函数
	~Line();                     // 析构函数

private:
	int *ptr;
};

// 成员函数定义，包括构造函数
Line::Line(int len)
{
	cout << "调用构造函数" << endl;
	// 为指针分配内存
	ptr = new int;
	*ptr = len;
}

Line::Line(const Line &obj)
{
	cout << "调用拷贝构造函数并为指针 ptr 分配内存" << endl;
	ptr = new int;
	*ptr = *obj.ptr; // 拷贝值
}

Line::~Line(void)
{
	cout << "释放内存" << endl;
	delete ptr;
}
int Line::getLength( void )
{
	return *ptr;
}

void display(Line obj)
{
	cout << "line 大小 : " << obj.getLength() <<endl;
}

// 程序的主函数
int main( )
{
	cout << "----------- Line line1(10) --------" << endl;
	Line line1(10);

	cout << "----------- Line line2 = line1 ---------"<< endl;
	Line line2 = line1; // 这里也调用了拷贝构造函数

	cout << "----------- display(line1) -------------"<< endl;
	display(line1);

	cout << "----------- display(line2) -------------"<< endl;
	display(line2);

	cout << "----------- return before -------------"<< endl;
	return 0;
}
