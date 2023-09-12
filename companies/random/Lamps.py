import bisect
def solution(lamps,points):
    si = set()
    for x,y in lamps: 
        si.add(x)
        si.add(y)
    for x in points: si.add(x)
    si = sorted(si)
    diff = [0]*(len(si) +1)
    for x,y in lamps:
        diff[bisect.bisect(si,x)] +=1
        diff[bisect.bisect(si,y)+1] -=1
    for i in range(1,len(diff)): diff[i] +=diff[i-1]
    ans = []
    for x in points:
        ans.append(diff[bisect.bisect(si,x)])
    return ans

print(solution([[1,7],[5,11],[7,9]],[7,1,5,10,9,15]))