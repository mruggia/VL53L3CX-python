#!/usr/bin/env python

# MIT License
#
# Copyright (c) 2024 Jakub Frgal
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

import time
import sys
import signal

import VL53L3CX

# Open and start the VL53L3CX sensor on the given I2C bus and address
tof = VL53L3CX.VL53L3CX(i2c_bus=1, i2c_address=0x29)
tof.open()
tof.start_ranging()

running = True

def exit_handler(signal, frame):
    global running
    running = False
    tof.stop_ranging()
    print()
    sys.exit(0)

# Signal handler to exit gracefully when Ctrl+C is pressed
signal.signal(signal.SIGINT, exit_handler)

# I have found that with VL53L3CX it's best practise to check if the sensor is ready before reading the distance
while running:
    if tof.is_ranging_ready():
        distance_in_mm = tof.get_distance()
        print("Distance: {}mm".format(distance_in_mm))
    time.sleep(0.1)
