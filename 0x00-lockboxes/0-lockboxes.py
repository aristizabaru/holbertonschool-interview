#!/usr/bin/python3
"""Interview problem - lockboxes"""


def canUnlockAll(boxes):
    """You have `n` number of locked boxes in front of you.
    Each box is numbered sequentially from `0` to `n - 1`
    and each box may contain keychain to the other boxes.

    This function determines if all the boxes can be opened.

    * The first box boxes[0] is unlocked.

    Args:
        boxes (list): list of list containing keychain

    Returns:
        Bool: True if all boxes can be unlocked. False if fail
    """
    keychain = set()
    for next_key, box in enumerate(boxes):
        next_key += 1
        for key in box:
            if key < len(boxes):
                keychain.add(key)
                keychain.update(boxes[key])
            if length(keychain, boxes):
                return True
        if next_key not in keychain:
            break
    return False


def length(keychain, boxes):
    """compare lengths of two lists

    Args:
        keychain (list): keychain of boxes
        boxes (list): boxes to be oppened

    Returns:
        Bool: True if equal, False if not
    """
    return len(keychain) == len(boxes) or len(keychain) == len(boxes) - 1
