import heapq
class Solution:
    def getOrder(self, nums: List[List[int]]) -> List[int]:
        tasks = [(nums[i][0],nums[i][1],i) for i in range(len(nums))]
        tasks.sort()
        heap = []
        time = tasks[0][0]
        res = []
        # print(tasks)
        i =0
        while(i<len(tasks)):
            while(i<len(tasks) and tasks[i][0]<=time):
                heapq.heappush(heap,(tasks[i][1],tasks[i][2],tasks[i][0]))
                i+=1
            if(len(heap)>0): # if cpu has tasks available to perform
                p = heapq.heappop(heap)
                time +=p[0]
                res.append(p[1])
            elif(i<len(tasks)):  # no tasks ?? update timer
                time = max(time,tasks[i][0])
        # print("last heap",heap)
        while(len(heap)>0):
            res.append(heapq.heappop(heap)[1])
        return res
            