class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        def generateHash(string):
            prod = 1
            sum = 0
            for i in string:
                prod *=ord(i)
                sum +=ord(i)
            return prod + sum
        cache = {}
        for ana in strs:
            sset = generateHash(ana)
            if(sset in cache):
                cache[sset].append(ana)
            else:
                cache[sset] = [ana]
        return list(cache.values())
    
print(Solution().groupAnagrams(["eat","tea","tan","ate","nat","bat"]))