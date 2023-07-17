# trie trick
from functools import *
from collections import defaultdict
T = lambda: defaultdict(T)
trie = T()
words = ["ab",'cd','af']
for w in words:
    reduce(dict.__getitem__, w, trie)['#'] = True
