class Solution:
    def minSideJumps(self, obs: List[int]) -> int:
        lanes = [float('inf'),1,0,1]
        for i in range(1,len(obs)):
            nlanes = lanes[:] # save the prev state 
            lanes[obs[i]] = float('inf')
            nlanes[1] = min(lanes[2]+1,lanes[3]+1,lanes[1])
            nlanes[2] = min(lanes[1]+1,lanes[3]+1,lanes[2])
            nlanes[3] = min(lanes[1]+1,lanes[2]+1,lanes[3])
            nlanes[obs[i]] = float('inf')
            lanes = nlanes
        return min(lanes)
