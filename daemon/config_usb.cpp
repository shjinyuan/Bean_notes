/*
 * Filename: config_usb.cpp
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
#include <iostream>
#include <unistd.h>

int main(int argc, char *argv[])
{
	daemon(0, 0);
	while (1) {
		system("ifconfig usb0 192.168.1.10");
		sleep(1);
	}
	return 0;
}
