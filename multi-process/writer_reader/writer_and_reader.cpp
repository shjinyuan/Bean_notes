/*
 * Filename: writer_and_reader.cpp
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/12/22 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-12-22
 * LastChange: 2020-12-22
 *    Version: v0.0.2
 *
 */
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
#include<signal.h>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<iostream>
struct Syn_info {
	Syn_info()
	{
		sem_init(&mutex_r, 0, 1);
		sem_init(&mutex_f, 0, 1);
		sem_init(&mutex_rw, 0, 1);
		count = 0;
	}
	sem_t mutex_f; //写优先锁
	sem_t mutex_r; //count变量互斥访问
	sem_t mutex_rw; //读写锁
	int count;
};

/**********************************读者写者问题******************************/
void *writer(void *arg)
{
	Syn_info *info = (Syn_info *)arg;
	while (1) {
		sem_wait(&info->mutex_f);
		sem_wait(&info->mutex_rw);
		std::cout << "write" << std::endl;
		sem_post(&info->mutex_rw);
		sem_post(&info->mutex_f);
	}
}
void *reader(void *arg)
{
	Syn_info *info = (Syn_info *)arg;
	while (1) {
		sem_wait(&info->mutex_f);
		sem_wait(&info->mutex_r);
		std::cout << "one reader access" << std::endl;
		if (info->count == 0) { //第一个读进程负责"加锁"
			sem_wait(&info->mutex_rw);
			std::cout << "prevent writer to write" << std::endl;
		}
		info->count++;
		sem_post(&info->mutex_r);
		sem_post(&info->mutex_f);

		std::cout << "reading" << std::endl;
		sleep(3);

		sem_wait(&info->mutex_r);
		info->count--;
		std::cout << "one reader leave" << std::endl;
		if (info->count == 0) { //最后一个读进程负责"解锁"
			sem_post(&info->mutex_rw);
			std::cout << "ok ,now writer can write" << std::endl;
		}
		sem_post(&info->mutex_r);
	}
}
int main(int argc, char **argv)
{
	pthread_t *tid = new pthread_t[10]();
	Syn_info *info = new Syn_info();
	for (int index = 0; index != 10; index++) {
		if (index < 5) {
			pthread_create(tid + index, NULL, writer, (void *)info);
		} else {
			pthread_create(tid + index, NULL, reader, (void *)info);
		}
	}
	pause();
}
