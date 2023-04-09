#include <bits/stdc++.h>

using namespace std;

class RangeQuery{
    int n;
    int *tree;
    int parent(int i){
        return i/2;
    }
    vector<int> childs(int i){
        return {2*i,2*i+1};
    }
public:
    RangeQuery(int n){
        this->n = 1<<((int)log2(n-1)+1);
        this->tree = new int[2*n+1];
    };
    void update(int index,int diff){
        int i = index+n;
        tree[i] +=diff;
        i = parent(i);
        while(i>0){
            auto child = childs(i);
            int left = child[0];
            int right = child[1];
            tree[i] = max(tree[left],tree[right]);
            i = parent(i);
        }
    }
    int query(int left,int right){
        return _query(0,n-1,left,right,1);
    }
private:
    int _query(int ns,int ne,int start,int end,int node){
        if(ns==start && ne==end){
            return tree[node];
        }
        if(ne < start || end<ns) return INT_MIN; // doesn't lie in the range
        int mid = (ns+ne)/2;
        auto child = childs(node);
        int left = child[0];
        int right = child[1];
        return max(_query(ns,mid,start,min(mid,end),left),_query(mid+1,ne,max(start,mid+1),end,right));
    }
};
class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size();
        vector<RangeQuery> cols(m,RangeQuery(n));
        vector<RangeQuery> rows(n,RangeQuery(m));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int best = INT_MAX;
                if(i==n-1 && j==m-1) best = 1;
                if(i+1<n) best = min(best,1-cols[j].query(i+1,min(n-1,i+grid[i][j]))); 
                if(j+1<m) best = min(best,1-rows[i].query(j+1,min(m-1,j+grid[i][j])));
                cols[j].update(i,-best);
                rows[i].update(j,-best);
            }
        }
        int res = -rows[0].query(0,0);
        return res==INT_MAX?-1:res;
    }
};
