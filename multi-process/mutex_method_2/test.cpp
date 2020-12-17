/*
 * Filename: test.cpp
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/12/15 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-12-15
 * LastChange: 2020-12-15
 *    Version: v0.0.01
 *
 */
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/mman.h>
#include <sys/wait.h>

struct mt {
	int num;
	pthread_mutex_t mutex;
	pthread_mutexattr_t mutexattr;
};

int main(void)
{
	int i;
	struct mt *mm;
	pid_t pid;

	mm = (mt *)mmap(NULL, sizeof(*mm), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0);
	memset(mm, 0, sizeof(*mm));

	pthread_mutexattr_init(&mm->mutexattr);                                  //初始化mutex属性对象
	pthread_mutexattr_setpshared(&mm->mutexattr, PTHREAD_PROCESS_SHARED);    //修改属性为进程间共享

	pthread_mutex_init(&mm->mutex, &mm->mutexattr);                          //初始化一把mutex琐

	pid = fork();
	if (pid == 0) {
		for (i = 0; i < 1000; i++) {
			usleep(1000);
			pthread_mutex_lock(&mm->mutex);
			(mm->num)++;
			pthread_mutex_unlock(&mm->mutex);
			printf("-child----------%d++   %d\n", mm->num - 1, mm->num);
		}
	} else if (pid > 0) {
		for (i = 0; i < 1000; i++) {
			usleep(1000);
			pthread_mutex_lock(&mm->mutex);
			mm->num += 2;
			pthread_mutex_unlock(&mm->mutex);
			printf("-------parent---%d+=2  %d\n", mm->num - 2, mm->num);
		}
		wait(NULL);
	}

	pthread_mutexattr_destroy(&mm->mutexattr);          //销毁mutex属性对象
	pthread_mutex_destroy(&mm->mutex);                  //销毁mutex
	munmap(mm, sizeof(*mm));                            //释放映射区

	return 0;
}
