/*
 * Filename: customer_demo.cpp
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/12/22 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-12-22
 * LastChange: 2020-12-22
 *    Version: v0.0.3
 *
 */

#include<unistd.h>
#include<semaphore.h>
#include<signal.h>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<thread>
struct Syn_info {
	Syn_info()
	{
		sem_init(&mutex_full, 0, 0);
		sem_init(&mutex_empty, 0, 10);
		sem_init(&mutex, 0, 1);
		count = 0;
	}
	sem_t mutex_full;
	sem_t mutex_empty;
	sem_t mutex;
	int count;
};

/****************************多个生产者消费者问题*****************************/
void *producen(void *arg)/*生产者*/
{
	Syn_info *info = (Syn_info *)arg;
	while (1) {
		sem_wait(&info->mutex_empty);
		sem_wait(&info->mutex);
		if (info->count < 10) {
			std::cout << "producer put product in work line" << std::endl;
			info->count++;
			std::cout << "produe product -> " << "product id: " << info->count << std::endl;
			sem_post(&info->mutex);
			sem_post(&info->mutex_full);
		} else {
			std::cout << "no free space for producer to put product" << std::endl;
			sem_post(&info->mutex);
		}
	}
}
void *consumen(void *arg)/*消费者*/
{
	Syn_info *info = (Syn_info *)arg;
	while (1) {
		sem_wait(&info->mutex_full);
		sem_wait(&info->mutex);
		if (info->count > 0) {
			std::cout << "consume-> " << "product id : " << info->count << std::endl;
			info->count--;
			std::cout << "consumer get product from work line" << std::endl;
			sem_post(&info->mutex);
			sem_post(&info->mutex_empty);
		} else {
			std::cout << "no product on work line" << std::endl;
			sem_post(&info->mutex);
		}
	}
}


/***************************一个生产者消费者问题******************************/
void *produce(void *arg)/*生产者*/
{
	Syn_info *info = (Syn_info *)arg;
	while (1) {
		sem_wait(&info->mutex_empty);
		sem_wait(&info->mutex);
		std::cout << "[producer] put product in work line" << std::endl;
		sem_post(&info->mutex);
		sem_post(&info->mutex_full);
		sleep(1);
	}
}

void *consume(void *arg)/*消费者*/
{
	Syn_info *info = (Syn_info *)arg;
	while (1) {
		sem_wait(&info->mutex_full);
		sem_wait(&info->mutex);
		std::cout << "[consumer] get product from work line" << std::endl;
		sem_post(&info->mutex);
		sem_post(&info->mutex_empty);
		sleep(1);
	}
}

int main(int argc, char **argv)
{
	Syn_info *info = new Syn_info();
#ifdef SINGLE_DEMO
	std::thread(produce, (void *)info).detach();
	std::thread(consume, (void *)info).detach();
#else
	for (int index = 0; index != 10; index++) {
		if (index < 5) {
			std::thread(producen, (void *)info).detach();
		} else {
			std::thread(consumen, (void *)info).detach();
		}
	}
#endif
	pause();
}
