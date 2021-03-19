/*
 * Filename: put.c
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

typedef struct Product {
	int id;
	char pro_name[10];
} Pro;

int main()
{
	shmfifo_t *fifo = shmfifo_init(12345, 4, sizeof(Pro));
	Pro p;

	for (int i = 0; i < 20; ++i) {
		memset(&p, 0x00, sizeof(p));
		sprintf(p.pro_name, "iphone%d", i);
		p.id = i + 1;
		shmfifo_put(fifo, &p);
		printf("put %d ok\n", i);
	}
}
