class Solution:
    def boxDelivering(self, boxes: List[List[int]], portsCount: int, mb: int, mw: int) -> int:
        n = len(boxes)
        dp = [0]*(n+1) # dp[i+1]: min cost to ship 0...i boxes
        # mentain window for single voyage
        cw = 0 # current wt of boxes in window
        start = 0 # starting of window
        cost  = 0 # cost of winwow
        for i in range(n):
            p,w = boxes[i]
            cw +=w
            while(start<i and (i-start+1>mb or cw>mw or dp[start]==dp[start+1] ) ): # wt or size or redudancy
                cw -= boxes[start][1]
                if(boxes[start][0]!=boxes[start+1][0]): cost-=1
                start +=1
            dp[i+1] = cost+2+dp[start]
            if(i+1<n): cost += (boxes[i][0]!=boxes[i+1][0])
        return dp[-1]
            