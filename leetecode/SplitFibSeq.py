class Solution:
    def splitIntoFibonacci(self, num: str) -> List[int]:
        gres = []
        prev=0
        for i in range(len(num)-1):
            prev = prev*10 + int(num[i])
            cur = 0
            for j in range(i+1,len(num)-1):
                cur = cur*10 + int(num[j])
                res = [prev,cur]
                nxt = None
                for k in range(j+1,len(num)):
                    nxt = (nxt if nxt is not None else 0)*10 + int(num[k])
                    if(nxt>=2**31): break
                    if(nxt==res[-1]+res[-2]):
                        res.append(nxt)
                        nxt = None
                if(len(res)>2 and len(gres)<len(res) and nxt is None): gres = res
                if(num[i+1]=='0' or j-i>10): break
            if(num[0]=='0' or i>10): break
        return gres
