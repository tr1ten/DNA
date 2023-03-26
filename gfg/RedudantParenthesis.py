# User function Template for python3

class Solution:
    def removeBrackets(self, s):
        need = [True for i in range(len(s))]
        op = []  # open bracket index stack
        opr = [(0, -1)]  # for edge case
        mp = {'+': 0, '-': 1, '*': 2, '/': 2}
        changed = set([(2, 1), (2, 0), (1, 0), (1, 1)])
        for i, x in enumerate(s):
            if (x == '('):
                op.append(i)
            elif (x == ')'):
                li = op.pop()
                if (not opr or opr[-1][1] < li):
                    need[i] = need[li] = False
                else:
                    inp = 3
                    while(opr and opr[-1][1]>li):
                        inp = min(inp,opr.pop()[0])
                    out, nxt = opr[-1][0], (mp[s[i+1]] if (i+1 < len(s) and s[i+1] in mp) else 0)
                    need[i] = need[li] = (
                        (out, inp) in changed or (inp == nxt == 2))
            elif (x in mp):
                    opr.append((mp[x], i))

        return "".join([s[i] for i in range(len(s)) if (need[i])])


# A-B-((C+D*E+((F/G+H+I-((((((J/K+(L*M+N-(((O-P+(Q-((R+((S-(T+U*V-W-(((X+Y-Z)))))))))))))))))))))))
# (A-(B*C-D+E+(F*((G/H+(I/((J*(K-((L+((M/N-((O-((((P-(((Q+(((R+(S/(T-U-V-(W*(X*(Y/Z))))))))))))))))))))))))))))))
# A-(B*C-D+E+F*(G/H+I/J*(K-(L+M/N-(O-(P-(Q+R+S/(T-U-V-W*X*Y/Z))))))))
# A-(B*C-D+E+F*(G/H+I/(J*(K-(L+M/N-(O-(P-(Q+R+S/(T-U-V-W*X*Y/Z)))))))))
# {
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    t = 1
    for _ in range(t):
        Exp = input()

        ob = Solution()
        print(ob.removeBrackets(Exp))

# A-B-((C+D*E+((F/G+H+I-((((((J/K+(L*M+N-(((O-P+(Q-((R+((S-(T+U*V-W-(((X+Y-Z)))))))))))))))))))))))
