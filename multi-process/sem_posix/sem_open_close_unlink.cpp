/*
 * Filename: maim.cpp
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/12/17 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-12-17
 * LastChange: 2020-12-17
 *    Version: v0.0.01
 *
 */
#include <fcntl.h>	    /* For O_* constants */
#include <sys/stat.h>	    /* For mode constants */
#include <semaphore.h>
#include <stdio.h>
int main(void)
{
	sem_t *sem;
	sem=sem_open("jinyuan_test_sem_posix", O_CREAT| O_EXCL,S_IRUSR|S_IWUSR,1);
	if (sem == SEM_FAILED){
		printf("SEM_FAILED!\n");
	}

	sem_close(sem);
	sem_unlink("jinyuan_test_sem_posix");
	return 0;
}
