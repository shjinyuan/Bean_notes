/*
 * Filename: main.cpp
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/11/27 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-11-27
 * LastChange: 2020-11-27
 *    Version: v0.0.01
 *
 */
#include <iostream>


enum ALPHABET {
	AAAA = 0x01,
	BBBB,
	CCCC,
	DDDD
};


//void set_via_alphabet(enum ALPHABET x)
void set_via_alphabet(uint32_t x)
{
	std::cout << x << std::endl;
}


int main(int argc, char *argv[])
{
	set_via_alphabet(CCCC);
	return 0;
}
