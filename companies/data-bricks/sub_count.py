def solution(numbers,pattern):
    s = ""
    c = ['c','b','a']
    for i in range(1,len(numbers)):
        if numbers[i]>numbers[i-1]: s+="a"
        elif numbers[i]==numbers[i-1]: s+='b'
        else: s+='c'
    pattern= "".join(map(lambda x: c[x+1],pattern))
    res = 0
    for i in range(len(s)-len(pattern)+1):
        if s[i:i+len(pattern)]==pattern: res+=1
    return res
    
print(solution([4,1,3,4,4,5,5,1],[1,0,-1]))
print(solution([5,7,7,9,9,11,11],[1,0,1,0]))
    
