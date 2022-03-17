#!/usr/bin/python3
"""0-nqueens module"""
import sys


def board_print(board):
    """ prints board
    """
    new_l = []
    for i, row in enumerate(board):
        value = []
        for j, col in enumerate(row):
            if col == 1:
                value.append(i)
                value.append(j)
        new_l.append(value)

    print(new_l)


def is_safe(board, row, col, number):
    """ checks if there's a move
    """

    # Check this row in the left side
    for i in range(col):
        if board[row][i] == 1:
            return False

    # Check upper diagonal on left side
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    for i, j in zip(range(row, number, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    return True


def solve_until(board, col, number):
    """ Auxiliar method to find the posibilities of answer
    """

    if (col == number):
        board_print(board)
        return True
    res = False
    for i in range(number):

        if (is_safe(board, i, col, number)):

            # Place this queen in board[i][col]
            board[i][col] = 1

            # Make result true if any placement
            # is possible
            res = solve_until(board, col + 1, number) or res

            board[i][col] = 0  # BACKTRACK

    return res


def solve(number):
    """ Find all the posibilities if exists
    """
    board = [[0 for i in range(number)]for i in range(number)]

    if not solve_until(board, 0, number):
        return False

    return True


def validate(args):
    """ Verify if the size answer is posible
    """
    if (len(args) == 2):
        # Validate data
        try:
            number = int(args[1])
        except Exception:
            print("N must be a number")
            exit(1)
        if number < 4:
            print("N must be at least 4")
            exit(1)
        return number
    else:
        print("Usage: nqueens N")
        exit(1)


if __name__ == "__main__":
    """ Run app
    """

    number = validate(sys.argv)
    solve(number)
