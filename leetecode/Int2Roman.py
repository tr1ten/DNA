class Solution:
    def intToRoman(self, num: int) -> str:
        rules = [['M'], ['C', 'CD', 'D', 'CM'], [
            'X', 'XL', 'L', 'XC'], ['I', 'IV', 'V', 'IX']]
        snum = (4-len(str(num)))*'0' + str(num)
        roman = ""
        for i in range(4):
            n = int(snum[i])
            if(n == 0):
                continue
            if(n < 4):
                roman += rules[i][0]*n
            elif(n == 4):
                roman += rules[i][1]
            elif(n >= 5 and n < 9):
                roman += rules[i][2] + (n-5)*rules[i][0]
            else:
                roman += rules[i][3]
        return roman
