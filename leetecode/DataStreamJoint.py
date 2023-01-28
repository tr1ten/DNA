
from typing import List
import bisect
class SummaryRanges:

    def __init__(self):
        self.intervals = [] # store the interval ranges sorted by start
        self.mp = set() # store the number encountered so far


    def addNum(self, value: int) -> None:
        if(value in self.mp): return;
        self.mp.add(value)
        if(value+1 in self.mp and value-1 not in self.mp): # this can become start postion
            ind = bisect.bisect_left(self.intervals,value+1,key=lambda x:x[0])
            self.intervals[ind][0] = value;
        if(value-1 in self.mp and value+1 not in self.mp): # this can become end postion
            ind = bisect.bisect_left(self.intervals,value-1,key=lambda x:x[1])
            self.intervals[ind][1] = value;
        if(value-1 in self.mp and value+1 in self.mp): # need to merge two ranges 
            ind = bisect.bisect_left(self.intervals,value+1,key=lambda x:x[0])
            self.intervals[ind-1][1] = self.intervals[ind][1]
            self.intervals.pop(ind)
        if(value-1 not in self.mp and value+1 not in self.mp): # this need its own range
            bisect.insort_left(self.intervals,[value,value],key=lambda x:x[0])
        
    def getIntervals(self) -> List[List[int]]:
        return self.intervals;
        


# Your SummaryRanges object will be instantiated and called as such:
# obj = SummaryRanges()
# obj.addNum(value)
# param_2 = obj.getIntervals()