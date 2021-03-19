/*
 * Filename: shmdata.h
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2021/03/18 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2021-03-18
 * LastChange: 2021-03-18
 *    Version: v0.0.01
 *
 */

#ifndef _SHMDATA_H
#define _SHMDATA_H
#define TEXT_SZ 2048
struct shared_use_st
{
    int written;//作为一个标志，非0：表示可读，0表示可写
    char text[TEXT_SZ];//记录写入和读取的文本
};

#endif
