class Solution:
    def isSolvable(self, words: List[str], result: str) -> bool:
        words.append(result)
        phobs = [x[0] for x in words if len(x)>1]
        for i in range(len(words)):
            if len(words[i])>len(result): return False
            words[i] = words[i][::-1]
        # main idea is to do column wise to prune early
        def rec(assigned,i,j,carry,cur,nums):
            if j==len(result): 
                return cur==0
            if i==len(words)-1:
                if(cur==0 and words[i][j] in phobs): return False
                if words[i][j] in assigned:
                    if assigned[words[i][j]]==cur: return rec(assigned,0,j+1,0,carry,nums)
                    return False
                if cur not in nums: return False
                nums.remove(cur)
                assigned[words[i][j]] = cur
                if rec(assigned,0,j+1,0,carry,nums): return True
                assigned.pop(words[i][j])
                nums.add(cur)
                return False
            if j>=len(words[i]): return rec(assigned,i+1,j,carry,cur,nums)
            if words[i][j] in assigned: 
                sm = cur+assigned[words[i][j]]
                return rec(assigned,i+1,j,carry+sm//10,sm%10,nums)
            for x in set(nums):
                if(x==0 and words[i][j] in phobs ): continue
                nums.remove(x)
                assigned[words[i][j]] = x
                sm = cur+x
                if rec(assigned,i+1,j,carry + sm//10,sm%10,nums): return True
                assigned.pop(words[i][j])
                nums.add(x)
            return False
        df = dict()
        res = rec(df,0,0,0,0,{0,1,2,3,4,5,6,7,8,9})
        # print(df)
        return res