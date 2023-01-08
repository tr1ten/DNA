def maxPoints(points):
    n = len(points)
    def slope(i,j):
        if points[i][0] == points[j][0]: return INF
        return (points[i][1]-points[j][1])/(points[i][0]-points[j][0])
    res = 0
    for i in range(n):
        for j in range(i+1,n):
            temp = 2
            slop = slope(i,j)
            for k in range(n):
                if k==i or k==j: continue
                if slop == slope(i,k): temp += 1
            res = max(temp,res)
    return res