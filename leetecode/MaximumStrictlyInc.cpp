#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        map<int,vector<int>> rows[n];
        map<int,vector<int>> cols[m];
        for(int i=0;i<n;i++){
            for( int j=0;j<m;j++){
                rows[i][mat[i][j]].push_back(j);
                cols[j][mat[i][j]].push_back(i);
            }
        }
        vector<vector<int>> mem(n,vector<int>(m,-1));
        function<int(int,int)> rec = [&](int i,int j){
            if(mem[i][j]!=-1) return mem[i][j];
            int res = 0;
            auto nc = rows[i].upper_bound(mat[i][j]);
            if(nc!=rows[i].end()){
                for(auto nx:(*nc).second){
                    res = max(res,rec(i,nx));
                }
            }
            auto nr = cols[j].upper_bound(mat[i][j]);
            if(nr!=cols[j].end()){
                for(auto nx:(*nr).second){
                    res = max(res,rec(nx,j));
                }
            }
            return res+1;
            
        };
        int res = 0;
        for(int i=0;i<n;i++){
            for( int j=0;j<m;j++){
                res = max(res,rec(i,j));
            }
        }
        return res;
    }
};