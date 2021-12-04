class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if(n==1):
            return True
        def sumOfSq(n):
            sum = 0 
            for digit in str(n):
                sum += int(digit)**2 
            return sum
        slow = sumOfSq(n)
        fast = sumOfSq(slow)
        if(slow==1 or fast==1):
            return True
        while slow!=fast:
            slow = sumOfSq(slow)
            fast = sumOfSq(sumOfSq(fast))
            if(slow==1 or fast==1):
                return True
        return False
                          

print(Solution().isHappy(10))