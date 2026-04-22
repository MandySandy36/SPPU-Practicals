# 0/1 Knapsack Problem using Dynamic Programming

def knapSack(W, wt, val, n):
    # Create a 2D DP table with (n+1) x (W+1)
    dp = [[0 for x in range(W + 1)] for y in range(n + 1)]

    # Build the table dp[][] in bottom-up manner
    for i in range(1, n + 1):
        for w in range(1, W + 1):
            if wt[i - 1] <= w:
                # Either include item i-1 or exclude it
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w])
            else:
                dp[i][w] = dp[i - 1][w]

    # The last cell will have the maximum value
    return dp[n][W], dp


# Function to find selected items
def find_selected_items(dp, wt, val, W, n):
    selected_items = []
    w = W
    for i in range(n, 0, -1):
        if dp[i][w] != dp[i - 1][w]:
            selected_items.append(i)  # item index (1-based)
            w -= wt[i - 1]
    return selected_items


# ---------------- DRIVER CODE ----------------
if __name__ == "__main__":
    values = [60, 100, 120]
    weights = [10, 20, 30]
    capacity = 50
    n = len(values)

    max_value, dp_table = knapSack(capacity, weights, values, n)
    selected = find_selected_items(dp_table, weights, values, capacity, n)

    print("Maximum value that can be put in Knapsack =", max_value)
    print("Selected item indices (1-based):", selected)
