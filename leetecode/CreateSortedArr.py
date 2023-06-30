class Solution:
    def createSortedArray(self, ins: List[int]) -> int:
        ind = list(range(len(ins)))
        gr = [0]*len(ins)
        ls = [0]*len(ins)
        def conq(l,m,r):
            p2 = m+1
            temp = []
            for k in range(l,m+1):
                while(p2<=r and ins[ind[k]]>=ins[ind[p2]]): 
                    temp.append(p2)
                    p2 +=1
                temp.append(k)
            while(p2<=r): 
                    temp.append(p2)
                    p2 +=1
            i = 0
            a=0 # on left
            b = m-l+1 # on right
            while(i<len(temp)): # update gr and ls vector for each right element
                j = i
                while(j<len(temp) and ins[ind[temp[j]]]==ins[ind[temp[i]]]):
                    j +=1
                t = 0
                for k in range(i,j):
                    if m>=temp[k]:
                        b -=1
                        t +=1
                for k in range(i,j):
                    if m<temp[k]: # duplicates considered
                        gr[ind[temp[k]]] += b # new at the right
                        ls[ind[temp[k]]] += a # new el at the left
                    temp[k] = ind[temp[k]]
                a +=t
                i = j
            ind[l:r+1] =temp
        def dev(i,j):
            if i>=j: return 
            mid = (i+j) >> 1
            dev(i,mid)
            dev(mid+1,j)
            conq(i,mid,j)    
        dev(0,len(ind)-1)
        # print(ind,ins,gr,ls)
        res = 0
        mod = 10**9 + 7
        for x,y in zip(gr,ls):
            res +=min(x,y)
            res %=mod
        return res