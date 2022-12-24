import heapq
class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        last,ll = None,None
        q = [(-a,'a'),(-b,'b'),(-c,'c')]
        heapq.heapify(q)
        ans = ""
        while(q[0][0]<0):
            cnt,char = heapq.heappop(q)
            if(last==char and ll==char):
                if(q[0][0]>=0): break
                t1,t2 = heapq.heappop()
                heapq.heappush((cnt,char))
                cnt,char = t1,t2
            ans += char
            heapq.heappush(q,(cnt-1,char))
            ll = last
            last = char
        return ans
             