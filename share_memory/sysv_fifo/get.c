/*
 * Filename: get.c
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2021/03/19 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2021-03-19
 * LastChange: 2021-03-19
 *    Version: v0.0.01
 *
 */
#include "shmfifo.h"
#include <unistd.h>

typedef struct Products {
	int id;
	char pro_name[10];
} Pro;

int main()
{
	shmfifo_t *fifo = shmfifo_init(12345, 3, sizeof(Pro));
	Pro p;

	while (1) {
		memset(&p, 0x00, sizeof(p));
		shmfifo_get(fifo, &p);
		printf("id:%d, 产品名：%s\n", p.id, p.pro_name);
		sleep(1);
	}
	shmfifo_destroy(fifo);
}
