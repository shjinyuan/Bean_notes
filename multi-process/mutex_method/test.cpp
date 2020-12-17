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
#include <sys/wait.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>


int main()
{
	pthread_mutexattr_t attr;
	pthread_mutex_t mutex;

	pthread_mutexattr_init(&attr);
	pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);
	pthread_mutex_init(&mutex, &attr);

	pid_t pid = fork();
	if (pid > 0) {
			pthread_mutex_lock(&mutex);
			printf("in parent process\n");
			sleep(2);
			pthread_mutex_unlock(&mutex);
			wait(NULL);
	} else if (pid == 0) {
			sleep(1);
			pthread_mutex_lock(&mutex);
			printf("in child process\n");
			pthread_mutex_unlock(&mutex);
			_exit(0);
	}

	pthread_mutexattr_destroy(&attr);
	pthread_mutex_destroy(&mutex);

	return 0;
}
