from typing import List
def zfunc(s:str):
    l,r = 0,0
    z = [0]*len(s)
    for i in range(1,len(s)):
        if(i<=r): z[i] = min(r-i+1,z[i-l]) # jump start by using past knowledge
        while(i+z[i]<len(s) and s[z[i]]==s[i+z[i]]): 
            z[i] +=1 # try bigger length
        if(i+z[i]-1>r): # increase the range 
            l = i
            r = l+z[i]-1
    return z
def match(s,pat):
    temp = pat+"#"+s
    z = zfunc(temp) # longest substring at ith index that also a prefix except first
    for i in range(len(temp)):
        if(z[i]==len(pat)): 
            print(i-z[i]-1)
            break

match("abcd","bc")
        

