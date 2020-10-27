/*
 * Filename: main.cpp
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/10/26 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-10-26
 * LastChange: 2020-10-26
 *    Version: v0.0.01
 *
 */
#include <iostream>
#include <unistd.h>
#include <libgen.h>
#include <unistd.h>

//char *test_path;
char test_path[64];

int main()
{
	//test_path =	get_current_dir_name();
	getcwd(test_path, sizeof(test_path));
	printf("getcwd:%s\n", test_path);
	std::string basename_ = basename(test_path);
	std::string dirname_ = dirname(test_path);
	printf("\t file : %s\n\t work dir: %s\n", basename_.c_str(), dirname_.c_str());

	return 0;
}
