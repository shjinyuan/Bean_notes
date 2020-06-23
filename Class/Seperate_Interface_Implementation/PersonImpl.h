/*
 * Filename: PersonImpl.h
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/06/22 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-06-22
 * LastChange: 2020-06-22
 *    Version: v0.0.01
 *
 */

#ifndef _PERSONIMPL_H
#define _PERSONIMPL_H
#include <string>
#include <iostream>
using namespace std;

class PersonImpl {
public:
	PersonImpl(string& name);
	virtual ~PersonImpl();

	string& getName() const;
	void setName(string& name);
	int getAge() const;
	void setAge(int age);

private:
	string& mName;
	int mAge;
};

#endif
