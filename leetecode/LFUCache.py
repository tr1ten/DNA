import heapq
class LFUCache:

    def __init__(self, capacity: int):
        self.t = 0
        self.h = []
        self.map = dict()
        self.time = dict()
        self.count = dict()
        self.cap = capacity
        

    def get(self, key: int) -> int:
        if(key not in self.map): return -1
        self.t +=1
        self.time[key] = self.t
        self.count[key] +=1
        return self.map[key]


    def put(self, key: int, value: int) -> None:
        self.t +=1
        self.time[key] = self.t
        self.count[key] = 1
        if(key in self.map):
            self.map[key] = value
            return;
        if(len(self.map.keys())==self.cap):
            if(not self.h):
                for k in self.map:
                    self.h.append((self.count[k],self.time[k],k));
                heapq.heapify(self.h)
            _,_,k = heapq.heappop(self.h)
            del self.map[k]
            del self.time[k]
            del self.count[k]
            heapq.heappush(self.h,(self.count[key],self.time[key],key));
        self.map[key] = value