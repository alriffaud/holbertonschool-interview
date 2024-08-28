#!/usr/bin/python3
""" This file defines the canUnlockAll function. """


def canUnlockAll(boxes):
    """
    This function defines a method that determines if all the boxes can be
    opened. Each box is numbered sequentially from 0 to n - 1 and each box
    may contain keys to the other boxes.A key with the same number as a box
    opens that box.
    All keys will be positive integers and there can be keys that do not have
    boxes. The first box boxes[0] is unlocked.
    boxes (list): is a list of lists.
    Return True if all boxes can be opened, else return False.
    """
    if not boxes:
        return False
    keys = [0]
    for key in keys:
        for new_key in boxes[key]:
            if new_key not in keys and new_key < len(boxes):
                keys.append(new_key)
    if len(keys) == len(boxes):
        return True
    return False
