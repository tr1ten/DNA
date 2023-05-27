import heapq
class Solution:
    def topKFrequent(self, A: List[int], k: int) -> List[int]:
        freq = Counter(A)
        A = list(set(A))
        def partition(l,r):
            i = l-1
            par = A[r]
            for k in range(l,r):
                if freq[A[k]]>=freq[par]:
                    i +=1
                    A[k],A[i] = A[i],A[k]
            i +=1
            A[r],A[i] = A[i],A[r]
            return i

        def qs(l,r):
            if r<=l: return A[l]
            p = partition(l,r)
            if p+1==k: return A[p] 
            if p+1>k: return  qs(l,p-1)
            else: return qs(p+1,r)
        res = qs(0,len(A)-1)
        # print(res)
        return [x for x in A if freq[x]>=freq[res]]
            

        
        