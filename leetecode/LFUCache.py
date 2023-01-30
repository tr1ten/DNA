from collections import defaultdict,OrderedDict
class LFUCache:

    def __init__(self, capacity: int):
        self.cap = capacity
        self._freq_dict = defaultdict(OrderedDict) # ordered dict for each freq
        self.key_freq = defaultdict(int)
        self._min_freq = 1        

    def get(self, key: int) -> int:
        if(key not in self.key_freq): return -1;
        freq = self.key_freq[key] 
        val = self._freq_dict[freq][key] # save value associated with key
        del self._freq_dict[freq][key] # remove the node 
        if(len(self._freq_dict[freq])==0 and self._min_freq==freq):
            self._min_freq = freq+1; # update the min freq
        self._freq_dict[freq+1][key] = val; # put it at tail of freq+1 so to follow LRU
        self.key_freq[key] = freq+1;
        return val

    def put(self, key: int, value: int) -> None:
        if(not self.cap): return;
        if(key in self.key_freq):
            self.get(key); # update the freq by calling get
            self._freq_dict[self.key_freq[key]][key] = value;
            return;
        if(len(self.key_freq)==self.cap):
            remove_key = next(iter(self._freq_dict[self._min_freq])) # get the head of min freq since we need to follow LRU
            del self._freq_dict[self._min_freq][remove_key] # remove the head of min freq
            del self.key_freq[remove_key]
        self._min_freq = 1 # since newly added node will always have min freq ie. 1
        self._freq_dict[self._min_freq][key] = value 
        self.key_freq[key] = self._min_freq