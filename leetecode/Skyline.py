class Solution:
    def getSkyline(self, bd: List[List[int]]) -> List[List[int]]:
        st = [(bd[0][0],bd[0][2]),(bd[0][1],0)]
        for i in range(1,len(bd)):
            l,r,h = bd[i]
            pl,pr,ph = bd[i-1]
            mr = None
            if(l<=pr):
                mr = st.pop(-1)[0];
            if(ph<h): st.append((l,h))
            else:
                if(r<=pr): continue
                if(ph>h or (l>pr)): st.append((max(l,pr),h))
            if(not mr or mr<r): st.append((r,0))
            else: st.append((mr,0))
        return st