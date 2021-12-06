class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        parenMap = {
            "{":"}",
            "(":")",
            "[":"]",
        }
        reverseMap = {
            "}":"{",
            ")":"(",
            "]":"[",
        }
        stack = []
        for char in s:
            if(char in reverseMap):
                if(len(stack)==0):
                    return False
                element = stack.pop()
                if(reverseMap[char]!=element):
                    return False
            else:
                stack.append(char)
        return True if len(stack)==0 else False
                    
        
print(Solution().isValid("}{()"))