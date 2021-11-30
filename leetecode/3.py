class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l, r = 0, 0
        ans = 0
        sett = set()
        while r < len(s):
            if(s[r] in sett):
                sett.remove(s[l])
                l += 1
            else:
                sett.add(s[r])
                ans = max([ans, r-l+1])
                r += 1
        return ans
