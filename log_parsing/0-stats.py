#!/usr/bin/python3

"""
Module to parse log and count statusCode and file size
"""
import signal
import sys

oldInput = None
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

def signal_handler(sig, frame):
     """
     Function for catch SIGINT signal
     """
     print("File size: {:d}".format(fileSizeTotal))
     for a in statusObj:
          if statusObj[a] != 0:
               print("{}: {}".format(a, statusObj[a]))  
     sys.exit(0)

signal.signal(signal.SIGINT, signal_handler)
signal.pause()

while True:
     if oldInput == input():
          continue
     counter+=1
     oldInput = input()
     
     firstSplit = oldInput.split('" ')[1].split(" ")
     statusCode = firstSplit[0]
     fileSize = firstSplit[1]
     statusObj[str(statusCode)] += 1
     fileSizeTotal += int(fileSize)

     if counter % 10 == 0:
          print("File size: {:d}".format(fileSizeTotal))
          for a in statusObj:
               if statusObj[a] != 0:
                    print("{}: {}".format(a, statusObj[a]))     





