//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


struct State {
    int i;
    int j;
    int u;
    int d;
};
class Solution{
 
	public:
	int numberOfCells(int n, int m, int r, int c, int u, int d, vector<vector<char>> &mat)
	{
        queue<State> q;
        if(mat[r][c]=='.') q.push({r,c,0,0});
        int ans = 0;
        vector<vector<bool>> vis(n,vector<bool>(m));
        vis[r][c] = 1;
        while(q.size()){
            auto s = q.front();
            int i=s.i,j=s.j;
            q.pop();
            // cout << i << " " << j << endl;
            ans++;
            if(j-1>=0 && (mat[i][j-1]=='.') && !vis[i][j-1]) {
                q.push({i,j-1,s.u,s.d});
                vis[i][j-1] = 1;
            }
            if(j+1<m && (mat[i][j+1]=='.') && !vis[i][j+1]) {
                q.push({i,j+1,s.u,s.d});
                vis[i][j+1] = 1;

                
            }
            if(i-1>=0 &&( mat[i-1][j]=='.' )&& !vis[i-1][j] && s.u<u) {
                q.push({i-1,j,s.u+1,s.d});
                 vis[i-1][j] = 1;

            }
            if(i+1<n && (mat[i+1][j]=='.') && !vis[i+1][j] && s.d<d) {
                q.push({i+1,j,s.u,s.d+1});
                vis[i+1][j] = 1;

            }
        }
        return ans;
	}

};

//{ Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;

    while (t--)
    {
    	int n, m, r, c, u, d;
        cin >> n >> m >> r >> c >> u >> d;
        
        vector<vector<char>> mat(n, vector<char>(m, '.'));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < m; j++)
        	{
        		cin >> mat[i][j];
        	}
        }

      

        Solution obj;
        cout << obj.numberOfCells(n, m, r, c, u, d, mat) << "\n";
    
    }

    return 0;
}



// } Driver Code Ends