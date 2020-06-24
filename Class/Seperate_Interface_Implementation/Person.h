/*
 * Filename: Person.h
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

#ifndef _PERSON_H
#define _PERSON_H
#include <string>
class PersonImpl;
using namespace std;

class Person {
public:
    Person(const string& name);
    virtual ~Person();

    string getName();
    void setName(string& name);
    int getAge() const;
    void setAge(int age);

private:
    PersonImpl *mPersonImpl;
};

#endif
