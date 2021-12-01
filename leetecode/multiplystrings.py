class Solution:
    """ Elementary maths starting multiplication from right most side  taking carry along the way """

    def multiply(self, num1: str, num2: str) -> str:
        if(num1=="0" or num2 == "0"):
            return "0"
        baseVal = ord("0")
        product = [0]*(len(num1)+len(num2))
        for i in range(len(num1)-1, -1, -1):
            for j in range(len(num2)-1, -1, -1):
                product[i+j+1] += (ord(num2[j])-baseVal)*(ord(num1[i])-baseVal)
                product[i+j] += product[i+j+1]//10
                product[i+j+1] = product[i+j+1] % 10

        return "".join([str(i) for i in product ]).lstrip("0")


print(Solution().multiply("123", "456"))
