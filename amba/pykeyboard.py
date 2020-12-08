#!/usr/bin/env python
# coding=utf-8
#
# Filename: pykeyboard.py
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
from pykeyboard import *
from pymouse import *
m=PyMouse()
k=PyKeyboard()


#time.sleep(1) # give time to move (1157,470)
#print(m.position())
m.click(1157.470)

k.type_string('123456'
        )
k.tap_key(ke.enter_key)
