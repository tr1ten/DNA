class Solution:
    # @param A : integer
    # @param B : list of integers
    # @param C : integer
    # @return a list of list of integers
    def solve(self, n, B, C):
        seen = [0]*n
        ans = []
        cnt = 0
        for i in range(n):
            if seen[i]: continue
            cur = i
            path = []
            while not seen[cur]:
                seen[cur] = 1
                path.append(cur)
                cur = B[cur] - 1
                cnt +=1
            cnt -=1
            for x,y in zip(path,path[1:]):
                ans.append([x+1,y+1])
            print(path)
        # print(ans)
        if cnt>C: return ans[:cnt-C]
        return [[-1,-1]]
                
s = Solution()
# print(s.solve(11,[7,2,11,6,9,1,10,4,8,3,5],9))
# print(s.solve(3,[2,3,1],1))
# print(s.solve(2,[2,1],0))
print(s.solve(14,[4,7,14,10,2,3,13,9,8,6,5,11,12,1],8))
