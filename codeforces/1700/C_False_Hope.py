from itertools import permutations

def solve(A):
    tot = 0
    safe = 0
    for x in permutations(range(10)):
        for y in x:
            i = y/3
            j = y%3
            