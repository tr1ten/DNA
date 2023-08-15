from os import *
from sys import *
from collections import *
from math import *
import heapq
def pathWithMaxMinValue(arr):
	# Write your code here.
	pq = [(-arr[0][0],0,0)]
	seen = set()
	seen.add((0,0)) # no need to mentain distance vector since we ensure each cell visited with max value till then
	while pq:
		d,y,x = heapq.heappop(pq)
		if(y==len(arr)-1 and x==len(arr[0])-1): return -d
		for dx,dy in [(1,0),(0,1),(-1,0),(0,-1)]:
			i,j = y+dy,x+dx;
			if i<len(arr) and j<len(arr[0]) and j>=0 and i>=0 and (i,j) not in seen:
				heapq.heappush(pq,((-min(-d,arr[i][j]),i,j)))
				seen.add((i,j))
	return -1
