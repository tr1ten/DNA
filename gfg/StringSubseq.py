from collections import defaultdict
class Solution:
    def countWays(self, S1, S2):
        dp = [0]*(len(S2)+1) # dp[i] will store number of subseq that can be formed starting at S2[i]
        dp[-1] = 1 # base case
        mp = defaultdict(list)
        for i,x in enumerate(S2): mp[x].append(i); # store each occurence of character with its index in S2
        for i in reversed(range(len(S1))):
            for j in mp[S1[i]]:
                dp[j] += dp[j+1] # updating all indices eg. gkhks then both k will be updated    
        return dp[0] # result 
        
  