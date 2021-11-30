class Solution:
    def longestCommonPrefix(self, strs) -> str:
        fword = strs[0]
        if(len(fword) < 1):
            return ""
        cp = ""
        for index, char in enumerate(fword):
            for word in strs[1:]:
                if(word[:index+1] != fword[:index+1]):
                    return cp
            else:
                cp += char
        return cp
