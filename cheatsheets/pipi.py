# Useful datasctructures in python 

# Counter in python 

# Counter is a container that stores elements as dictionary keys, and their counts are stored as dictionary values.
# most_common(n) -> list<list<int>>  | returns a list of the n most common elements and their counts from the most common to the least.
# elements() -> list<int> | returns an iterator over elements repeating each as many times as its count.
# subtract(iterable) -> None | subtracts count from each element in an iterable from the current counter.
from collections import Counter

arr = [1, 3, 4, 1, 2, 1, 1, 3, 4, 3, 5, 1, 2, 5, 3, 4, 5]
counter = Counter(arr)
counter.keys()
top_three = counter.most_common(3)
print(top_three) # [(1, 5), (3, 4), (4, 3)]
counter.get(10,0)
# Priority queue in python
# heappush(heap, ele): This function is used to insert the element mentioned in its arguments into heap.
# heappop(heap): This function is used to remove and return the smallest data element from a heap.
# heapify(list)
import heapq
grades = [110, 25, 38, 49, 20, 95, 33, 87, 80, 90]
heapq.heapify(grades)
heapq.heappush(grades,10)
print(heapq.nlargest(3, grades)) # [110, 95, 90]
print(heapq.nsmallest(4, grades)) # [20, 25, 33, 38]

# custom comparator - no option for custom comparator in python heapq, need to wrap the element in a tuple or class



# Hashset in python
a = 3
st = set()
st.add(a) # Add to st
st.remove(a) # Remove from st
st.discard(a) # Removes from set with no error
st.add(a) # Add to st
next(iter(st)) # return 3 without removal
st.pop() # returns 3
s = set('abc') # {'c', 'a', 'b'}
s |= set('cdf') # {'f', 'a', 'b', 'd', 'c'} union
s &= set('bd') # {'d', 'b'}
s -= set('b') # {'d'} elements in s but not in set('b'), difference
s ^= set('abd') # {'a', 'b'} elements from s or new but not both, (A^B)-(AvB) symmetric difference

import string
string.ascii_lowercase
# Queue & Stack in python
from collections import deque
q = deque()
q.si
q.append(1) # Add to q (Queue)
q.popleft() # Remove from q (Queue)
q[0] # Peek from q (Queue)
q.appendleft(3) # Add to q in front
q.pop() # Remove from q in back (Stack)
q[-1] # Peek from q in back (Stack)

# Hashmap in python

d = {'key': 'value'}         # Declare dict{'key': 'value'}
d['key'] = 'value'           # Add Key and Value
{x:0 for x in {'a', 'b'}}    # {'a': 0, 'b': 0} declare through comprehension
d['key']                     # Access value
d.get('notakey',0)           # Access value, returns 0 if notakey not in d
d.items()                    # Items as tuple list dict_items([('key', 'value')])
if 'key' in d: print("meh")  # Check if value exists
par = {}
par.setdefault(1,1)          # returns 1, makes par = { 1 : 1 }
par = {0:True, 1:False}
par.pop(0)                   # Remove key 0, Returns True, par now {1: False}
for k in d: print(k)         # Iterate through keys

from collections import defaultdict
d = defaultdict(int)         # Declare dict with default value of int 0
d['key']                     # Access value
d['key'] += 1                 # Add Key and Value

# TreeSet in python
from sortedcontainers import SortedSet
s = SortedSet([14,10, 5])
s.remove(10)
s.add(3)
s
s.bisect_left(10) # 2
list(s.irange(1, 14)) # [5, 14]

# Treemap in python
from sortedcontainers import SortedDict
d = SortedDict()
d[2] = 1
d[3] = 2
list(d.irange(3, 3)) # [(2, 1), (3, 2)]



# Useful Algorithms -----------------------------------------------------------

# any - returns true if any element of iterable is true
# all - returns true if all elements of iterable are true
# bisect - binary search
# bisect.bisect_left returns the leftmost place in the sorted list to insert the given element
# bisect.bisect_right returns the rightmost place in the sorted list to insert the given element
import bisect
ls = [1,2,2,5,6,10,10]
bisect.bisect_left(ls, 2)  # 1
bisect.bisect_left(ls, 7)  # 5
bisect.bisect_right(ls, 2,) # 3 

# pow(a,b,m) - returns a^b mod m
d = pow(2, 3, 5) # 3

# divmod - returns quotient and remainder
d = divmod(5, 2) # (2, 1)

# random in python

import random
ints = [0,1,2]
random.choice(ints) # 0,1,2
random.choices([1,2,3],[1,1,10]) # 3, heavily weighted
random.randint(0,2) # 0,1, 2
random.randint(0,0) # 0
random.randrange(0,0) # error
random.randrange(0,2) # 0,1


# Common operations -----------------------------------------------------------
s = "1"
s.isdigit()
s.isalnum()
s.isnumeric
# ternary operator
print("yes") if True else print("no") # yes

# Zipping iterables in python

letters = ['a', 'b', 'c']
numbers = [1]
print(list(zip(letters, numbers))) # [('a', 1)]

# Python code to sort a list of tuples by second Item
# using sorted() + lambda
ind = [0,1,2]
vals = [3,2,1]
sorted(ind, key = lambda x: vals[x])

# rotating a matrix by 90 degrees
matrix = [[1,2],[3,4]]
matrix[:] = zip(*matrix[::-1]) # [[3, 1], [4, 2]]


# Python code to apply a function on a list
# map(fn, list)-> map object applies fn to each element of list

def neighbors(r, c):
    for nr, nc in ((r,c-1), (r,c+1), (r-1, c), (r+1,c)):
        if 0<=nr<R and 0<=nc<C:
            yield nr, nc
    
# rank operation on sorted container
def next_smaller(sc, value):
    """Return strictly smaller value to the given value."""
    i = sc.bisect_left(value) - 1
    if i < 0:
        return None
    return sc[i]

def floor(sc, value):
    """Return smaller or equal value than the given value."""
    i = sc.bisect_right(value) - 1
    if i < 0:
        return None
    return sc[i]

def ceil(sc, value):
    """Return larger or equal value than the given value."""
    i = sc.bisect_left(value)
    if i >= len(sc):
        return None
    return sc[i]

def next_greater(sc, value):
    """Return strictly larger value than the given value."""
    i = sc.bisect_right(value)
    if i >= len(sc):
        return None
    return sc[i]


import math
def euclidean_distance(p1, p2):
    return math.sqrt(sum([(a - b) ** 2 for a, b in zip(p1, p2)]))

euclidean_distance([1,2], [4,5]) # 4.242640687119285

from itertools import accumulate
acc = accumulate([1,2,3,4,5]) # 1, 3, 6, 10, 15
print(list(acc)) # [1, 3, 6, 10, 15]

from functools import cmp_to_key

def cmp(a, b):
    return b-a

arr = [1,2,3,4,5]
arr.sort(key=cmp_to_key(cmp)) # [5, 4, 3, 2, 1]
arr

# reduce 
import functools
s = "AbC"
functools.reduce(lambda acc,x:acc+1 if(x.isupper()) else acc,s,0)


# reverse array from i to j
def reverse(arr, i, j):
    while i < j:
        arr[i], arr[j] = arr[j], arr[i]
        i += 1
        j -= 1
        
def is_subseq(x, y):
    it = iter(y)
    return all(c in it for c in x)