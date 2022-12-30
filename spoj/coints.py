import sys
from functools import lru_cache

def read_str():
    return sys.stdin.readline().strip()
def read_int():
    return int(read_str())
def read_ints():
    return list(map(int, read_str().split()))
def write_line(s):
    sys.stdout.write(s)
    sys.stdout.write("\n")
def write_lines(lines):
    sys.stdout.writelines("\n".join(lines))
    sys.stdout.write("\n")

# input
# solve here
@lru_cache(maxsize=None)
def solve(x):
    if(x<5): return x
    return max(x,solve(x//2)+solve(x//3)+solve(x//4));
# input processing
while(True):
    try:
        write_line(str(solve(read_int())))
    except:
        break