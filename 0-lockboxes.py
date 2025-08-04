#!/usr/bin/python3

def canUnlockAll(boxes):
    indexUnlocked = {0: 'unlocked'}

    for i in range(len(boxes)):
        if i in indexUnlocked:
            for key in boxes[i]:
                if key < len(boxes) and key not in indexUnlocked:
                    indexUnlocked[key] = 'unlocked'
    for i in range(len(boxes)):
        if i in indexUnlocked:
            for key in boxes[i]:
                if key < len(boxes) and key not in indexUnlocked:
                    indexUnlocked[key] = 'unlocked'

    return len(indexUnlocked) == len(boxes)

