/*
 * Filename: test.cpp
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/06/21 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-06-21
 * LastChange: 2020-06-21
 *    Version: v0.0.01
 *
 */
#include <iostream>
#include "pureClassDemoImp.h"

int main(){
	pureClassDemoImp *test_demo = new pureClassDemoImp();
	test_demo->DisplayMessage(" hahaha~ ");
	test_demo->showName();
}
