class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        modal = ["Gold Medal", "Silver Medal", "Bronze Medal"]
        sscore= sorted(range(0,len(score)), key=lambda k: -score[k])
        size = len(score)
        result = [""]*size
        for i in range(size):
            if(i<3):
                result[sscore[i]] = modal[i]
            else:
                result[sscore[i]] = str(i+1)
        return result