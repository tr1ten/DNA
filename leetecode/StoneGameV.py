# Fix this
# import bisect
# class Solution:
#     def stoneGameV(self, A: List[int]) -> int:
#         pref = [0]*(len(A)+1)
#         for i in range(1,len(A)+1): pref[i] = pref[i-1] + A[i-1];
#         def f(i,j):
#             if(i==j): return 0;
#             res = 0
#             sm = pref[j+1] - pref[i]
#             target = pref[i]+sm//2;
#             k = bisect.bisect_left(pref,target,i+1,j+1)
#             left = pref[k+1]-pref[i]
#             right = pref[j+1] - pref[k+1]
#             if(left==right):                                  
#                 res = max(res,f(i,k)+left,f(k+1,j)+right)
#             else:
#                 res = max(res,f(i,k)+left)    
#             return res
#         return f(0,len(A)-1)
                    
                
            
                
                
        