/*
 * Filename: main.c
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/11/30 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-11-30
 * LastChange: 2020-11-30
 *    Version: v0.0.01
 *
 */
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define true 1
#define false -1
void childProcessFunc()
{
	int i = 0;
	while (true) {
		++i;
		printf("i: %d, pid: %d, ppid: %d\n", i, getpid(), getppid());
		if (i == 3) {
			// 子进程主动结束
			char *p = NULL;
			char ch[32] = "mytest jin";
			p = 1; //kill thread
			/*p = &ch; // kill thread*/
		}
		sleep(1);
	}
}

void forkChildProcess()
{
	int status = 0;
	// 等待子进程中断或终止，释放子进程资源
	// 否则死掉的子进程会变成僵尸进程
	int pid = wait(&status);
	if (pid < 0) {
		printf("error: %s\n", strerror(errno));
		return;
	}

	// 如果子进程是由于某种信号退出的，捕获该信号
	if (WIFSIGNALED(status)) {
		int signalNum = WTERMSIG(status);
		printf("Child process was killed by signal num: %d\n", signalNum);
	}

	// 检测是否生成了core文件
	if (WCOREDUMP(status)) {
		printf("Child process core dump file generated\n");
	}

	// 等待3秒钟重新启动子进程
	sleep(3);

	pid = fork();
	if (pid == 0) {
		printf("Fork new child process\n");
		// 运行子进程代码
		(void)init();
	}
}

int initWatchDog()
{
	int pid = fork();
	if (pid) {
		// 父进程一直监视子进程的运行状态
		while (true) {
			// 捕获子进程结束信号
			assert(signal(SIGCHLD, forkChildProcess) != SIG_ERR);
			// 父进程挂起，当有信号来时被唤醒
			pause();
		}
	} else if (pid < 0) {
		return false;
	}

	return true;
}


int init()
{
	printf("pthread begain\n");
	int ret = 0;
	ret = childinit();
	if (true != ret) {
		printf("init: childinit Fail!\n");
		return false;
	}

	return true;

}

int childinit()
{
	int iRet = 0;
	pthread_t Thread_ID;

	iRet = pthread_create(&Thread_ID, NULL, childProcessFunc, NULL);
	if (iRet != 0) {
		printf("childinit: childProcessFunc failed!\n");
		return false;
	}

	return true;
}

int main()
{
	int ret = 0;
	printf("Main pid: %d\n", getpid());

	// 初始化看门狗进程
	ret = initWatchDog();
	if (!ret) {
		printf("Init watch dog failed\n");
		return -1;
	}

	printf("Init watch dog success...\n");

	// 运行子进程代码
	(void)init();

	return 0;
}
