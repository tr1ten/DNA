def solution(wins,draws,scores,conceded):
    ind = sorted(range(len(wins)),
                 key=lambda x:(3*wins[x]+draws[x],scores[x]-conceded[x]))
    return ind[-2:][::-1]

print(solution([2,1,0],[1,5,6],[20,15,10],[20,10,15]))
print(solution([1,1,2,2],[1,5,4,4],[10,10,20,40],[32,13,18,37]))
