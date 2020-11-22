/*
 * Filename: main.cpp
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/11/22 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-11-22
 * LastChange: 2020-11-22
 *    Version: v0.0.01
 *
 */
#include <iostream>     // std::cout
#include <algorithm>    // std::find_if
#include <vector>       // std::vector

bool IsOdd (int i) {
  return ((i%2)==1);
}

int main () {
  std::vector<int> myvector;

  myvector.push_back(10);
  myvector.push_back(25);
  myvector.push_back(40);
  myvector.push_back(55);

  std::vector<int>::iterator it = std::find_if (myvector.begin(), myvector.end(),IsOdd);
  std::cout << "The first odd value is " << *it << '\n';

  std::vector<int>::iterator it1 = std::find_if (myvector.begin(), myvector.end(), [](auto &a){return a%2==1;});//using lambda
  std::cout << "The first odd value is " << *it1 << '\n';

  return 0;
}
