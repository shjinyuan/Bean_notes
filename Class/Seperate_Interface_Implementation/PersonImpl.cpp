/*
 * Filename: PersonImpl.cpp
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

#include "PersonImpl.h"

PersonImpl::PersonImpl(const string& name):
    mName(name)
{
	printf("Construtor PersonImpl\n");
}

PersonImpl::~PersonImpl() {
	printf("DeConstrutor PersonImpl\n");
}

//string& PersonImpl::getName() const {
const string PersonImpl::getName() {
    return mName;
}

void PersonImpl::setName(string& name) {
    mName = name;
}

int PersonImpl::getAge() const {
    return mAge;
}

void PersonImpl::setAge(int age) {
    mAge = age;
}
