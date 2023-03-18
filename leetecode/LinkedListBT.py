class Solution:
    def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
        l = 0
        temp = head;
        arr = []
        while(temp):
            arr.append(temp)
            temp = temp.next;
        l = 0
        i = 1
        dp = [0]*len(arr)
        while(i<len(arr)):
            if(arr[i].val==arr[l].val):
                dp[i] = l+1
                l +=1
                i +=1
            elif(l==0): 
                dp[i] = 0
                i +=1
            else: l = dp[l-1] 
        
        def f(node,t):
            if(t==len(arr)): return True
            if(not node): return False
            while(t>0):
                if(arr[t].val!=node.val): t = dp[t-1]
            if(arr[t].val == node.val): t +=1
            return f(node.left,t) or f(node.right,t)
        return f(root,0)