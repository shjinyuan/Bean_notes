/*
 * Filename: write_serial.c
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/12/06 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-12-06
 * LastChange: 2020-12-06
 *    Version: v0.0.01
 *
 */
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#define W_BUF   "WuYuJun<540726307@qq.com>"
int main(int argc, char **argv)
{
	int     tty_fd = -1 ;
	int     rv = -1 ;
	struct termios options;
	tty_fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY) ; //打开串口设备
	if (tty_fd < 0) {
		printf("open tty failed:%s\n", strerror(errno)) ;
		goto cleanup ;
	}
	printf("open devices sucessful!\n") ;
	memset(&options, 0, sizeof(options)) ;
	rv = tcgetattr(tty_fd, &options); //获取原有的串口属性的配置
	if (rv != 0) {
		printf("tcgetattr() failed:%s\n", strerror(errno)) ;
		goto cleanup ;
	}
	options.c_cflag |= (CLOCAL | CREAD); // CREAD 开启串行数据接收，CLOCAL并打开本地连接模式
	options.c_cflag &= ~CSIZE; // 先使用CSIZE做位屏蔽
	options.c_cflag |= CS8; //设置8位数据位
	options.c_cflag &= ~PARENB; //无校验位
	/* 设置115200波特率  */
	cfsetispeed(&options, B115200);
	cfsetospeed(&options, B115200);
	options.c_cflag &= ~CSTOPB;/* 设置一位停止位; */
	options.c_cc[VTIME] = 0;/* 非规范模式读取时的超时时间；*/
	options.c_cc[VMIN]  = 0; /* 非规范模式读取时的最小字符数*/
	tcflush(tty_fd, TCIFLUSH);/* tcflush清空终端未完成的输入/输出请求及数据；TCIFLUSH表示清空正收到的数据，且不读取出来 */
	if ((tcsetattr(tty_fd, TCSANOW, &options)) != 0) {
		printf("tcsetattr failed:%s\n", strerror(errno));
		goto cleanup ;
	}
	while (1) {
		rv = write(tty_fd, W_BUF, strlen(W_BUF)) ;
		if (rv < 0) {
			printf("Write() error:%s\n", strerror(errno)) ;
			goto cleanup ;
		}
		sleep(3) ;
	}
cleanup:
	close(tty_fd) ;
	return 0 ;
}
