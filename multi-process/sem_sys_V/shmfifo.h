/*
 * Filename: shmfifo.h
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

#ifndef __SHMFIFO_H__
#define __SHMFIFO_H__

#include <sys/ipc.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

typedef struct shmhead {
    int rd_idx; // 读入数据索引
    int wr_idx; // 写数据索引
    int blocks; // 存数据块数量
    int blksz;  // 每个数据块大小
}shmhead_t;

typedef struct shmfifo {
    shmhead_t *p_head;    // 共享内存的起始地址
    char *     p_payload; // 有效数据的起始地址
    int shmid;            // 打开的共享内存id
    int sem_mutex;        // 互斥量
    int sem_empty;        // 还剩多少个可以消费<br>     int sem_full; // 剩余多少个地方可以生产
    int sem_full;        // 还剩多少个可以消费<br>     int sem_full; // 剩余多少个地方可以生产
}shmfifo_t;

// 初始化函数
shmfifo_t *shmfifo_init(key_t key, int blocks, int blksz);
// 放入数据
void shmfifo_put(shmfifo_t *fifo, const void *buf);
// 取得数据
void shmfifo_get(shmfifo_t *fifo, void *buf);
// 结构销毁
void shmfifo_destroy(shmfifo_t *fifo);

#endif //__SHMFIFO_H__
