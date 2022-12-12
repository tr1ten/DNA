from collections import Counter
class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        st = []
        c = Counter(s)
        for x in s:
            if(x not in st):
                while(len(st)>0 and st[-1]>x and c[st[-1]]>0):
                    st.pop(-1)
                st.append(x)
            c[x] -=1
        return "".join(st)
