import bisect
def solution(s,req):
    ans = []
    z,o =[],[]
    for i in range(len(s)):
        if s[i]=='0': z.append(i)
        else: o.append(i)
    for x in req:
        if x in 'flip': z,o = o,z 
        else:
            ind = int(x.split(":")[1])
            ans.append(bisect.bisect_right(z,ind))
    return ans
print(solution("1111010",["count:4","count:6","flip","count:4","flip","count:2"]))



