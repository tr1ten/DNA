#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
struct ArrayHasher {
    std::size_t operator()(const std::array<int, 2>& a) const {
        std::size_t h = 0;

        for (auto e : a) {
            h ^= std::hash<int>{}(e)  + 0x9e3779b9 + (h << 6) + (h >> 2); 
        }
        return h;
    }   
};
int solve(int W,int wt[],int val[],int n,int cval,int index,unordered_map< array<int,2> , int, ArrayHasher >  hm)
{
    if(W<0)
    {
        return -1;
    }
    if(W==0 || index>=n)
    {
        return cval;
    }
    if(hm.count({W,index}))
    {
        return hm[{W,index}];
    }
    return hm[{W,index}] = max(solve(W-wt[index],wt,val,n,cval+val[index],index+1,hm),solve(W,wt,val,n,cval,index+1,hm));
    
}
int knapSack(int W, int wt[], int val[], int n) 
{
    unordered_map< array<int,2> , int, ArrayHasher >  hm;
    return solve(W,wt,val,n,0,0,hm); 
}
int knapSack2(int W, int wt[], int val[], int n) 
{
    int matrix[n+1][W+1]={{0}};
    fill(&matrix[0][0],&matrix[n][0],0);
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=W; j++)
        {

            if(wt[i-1]<=j)
            {
                // either not pick current wt and choose last best or pick current and pick last best for residual wt
                matrix[i][j] = max(matrix[i-1][j],val[i-1]+matrix[i-1][j-wt[i-1]]);
            }
            else{
                // since wt of item is greator than capacity, we choose last best 
                matrix[i][j] = matrix[i-1][j];
            }
        }
        
    }
    return matrix[n][W];
     
} 
int main()
{
    
    // int a[] = {57,95,13,29,1,99,34,77,61,23,24,70,73,88,33,61,43,5,41,63,8,67,20,72,98,59,46,58,64,94,97,70,46,81,42,7,1,52,20,54,81,3,73,78,81,11,41,45,18,94,24,82,9,19,59,48,2,72};
    // int b[] = {83,84,85,76,13,87,2,23,33,82,79,100,88,85,91,78,83,44,4,50,11,68,90,88,73,83,46,16,7,35,76,31,40,49,65,2,18,47,55,38,75,58,86,77,96,94,82,92,10,86,54,49,65,44,77,22,81,52};
    int wt[] = {1,3,4,6};
    int val[] = {20,30,10,50};
    cout << knapSack2(10,wt,val,4) << endl;
    return 0;
}
