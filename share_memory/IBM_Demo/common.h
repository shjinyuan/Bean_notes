/*
 * Filename: common.h
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2021/04/14 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2021-04-14
 * LastChange: 2021-04-14
 *    Version: v0.0.01
 *
 */

#ifndef _COMMON_H
#define _COMMON_H
class A
{
public:
	int m_nA;
	virtual void WhoAmI();
	static void *m_sArena;
	void *operator new (unsigned int);

};
class B : public A
{
public:
	int m_nB;
	virtual void WhoAmI();

};
class C : virtual public A
{
public:
	int m_nC;
	virtual void WhoAmI();

};
void GetObjects(A **pA, B **pB, C **pC);
#endif
