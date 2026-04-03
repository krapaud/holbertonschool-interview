#!/usr/env/python 3
def canUnlockAll(boxes):
    elements = [0]
    keys = set()

    while elements:
        element = elements.pop()
        print(element)
        if element in keys:
            continue;
        if element not in range(len(boxes)):
            continue;
        elements.extend(boxes[element])
        keys.add(element)
    return len(keys) == len(boxes)
