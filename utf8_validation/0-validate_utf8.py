#!/usr/bin/python3
"""Module that validates UTF-8 encoding"""


def validUTF8(data):
    """Determine if a given data set represents a valid UTF-8 encoding.

    Args:
        data (list): List of integers representing bytes

    Return:
        True if valid UTF-8, False otherwise
    """
    i = 0

    while i < len(data):
        octet = data[i] & 0xFF

        if octet >> 7 == 0:
            i += 1
        elif octet >> 5 == 0b110:
            if i + 1 >= len(data) or (data[i + 1] & 0xFF) >> 6 != 0b10:
                return False
            i += 2
        elif octet >> 4 == 0b1110:
            if (i + 2 >= len(data) or
                    (data[i + 1] & 0xFF) >> 6 != 0b10 or
                    (data[i + 2] & 0xFF) >> 6 != 0b10):
                return False
            i += 3
        elif octet >> 3 == 0b11110:
            if (i + 3 >= len(data) or
                    (data[i + 1] & 0xFF) >> 6 != 0b10 or
                    (data[i + 2] & 0xFF) >> 6 != 0b10 or
                    (data[i + 3] & 0xFF) >> 6 != 0b10):
                return False
            i += 4
        else:
            return False
    return True
