/*
 * Filename: Person.cpp
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
#include "Person.h"
#include "PersonImpl.h"

Person::Person(const string& name):
    mPersonImpl(new PersonImpl(name))
{
    std::cout << "construct Person" << std::endl;
}

Person::~Person() {
    delete mPersonImpl;
    std::cout << "deconstruct Person" << std::endl;
}

string Person::getName(){
    return mPersonImpl->getName();
}

void Person::setName(string& name) {
    mPersonImpl->setName(name);
}

int Person::getAge() const {
    return mPersonImpl->getAge();
}

void Person::setAge(int age) {
    mPersonImpl->setAge(age);
}
