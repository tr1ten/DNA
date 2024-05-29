def min_moves(A: int, B: int, C: int) -> int:
    def move_and_count(x, y, z):
        count = 0
        while x != 0 and y != 0:
            move = min(x, y)
            x -= move
            y -= move
            z += 2 * move
            count += move
        return x, y, z, count

    total_count = 0

    # Process pairs (A, B), (B, C), and (A, C)
    A, B, C, count = move_and_count(A, B, C)
    total_count += count

    B, C, A, count = move_and_count(B, C, A)
    total_count += count

    A, C, B, count = move_and_count(A, C, B)
    total_count += count

    # Check if all are equal
    if A == B == C:
        return total_count
    return -1

# Input and Output Handling
A, B, C = map(int, input().split())
print(min_moves(A, B, C))
