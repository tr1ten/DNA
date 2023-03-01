class Solution:
    def smallestSubsequence(self, s: str) -> str:
        cnt = Counter(s) # store count of remaining characters
        st = []
        for x in s:
            cnt[x] -=1 # decrease element count
            if(x in st):  continue # since it would already be in optimal place
            while(st and st[-1]>=x and cnt[st[-1]]>=1): # greedily remove larger element of possible
                st.pop()
            st.append(x) 
        return "".join(st)