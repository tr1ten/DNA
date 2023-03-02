from sortedcontainers import SortedList
class Solution():
    def updateQuery(self, N, Q, U):
        N_BITS = 5
        das = [SortedList([[-1,-1],[N,N]]) for i in range(N_BITS)]
        for l,r,v in U:
            for i in range(N_BITS):
                if((v&(1<<i))==0): continue
                ival = [l-1,r-1] # act as interval
                ind = das[i].bisect_right(ival)
                prev,nxt = das[i][ind-1],das[i][ind]
                if(prev[1]>=ival[1]): continue # contained inside other interval
                if(ival[1]>=nxt[0]):  # merge intervals prev & next if possible
                    ival[1] = max(ival[1],nxt[1])
                    das[i].remove(nxt)
                if(ival[0]<=prev[1]):
                    ival[0] = min(ival[0],prev[0])
                    das[i].remove(prev)
                das[i].add(ival) # finnaly append
                
        arr = [0]*N
        for i in range(N_BITS):
            for l,r in das[i][1:-1]: 
                for j in range(l,r+1):
                    arr[j] |= 1<<i
        return arr