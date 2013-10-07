#!/usr/bin/python
import argparse
import serial
import time
import sys

def load_file(dev, filename):
    with open(filename, "rb") as f:
	bytes = f.read(2048)

    print "Read %d bytes" % len(bytes)

    ser = serial.Serial(
        port=dev, 
        baudrate=9600, 
        timeout=1,
        parity=serial.PARITY_NONE,
        stopbits=serial.STOPBITS_ONE,
        bytesize=serial.EIGHTBITS)

    print "Wait for connection..."

    while True:
	x = ser.read()
	if len(x) != 0:
	    break

    if x[0] != '<':
	print "Got unknown sumbol %s" % x
	sys.exit(1)

    ser.write(bytes)
    for i in xrange(2048-len(bytes)):
	ser.write(chr(0x000))

    print "Download complete"

    while True:
	x = ser.read()
	if len(x) > 0:
	    sys.stdout.write(x)
	else:
	    sys.stdout.flush()





if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('-b', '--binary', required=True)
    parser.add_argument('-d', '--device', default="/dev/ttyUSB0")
    args = parser.parse_args()

    load_file(args.device, args.binary)
