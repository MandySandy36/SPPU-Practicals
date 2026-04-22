# N-Queens Problem using Backtracking

def print_board(board, N):
    for i in range(N):
        for j in range(N):
            print("Q" if board[i][j] == 1 else ".", end=" ")
        print()
    print()


def is_safe(board, row, col, N):
    # Check column
    for i in range(row):
        if board[i][col] == 1:
            return False

    # Check upper left diagonal
    i, j = row, col
    while i >= 0 and j >= 0:
        if board[i][j] == 1:
            return False
        i -= 1
        j -= 1

    # Check upper right diagonal
    i, j = row, col
    while i >= 0 and j < N:
        if board[i][j] == 1:
            return False
        i -= 1
        j += 1

    return True


def solve_nqueens(board, row, N):
    if row == N:
        print_board(board, N)
        return True

    res = False
    for col in range(N):
        if is_safe(board, row, col, N):
            board[row][col] = 1
            res = solve_nqueens(board, row + 1, N) or res
            board[row][col] = 0  # Backtrack

    return res


# ---------------- DRIVER CODE ----------------
if __name__ == "__main__":
    N = int(input("Enter the value for N-queens problem : "))  # Change this to test with other N values (e.g., 8 for 8-Queens)
    board = [[0 for _ in range(N)] for _ in range(N)]

    if not solve_nqueens(board, 0, N):
        print("No solution exists")
