def ps(s):
        arr = [0]*len(s)
        i,j = 1,0
        while(i<len(s)):
            if(s[i]==s[j]):
                arr[i] = j+1
                j +=1
                i+=1
            elif(j==0):
                arr[i] = 0
                i+=1
            else:
                j = arr[j-1] # can't just use j-1 since we don't know if smaller <j-1 are equal 
        return arr
class Solution(object):
    def strStr(self, haystack, needle):
        s  =  needle+"#"+haystack
        print(s,ps(s))
        for i,x in enumerate(ps(s)):
            if(x==len(needle)): return i-2*len(needle)
        return -1
    
print(Solution().strStr("aaaa","aaaa"))