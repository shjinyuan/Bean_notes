/*
 * Filename: main.cpp
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/10/27 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-10-27
 * LastChange: 2020-10-27
 *    Version: v0.0.01
 *
 */
#include <iostream>
#include <libgen.h>
#include <string.h>
int main(void)
{

	char *path = "/home/yuan/minicom.log";
	std::cout << path << std::endl;

	std::cout << "-------------1----------" << std::endl;
	char *dirc = strdup(path);
	char *basec = strdup(path);
	std::cout << "dirc=" << dirc << std::endl;
	std::cout << "basec=" << basec << std::endl;
	std::cout << "-------------2----------" << std::endl;
	char *d = dirname(dirc);
	std::cout << "dirname(dirc)=" << d << std::endl;
	std::cout << "dirc=" << dirc << std::endl;
	std::cout << "basec=" << basec << std::endl;

	std::cout << "-------------3----------" << std::endl;
	char *f = basename(basec);
	std::cout << "basename(basec)=" << f << std::endl;

	//std::cout << dir << std::endl;


	return 0;
}
