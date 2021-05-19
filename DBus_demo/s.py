#!/usr/bin/env python
# coding=utf-8
#
# Filename: s.py
#
# Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
#
# History:
#    2021/05/17 - [yuan] Created file
#
# Maintainer: yuan <yuan@email.com>
#    Created: 2021-05-17
# LastChange: 2021-05-17
#    Version: v0.0.01
#
#!/usr/bin/env python

import dbus
import dbus.decorators
import dbus.glib
import gobject

bus = dbus.SystemBus()

def catchall_hello_signals_handler(hello_string):
    print hello_string

bus.add_signal_receiver(catchall_hello_signals_handler, dbus_interface = "test.method.caller", signal_name = "Test")

loop = gobject.MainLoop()
loop.run()
