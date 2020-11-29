/*
 * Filename: test.h
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/11/29 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-11-29
 * LastChange: 2020-11-29
 *    Version: v0.0.01
 *
 */

#ifndef _TEST_H
#define _TEST_H


class A_Test
{
public:
	void print() {}

	template<typename Type, typename... Types>
	void print(const Type &arg, const Types &... args)
	{
		std::cout << arg << std::endl;
		print(args...);
	}

};
#endif
