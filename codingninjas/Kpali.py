def isPalindrome(K: int, s: str) -> bool:
    # write your code here
    dp = [[False]*(len(s)+1) for i in range((len(s)+1))]
    for k in range(K+1):
        dp1 = [[False]*(len(s)+1) for i in range((len(s)+1))]
        for sz in range(1,len(s)+1):
            for l in range(len(s)-sz+1):
                r = l+sz-1
                if l==r: dp1[l][r] = True
                else: dp1[l][r] = (s[l]==s[r] and (dp1[l+1][r-1] if sz>2 else True)) or dp[l+1][r] or dp[l][r-1]
        dp = dp1
    return dp[0][len(s)-1]

print(isPalindrome(2,"abcca"))