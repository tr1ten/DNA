class Solution:
    def romanToInt(self, s: str) -> int:
        db = {'I': 1, 'V': 5, 'X': 10,
              'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        valid = {'I': ['V', 'X'], 'X': ['L', 'C'], 'C': ['D', 'M']}
        value = 0
        last_index = len(s)-1
        index = 0
        while index < len(s):
            if s[index] in valid.keys() and index < last_index and s[index+1] != 'I' and s[index+1] in valid[s[index]]:
                value += db[s[index+1]]-db[s[index]]
                index += 2
            else:
                value += db[s[index]]
                index += 1

        return value
