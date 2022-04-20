#include <iostream>
#include <vector>
#include <string>
using namespace std;
// best example of bottom up approach

// naive way freakin slow
// void rec(string a,string b, int p1,int p2, int op,int& curMin)
// {
//     int an = a.size();
//     int bn = b.size();
//     // base cases
//     if(op>=curMin)
//     {
//         return;
//     }
//     if(an<=p1 && bn<=p2)
//     {
//         curMin = op;
//         return;
//     }
//     if(an<=p1 && bn>p2)
//     {
//         return rec(a,b,an,bn,op + (bn-p2),curMin);
//     }
//     if(an>p1 && bn<=p2)
//     {
//         return rec(a,b,an,bn,(op + (an-p1)),curMin);
//     }
//     // different cases
//     if(a.at(p1)==b.at(p2))
//     {
//         return rec(a,b,p1+1,p2+1,op,curMin);
//     }
//     rec(a,b,p1,p2+1,op+1,curMin);
//     rec(a,b,p1+1,p2,op+1,curMin);
//     rec(a,b,p1+1,p2+1,op+1,curMin);


// }

// pro way
int update(vector<vector<int>> &matrix,int x,int y,bool isSame)
{
    if(isSame)
    {
        return (matrix[y+1][x+1]);
    }
    return min(min(matrix[y][x+1],matrix[y+1][x+1]),matrix[y+1][x]) + 1;
}
int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    vector<vector<int>> vec(m+1, vector<int> (n+1, -1));
    for (int i = 0; i < n; i++)
    {
        vec[m][i] = n-i;
    }
    for (int i = 0; i <=m; i++)
    {
        vec[i][n] = m-i;
    }
    for (int i = m-1; i >=0; i--)
    {
        for (int j = n-1; j >=0; j--)
        {
            vec[i][j] = update(vec,j,i,word1[i]==word2[j]);
        }
        
    }
    return vec[0][0];
    
}
int main()
{
    cout << minDistance("inothateyou","ihateyou") << endl;
        return 0;
}
