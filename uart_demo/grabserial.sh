#/bin/bash
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
grabserial -v -S -d /dev/ttyUSB0 -e 30 -t -c "root"
grabserial -v -S -d /dev/ttyUSB0 -e 30 -t -c "reboot"
sleep 1
grabserial -v -S -d /dev/ttyUSB0 -e 30 -t -c "\n"
grabserial -v -S -d /dev/ttyUSB0 -e 30 -t -c "\n"
grabserial -v -S -d /dev/ttyUSB0 -e 30 -t -c "\n"
grabserial -v -S -d /dev/ttyUSB0 -e 30 -t -c "\n"
grabserial -v -S -d /dev/ttyUSB0 -e 30 -t -c "\n"
grabserial -v -S -d /dev/ttyUSB0 -e 30 -t -c "\n"
grabserial -v -S -d /dev/ttyUSB0 -e 30 -t -c "\n"
grabserial -v -S -d /dev/ttyUSB0 -e 30 -t -c "\n"
grabserial -v -S -d /dev/ttyUSB0 -e 30 -t -c "u"

