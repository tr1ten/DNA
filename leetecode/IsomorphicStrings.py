class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        d = {}
        o = set()
        for  i in range(len(s)):
            if(s[i] in d):
                if(d[s[i]]!=t[i]):
                    return False
            else:
                if(t[i] in o):
                    return False
                d[s[i]] = t[i]
                o.add(t[i])
        return True