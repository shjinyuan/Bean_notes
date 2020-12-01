/*
 * Filename: main.cpp
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/11/30 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-11-30
 * LastChange: 2020-11-30
 *    Version: v0.0.01
 *
 */
#include <iostream>
#include "AsyncTimer.h"


void test() {
    std::cout << "hello world\n";
}

int main()
{
    std::cout << "case 1\n";
    Timer t;
    t.start(1, test);
    std::this_thread::sleep_for(2000ms);
    t.stop();

    std::cout << "case 2\n";
	Timer t_2;
    t_2.start(1, test);
    std::this_thread::sleep_for(120ms);
    t_2.stop();

}
