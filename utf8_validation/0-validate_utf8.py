#!/usr/bin/python3
""" This module contains a function for UTF-8 validation """


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding
    Args:
        data: list of integers
    Returns:
        True if data is a valid UTF-8 encoding, False otherwise.
    """
    num_bytes = 0

    for num in data:
        # Convert integer to binary and check the number of leading 1's
        if num < 0 or num > 255:
            return False  # Each number must be in the range of a byte
        if num >> 7 == 0:  # 0xxxxxxx
            num_bytes = 0
        elif num >> 5 == 0b110:  # 110xxxxx
            num_bytes = 1
        elif num >> 4 == 0b1110:  # 1110xxxx
            num_bytes = 2
        elif num >> 3 == 0b11110:  # 11110xxx
            num_bytes = 3
        else:
            return False  # Invalid start byte

        # Check continuation bytes
        for _ in range(num_bytes):
            if not data:
                return False  # Not enough bytes
            num = data.pop(0)
            if num >> 6 != 0b10:  # 10xxxxxx
                return False

    return num_bytes == 0  # Ensure no extra bytes remain unprocessed
