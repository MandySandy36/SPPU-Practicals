import heapq

# Node class for Huffman Tree
class Node:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    # For priority queue (min-heap)
    def __lt__(self, other):
        return self.freq < other.freq


# Function to build Huffman Tree
def build_huffman_tree(char_freq):
    heap = [Node(char, freq) for char, freq in char_freq.items()]
    heapq.heapify(heap)

    while len(heap) > 1:
        left = heapq.heappop(heap)
        right = heapq.heappop(heap)

        merged = Node(None, left.freq + right.freq)
        merged.left = left
        merged.right = right

        heapq.heappush(heap, merged)

    return heap[0]


# Function to generate Huffman Codes
def generate_codes(root, current_code="", codes={}):
    if root is None:
        return

    if root.char is not None:
        codes[root.char] = current_code
        return

    generate_codes(root.left, current_code + "0", codes)
    generate_codes(root.right, current_code + "1", codes)

    return codes


# Huffman Encoding function
def huffman_encoding(text):
    # Step 1: Frequency dictionary
    freq = {}
    for char in text:
        freq[char] = freq.get(char, 0) + 1

    # Step 2: Build Huffman Tree
    root = build_huffman_tree(freq)

    # Step 3: Generate codes
    codes = generate_codes(root)

    # Step 4: Encode the text
    encoded_text = "".join(codes[char] for char in text)

    return encoded_text, codes, freq


# Function to calculate average code length
def average_code_length(codes, freq, total_chars):
    total_bits = sum(len(codes[ch]) * freq[ch] for ch in freq)
    return total_bits / total_chars, total_bits


# ------------------- DRIVER CODE -------------------
if __name__ == "__main__":
    text = "mississippi"

    encoded_text, codes, freq = huffman_encoding(text)

    print("Character Frequencies:", freq)
    print("Huffman Codes:", codes)
    print("Encoded Message:", encoded_text)

    avg_length, total_bits = average_code_length(codes, freq, len(text))
    print("\nAverage Code Length:", round(avg_length, 2))
    print("Total Encoded Message Length (bits):", total_bits)
    print("Original Size (bits):", len(text) * 8)
