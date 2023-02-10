class Solution:
    def totalStrength(self, strength: List[int]) -> int:
        n = len(strength)
        MOD = 10**9 + 7
        pref = [0]*(n+1)
        ppref = [0]*(n+2)
        for i in range(1,n+1): pref[i] = pref[i-1]+strength[i-1]
        for i in range(2,n+2): ppref[i] = ppref[i-1]+pref[i-1]
        st = []
        lefts = [-1]*n
        for i in range(n):
            while(st and strength[st[-1]]>=strength[i]): st.pop()
            if(st): lefts[i] = st[-1]
            st.append(i)
        rights = [n]*n
        st = []
        for i in reversed(range(n)):
            while(st and strength[st[-1]]>strength[i]): st.pop()
            if(st): rights[i]=(st[-1])
            st.append(i)
        res = 0
        for i in range(n):
            L = lefts[i]
            R = rights[i]
            res += ((ppref[R+1]-ppref[i+1])*(i-L) - (ppref[i+1]-ppref[L+1])*(R-i))*strength[i]
        return res%MOD