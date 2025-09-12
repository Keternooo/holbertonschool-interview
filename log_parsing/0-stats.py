#!/usr/bin/python3
"""
Module to parse log and count statusCode and file size.
"""

import signal
import sys

statusObj = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
}
fileSizeTotal = 0
counter = 0


def printA():
    """
    Print function for printing like desired
    """
    print("File size: {:d}".format(fileSizeTotal))
    for a in statusObj:
        if statusObj[a] != 0:
            print("{}: {}".format(a, statusObj[a]))


def signal_handler(sig, frame):
    """
    Function to catch SIGINT signal
    """
    printA()
    sys.exit(0)


def main():
    """
    Main function to parse input and print stats
    """
    global counter, fileSizeTotal

    signal.signal(signal.SIGINT, signal_handler)

    for line in sys.stdin:
        counter += 1
        try:
            firstSplit = line.split('" ')[1].split(" ")
            statusCode = firstSplit[0]
            fileSize = firstSplit[1]
        except (IndexError, ValueError):
            continue

        if statusCode in statusObj:
            statusObj[str(statusCode)] += 1
        fileSizeTotal += int(fileSize)

        if counter % 10 == 0:
            printA()

    printA()


if __name__ == "__main__":
    main()
