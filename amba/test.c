/*
 * Filename: test.c
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
#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <string.h>

#include <errno.h>

#include <sys/types.h>

#include <sys/stat.h>

#include <fcntl.h>

#include <termios.h>

#define BAUDRATE B115200 ///Baud rate : 115200

#define DEVICE "/dev/ttyUSB0"//设置你的端口号

int nFd = 0;

struct termios stNew;

struct termios stOld;



//Open Port & Set Port

int SerialInit()

{

	nFd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);

	if (-1 == nFd)

	{

		perror("Open Serial Port Error!\n");

		return -1;

	}

	if ((fcntl(nFd, F_SETFL, 0)) < 0)

	{

		perror("Fcntl F_SETFL Error!\n");

		return -1;

	}

	if (tcgetattr(nFd, &stOld) != 0)

	{

		perror("tcgetattr error!\n");

		return -1;

	}



	stNew = stOld;

	cfmakeraw(&stNew);//将终端设置为原始模式，该模式下全部的输入数据以字节为单位被处理



	//set speed

	cfsetispeed(&stNew, BAUDRATE);//115200

	cfsetospeed(&stNew, BAUDRATE);



	//set databits

	stNew.c_cflag |= (CLOCAL | CREAD);

	stNew.c_cflag &= ~CSIZE;

	stNew.c_cflag |= CS8;



	//set parity

	stNew.c_cflag &= ~PARENB;

	stNew.c_iflag &= ~INPCK;



	//set stopbits

	stNew.c_cflag &= ~CSTOPB;

	stNew.c_cc[VTIME] = 0;  //指定所要读取字符的最小数量

	stNew.c_cc[VMIN] = 1; //指定读取第一个字符的等待时间，时间的单位为n*100ms

	//假设设置VTIME=0，则无字符输入时read（）操作无限期的堵塞

	tcflush(nFd, TCIFLUSH); //清空终端未完毕的输入/输出请求及数据。

	if (tcsetattr(nFd, TCSANOW, &stNew) != 0)

	{

		perror("tcsetattr Error!\n");

		return -1;

	}



	return nFd;

}



int main(int argc, char **argv)

{
	int i;

	int nRet = 0;

	char *sendmsg = "welC";

	int SIZE = sizeof(sendmsg);

	char buf[SIZE];

	if (SerialInit() == -1)

	{

		perror("SerialInit Error!\n");

		return -1;

	}

	bzero(buf, SIZE);

	while (1)

	{
		sleep(1);

		write(nFd, sendmsg, sizeof(sendmsg)); //向串口发送数据

		printf("%s\n", sendmsg);


#if 0
		// 串口接收部分

		nRet = read(nFd, buf, SIZE);

		if (-1 == nRet)

		{

			perror("Read Data Error!\n");

			break;

		}

		if (0 < nRet)

		{

			buf[nRet] = 0;

			printf("Recv Data: %s\n", buf);

		}

#endif

	}

	close(nFd);

	return 0;

}
