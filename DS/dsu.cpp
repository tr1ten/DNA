#include <bits/stdc++.h>

using namespace std;


struct DSU
{
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i] = i; // oath compression
        size.resize(n,1);
    }
    int find(int u){
        if(parent[u]!=u) parent[u] = find(parent[u]);
        return parent[u];
    }
    bool unite(int u,int v){
        int ra = find(u);
        int rb = find(v);
        if(ra==rb) return 0;
        if(size[ra]<size[rb]) swap(ra,rb); // merge smaller to bigger tree
        size[ra] +=size[rb]; // union by rank
        parent[rb] = ra;
        return 1;
    }
};

