#!/usr/bin/env python
# coding=utf-8
#
# Filename: press_enter.py
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
import virtkey
import time
import webbrowser
v = virtkey.virtkey()  # 调用系统键盘
while 1 :
    v.press_keysym(65480)  # pess是按下键
