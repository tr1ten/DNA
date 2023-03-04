class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        @cache
        def solve(i,j):
            if(i==j): return 0
            res = float('inf')
            for k in range(i,j):
                l,r = max(arr[i:k+1]),max(arr[k+1:j+1]) # can use preprocessing here 
                res = min(res,solve(i,k)+solve(k+1,j)+l*r)
            return res
        return solve(0,len(arr)-1)


# greedy approach
class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        res = 0
        while(len(arr)>1):
            ind = arr.index(min(arr))
            if(ind+1<len(arr) and (ind==0 or arr[ind-1]>=arr[ind+1] )):
                res  += arr[ind+1]*arr[ind]
            else:
                res += arr[ind-1]*arr[ind]
            arr.pop(ind)
        return res
    
# greedy w/ mono stack
class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        res = 0
        st = [float('inf')]
        for x in arr:
            while(st[-1]<=x): # smaller then bigger
                sm = st.pop() # multiply smallest with smaller neighbour
                res += sm*(min(x,st[-1])) 
            st.append(x)
        while(len(st)>2): # join remaining
            res += st.pop()*st[-1]
        return res