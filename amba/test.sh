#!/bin/bash
#
# Filename: test.sh
#
# Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
#
# History:
#    2020/12/03 - [yuan] Created file
#
# Maintainer: yuan <yuan@email.com>
#    Created: 2020-12-03
# LastChange: 2020-12-03
#    Version: v0.0.01
#


stty -F /dev/ttyUSB0 raw speed 115200 min 0 time 10
while [ 1 -eq 1 ]
do
	cat /dev/ttyUSB0 >> "tmpFile"
do something
done
