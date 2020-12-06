/*
 * Filename: test.c
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
#include     <stdio.h>      /*标准输入输出定义*/
#include     <stdlib.h>     /*标准函数库定义*/
#include     <unistd.h>     /*Unix 标准函数定义*/
#include     <sys/types.h>
#include     <sys/stat.h>
#include     <fcntl.h>      /*文件控制定义*/
#include     <termios.h>    /*PPSIX 终端控制定义*/
#include     <errno.h>      /*错误号定义*/

int speed_arr[] = { B115200, B57600, B38400, B19200, B9600, B4800, B2400, B1200, B300};
int name_arr[] =  { 115200,  57600,  38400,  19200,  9600,  4800,  2400,  1200,  300};

/**
*@brief  Set Serial Port BitRate
*@param  fd     Type : int The File Description of Serial Port
*@param  speed  Type : int  Serial Speed
*@return  void
*/
void set_speed(int fd, int speed)
{
	int   i;
	int   status;
	struct termios   Opt;
	tcgetattr(fd, &Opt);
	for (i = 0; i < (sizeof(speed_arr) / sizeof(int)); i++) {
		if (speed == name_arr[i]) {
			tcflush(fd, TCIOFLUSH);
			cfsetispeed(&Opt, speed_arr[i]);
			cfsetospeed(&Opt, speed_arr[i]);
			status = tcsetattr(fd, TCSANOW, &Opt);
			if (status != 0) {
				perror("tcsetattr fd");
				return;
			}
			tcflush(fd, TCIOFLUSH);
		}
	}
}

/**
*@brief   Set Serial Port Databits, Stopbits and Parity.
*@param  fd     Type:  int The File Description of Serial Port
*@param  databits Type:  int Databits 7 or 8
*@param  stopbits Type:  int Stopbits 1 or 2
*@param  parity  Type:  int  Parity Type: n,N,e,E,o,O,s,S
*/
int set_Parity(int fd, int databits, int parity, int stopbits)
{
	struct termios options;
	if (tcgetattr(fd, &options)  !=  0) {
		perror("SetupSerial 1");
		return (-1);
	}
	options.c_cflag &= ~CSIZE;
	switch (databits) {             /*Set Datebits*/
	case 7:
		options.c_cflag |= CS7;
		break;
	case 8:
		options.c_cflag |= CS8;
		break;
	default:
		fprintf(stderr, "Unsupported data size\n");
		return (-1);
	}

	switch (parity) { /*Set Parity*/
	case 'n':
	case 'N':
		options.c_cflag &= ~PARENB;   /* Clear parity enable */
		options.c_iflag &= ~INPCK;     /* Enable parity checking */
		break;
	case 'o':
	case 'O':
		options.c_cflag |= (PARODD | PARENB); /* Odd Checking*/
		options.c_iflag |= INPCK;             /* Disnable parity checking */
		break;
	case 'e':
	case 'E':
		options.c_cflag |= PARENB;     /* Enable parity */
		options.c_cflag &= ~PARODD;   /* Even Checking*/
		options.c_iflag |= INPCK;       /* Disnable parity checking */
		break;
	case 'S':
	case 's':  /*as no parity*/
		options.c_cflag &= ~PARENB;
		options.c_cflag &= ~CSTOPB;
		break;
	default:
		fprintf(stderr, "Unsupported parity\n");
		return (-1);
	}

	switch (stopbits) {             /*Set Stobits*/
	case 1:
		options.c_cflag &= ~CSTOPB;
		break;
	case 2:
		options.c_cflag |= CSTOPB;
		break;
	default:
		fprintf(stderr, "Unsupported stop bits\n");
		return (-1);
	}
	/* Set input parity option */
	if (parity != 'n')
		options.c_iflag |= INPCK;

	/*以下两句添加后发送方可以不加回车换行，但是read读取不完整*/
	options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);     /*Input*/
	options.c_oflag &= ~OPOST;  /*Output*/

	//屏蔽功能： NL(换行)->CR(回车)、CR->NL、忽略输入回车
	options.c_iflag &= ~(INLCR | ICRNL | IGNCR);
	options.c_oflag &= ~(ONLCR | OCRNL);

	tcflush(fd, TCIFLUSH);
	//未设置O_NONBLOCK或O_NDELAY
	options.c_cc[VTIME] = 150; /* Timeout in 15 seconds*/
	options.c_cc[VMIN] = 0; /* Update the options and do it NOW */
	if (tcsetattr(fd, TCSANOW, &options) != 0) {
		perror("SetupSerial 3");
		return (-1);
	}
	return (0);
}

int main(void)
{
	char buf[512] = {0};
	int nread = 0;
	char *dev = "/dev/ttyS0";
	int fd = open(dev, O_RDWR | O_NOCTTY);
	if (fd > 0) {
		printf("Open %s Success!\n", dev);
	} else {
		printf("Can't Open %s\n", dev);
		exit(0);
	}

	set_speed(fd, 115200);
	if (set_Parity(fd, 8, 'N', 1) == -1) {
		close(fd);
		exit(-1);
	}

	while (1) {
		if ((nread = read(fd, buf, 512)) > 0) {
			printf("%s", buf);
		}
	}
	close(fd);
	exit(0);
}
