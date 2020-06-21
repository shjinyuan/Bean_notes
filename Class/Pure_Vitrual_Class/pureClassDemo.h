/*
 * Filename: pureClassDemo.h
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/06/21 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-06-21
 * LastChange: 2020-06-21
 *    Version: v0.0.01
 *
 */

#ifndef _PURECLASSDEMO_H
#define _PURECLASSDEMO_H
class pureClassDemo{
public:
	virtual void DisplayMessage(std::string) = 0;

	std::string basename = "pureClassDemo";
};
#endif
