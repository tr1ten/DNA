class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        poss = []
        hashmap = {
            "2":"abc",
            "3":"def",
            "4":"ghi",
            "5":"jkl",
            "6":"mno",
            "7":"pqrs",
            "8":"tuv",
            "9":"wxyz",
        }
        def recur(hashmap=hashmap,pointer=0,gs="",digits=digits):
            if(len(gs)==len(digits)):
                poss.append(gs)
                return;
            for letter in hashmap[digits[pointer]]:
                recur(hashmap,pointer+1,gs+letter,digits)
        recur()
        return poss
            
            
                
    
print(Solution().letterCombinations("2"),len(Solution().letterCombinations("2")))
        