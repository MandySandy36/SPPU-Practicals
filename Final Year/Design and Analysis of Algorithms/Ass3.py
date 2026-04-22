# Fractional Knapsack Problem using Greedy Method

class Item:
    def __init__(self, weight, value):
        self.weight = weight
        self.value = value
        self.ratio = value / weight  # value/weight ratio


def fractional_knapsack(weights, values, capacity):
    items = [Item(weights[i], values[i]) for i in range(len(weights))]

    # Step 1: Sort items by decreasing value/weight ratio
    items.sort(key=lambda x: x.ratio, reverse=True)

    total_value = 0.0
    knapsack_contents = []

    # Step 2: Add items to knapsack
    for item in items:
        if capacity >= item.weight:
            # Take the whole item
            capacity -= item.weight
            total_value += item.value
            knapsack_contents.append((item.weight, item.value, 1.0))  # 100% taken
        else:
            # Take fraction of item
            fraction = capacity / item.weight
            total_value += item.value * fraction
            knapsack_contents.append((item.weight, item.value, fraction))
            break  # Knapsack is full

    return total_value, knapsack_contents


# ---------------- DRIVER CODE ----------------
if __name__ == "__main__":
    # Example: items with weights and values
    weights = [10, 20, 30, 22, 15]   # weights of items
    values = [60, 100, 120, 77, 50]  # values of items
    capacity = 60                    # knapsack capacity

    max_value, contents = fractional_knapsack(weights, values, capacity)

    print("Items considered (weight, value, fraction taken):")
    for w, v, f in contents:
        print(f"Weight={w}, Value={v}, Fraction Taken={round(f, 2)}")

    print("\nMaximum value in Knapsack =", round(max_value, 2))
