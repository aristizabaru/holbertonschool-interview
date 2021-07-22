#!/usr/bin/python3
"""Interview problem - lockboxes"""


def canUnlockAll(boxes):
    """You have `n` number of locked boxes in front of you.
    Each box is numbered sequentially from `0` to `n - 1`
    and each box may contain keys to the other boxes.

    This function determines if all the boxes can be opened.

    * The first box boxes[0] is unlocked.

    Args:
        boxes (list): list of list containing keys

    Returns:
        Bool: True if all boxes can be unlocked. False if fail
    """
    keys = set(boxes[0])

    for next_key, box in enumerate(boxes):
        next_key += 1
        for key in box:
            keys.update(boxes[key])
        if next_key not in keys and next_key < len(boxes):
            return False
    return True
