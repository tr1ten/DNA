class Solution:
    def knightDialer(self, n: int) -> int:
        if(n==1): return 10
        MOD = (10**9 + 7)
        mul = {i:None for i in range(1,10)}
        mul[0] = [4,6]
        mul[1] = [6,8]
        mul[2] = [7,9]
        mul[3] = [4,8]
        mul[4] = [0,3,9]
        mul[5] = []
        mul[6] = [0,1,7]
        mul[7] = [2,6]
        mul[8] = [1,3]
        mul[9] = [2,4]
        digits = {i:1 for i in range(0,10)}
        while(n>1):
            temp = {i:0 for i in range(0,10)}
            for i in range(0,10):
                for j in mul[i]:
                    temp[j] += digits[i]
                    temp[j] %= MOD
            digits = temp
            n-=1
        print(digits)
        return sum(digits.values())%MOD
        