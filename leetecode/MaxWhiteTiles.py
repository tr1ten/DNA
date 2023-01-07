# sliding window
class Solution:
    def maximumWhiteTiles(self, tiles: List[List[int]], cl: int) -> int:
        tiles.sort()
        i,j = 0,0;
        n = len(tiles)
        s,res=0,0 # white tiles count 
        while(i<n and j<n):
            if(tiles[i][0]+cl>tiles[j][1]): # if greator then the end of current jth range
                s += tiles[j][1]-tiles[j][0]+1 # then add whole range tiles
                res = max(res,s)
                j+=1
            else:
                temp = s + max(0,tiles[i][0]+cl-tiles[j][0]) # partial or no tiles overlap with carpet, add those tiles
                s -= (tiles[i][1]-tiles[i][0]+1) # remove white tiles
                i+=1 # shrink the window 
                res = max(res,temp) # update the ans
        return res
            
        

# from itertools import accumulate
# class Solution:
#     def maximumWhiteTiles(self, tiles: List[List[int]], cl: int) -> int:
#         tiles.sort()
#         pref = [0]+list(accumulate([r-l+1 for l,r in tiles]))
#         i = 0
#         res = 0
#         for j in range(len(tiles)):
#             r = pref[j]-pref[i]+min(max(0,(tiles[i][0]+cl)-tiles[j][0]), tiles[j][1]-tiles[j][0]+1)
#             if(cl==r): return r
#             while(i<j and tiles[i][0]+cl<=tiles[j][1]): i+=1
#             res = max(res,r,pref[j+1]-pref[i])
#             # print(i,j,res,r)
#         return res
            

        