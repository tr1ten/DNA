from collections import defaultdict, OrderedDict, Counter

def solve(N, Q, operations):
    class LFUCache:
        def __init__(self, capacity):
            self.freq = defaultdict(OrderedDict)
            self.ktf = Counter()
            self.sm = dict()
            self.minf = 1
            self.cap = capacity

        def inc(self, key):
            f = self.ktf[key]
            if f == self.minf and len(self.freq[f]) == 1:
                self.minf += 1  # increase freq
            self.ktf[key] += 1
            if f:
                del self.freq[f][key]
            self.freq[f + 1][key] = None

        def dec(self):
            f = self.minf
            ff = next(iter(self.freq[f]))
            del self.sm[ff]
            del self.freq[f][ff]
            del self.ktf[ff]

        def get(self, key):
            if key not in self.sm:
                return -1
            self.inc(key)
            return self.sm[key]

        def put(self, key, value):
            if key not in self.sm and len(self.sm) == self.cap:
                self.dec()
            if key not in self.sm:
                self.minf = 1
            self.inc(key)
            self.sm[key] = value

    lfu_cache = LFUCache(N)
    results = []

    for op in operations:
        if op[0] == 1:
            results.append(lfu_cache.get(op[1]))
        elif op[0] == 2:
            lfu_cache.put(op[1], op[2])

    return results

# Example usage:
N = int(input())
Q = int(input())
operations = [list(map(int, input().split())) for i in range(Q)]
out = solve(N, Q, operations)
print(' '.join(map(str, out)))