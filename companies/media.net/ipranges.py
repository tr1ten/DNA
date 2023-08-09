# Given a list of ‘n’ IP ranges (ipv4), create an efficient data structure to serve queries if a given IP belongs to the set or not quicker. 
# for e.g. :
# given these ip ranges
# [[10.10.1.100, 10.10.2.50], [10.10.2.200, 10.10.4.100], [10.20.200.20, 10.40.10.100]]
# To search : 
# find(10.20.100.40) ->No
# find(10.10.3.100) -> Yes
# find(10.10.1.256) -> Yes

# ranges can be upto 1e5 and queries can also be upto 1e5, "you need to implement searching in constant time"
import bisect
class IPTable:
    def cvt(self,x):
            cur = 0
            for y in x.split('.'):
                cur = (cur<<8) | (int(y)-1) # 0-255
            return cur
    def add(self,x):
        s,e = self.cvt(x[0]),self.cvt(x[1])
        self.intervals.append((s,e))
    def __init__(self,ips):
        self.intervals = []
        for x in ips: self.add(x)
        self.intervals = self._merge(self.intervals)
    def _merge(self,intervals):
        res = []
        i = 0
        intervals.sort()
        while i<len(intervals):
            s,e = intervals[i]
            while i<len(intervals) and intervals[i][0]<=e:
                e = max(intervals[i][1],e)
                i +=1
            res.append((s,e))
        return res
    def query(self,ip):
        x = self.cvt(ip)
        idx = bisect.bisect_right(self.intervals,(x,x))-1
        if idx<0: return False
        if self.intervals[idx][0]<=x<=self.intervals[idx][1]: return True
        return False
table = [["10.10.1.100", "10.10.2.50"],["10.10.2.200","10.10.4.100"], ["10.20.200.20"," 10.40.10.100"]]
ip = IPTable(table)
queries = ['10.20.100.40','10.10.3.100','10.10.1.256']
for x in queries:
    print(ip.query(x))