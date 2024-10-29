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
    # Number of bytes expected in the current character
    num_bytes = 0

    for num in data:
        # Mask to keep only the last 8 bits (in case input integers are >255)
        num = num & 0xFF

        if num_bytes == 0:
            # Determine the number of bytes in the current UTF-8 character
            if num >> 7 == 0:  # 1-byte character (0xxxxxxx)
                continue
            elif num >> 5 == 0b110:  # 2-byte character (110xxxxx)
                num_bytes = 1
            elif num >> 4 == 0b1110:  # 3-byte character (1110xxxx)
                num_bytes = 2
            elif num >> 3 == 0b11110:  # 4-byte character (11110xxx)
                num_bytes = 3
            else:
                return False  # Invalid starting byte
        else:
            # Check if the current byte is a valid continuation byte (10xxxxxx)
            if num >> 6 != 0b10:
                return False
            num_bytes -= 1

    # If num_bytes is not zero, we have an incomplete UTF-8 character
    return num_bytes == 0
