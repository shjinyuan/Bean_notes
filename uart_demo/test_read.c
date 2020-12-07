/*
 * Filename: test_read.c
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/12/03 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-12-03
 * LastChange: 2020-12-03
 *    Version: v0.0.01
 *
 */
#include<unistd.h>
#include<stdlib.h>
int main(void)
{
	char buf[10];
	int n;
	/*n = read("/dev/ttyUSB0", buf, 10);*/
	n = read(STDIN_FILENO, buf, 10);
	if (n < 0) {
		perror("read STDIN_FILENO");
		exit(1);
	}
	write(STDOUT_FILENO, buf, n);
	return 0;
}
