#!/usr/bin/python3
"""Module to determine if all locked boxes can be unlocked."""


def canUnlockAll(boxes):
    """Determine if all boxes can be unlocked.

    Each box may contain keys to other boxes. Box 0 is unlocked by default.

    Args:
        boxes (list of list): boxes[i] contains the keys found in box i.

    Returns:
        bool: True if all boxes can be opened, False otherwise.
    """
    elements = [0]
    keys = set()

    while elements:
        element = elements.pop()
        if element in keys:
            continue
        if element not in range(len(boxes)):
            continue
        elements.extend(boxes[element])
        keys.add(element)
    return len(keys) == len(boxes)
