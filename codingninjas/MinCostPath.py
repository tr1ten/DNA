def minCostPath(cost, n, m, y, x):
    x -=1
    y -=1
    for i in reversed(range(y)): 
        cost[i][x]+=cost[i+1][x];
    for i in reversed(range(x)): 
        cost[y][i]+=cost[y][i+1];
    for i in reversed(range(y)):
        for j in reversed(range(x)):
            cost[i][j] = cost[i][j]+min(cost[i+1][j],cost[i+1][j+1],cost[i][j+1])
    print(cost)
    return cost[0][0]
    

# 3 4
# 3 4 1 2
# 2 1 8 9
# 4 7 8 1
# 2 3

print(minCostPath([[3,4,1,2],[2,1,8,9],[4,7,8,1],[2,3]],4,4,2,3))