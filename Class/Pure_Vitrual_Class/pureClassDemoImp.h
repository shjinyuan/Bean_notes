/*
 * Filename: pureClassDemoImp.h
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

#ifndef _PURECLASSDEMOIMP_H
#define _PURECLASSDEMOIMP_H

#include "pureClassDemo.h"

class pureClassDemoImp:pureClassDemo{
public:

	pureClassDemoImp(){
		basename = "pureClassDemoImp";
		printf("[constructor] %s\n",__FUNCTION__);
	}


	void DisplayMessage(std::string){
		printf("%s: in %s %d\n",__FUNCTION__,__FILE__,__LINE__);
	}

	void showName();
};

void pureClassDemoImp::showName(){
	printf("myName is HappyNewYear\n");
}

#endif
