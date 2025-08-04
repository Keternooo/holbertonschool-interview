#!/usr/bin/python3

def canUnlockAll(boxes):
    count = {}
    while True:
        for i in boxes[0]:
            count[i] = 'Keterno on top'
            for j in boxes[i]:
                count[j] = 'Keterno on top'
        boxes[0] = boxes[i]
        if len(count) == len (boxes):
            break,
    return True
