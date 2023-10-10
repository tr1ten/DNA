#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
vector<vector<int>> divs(N+1);
// find prime <sqrt(MAX)
// O(LlogL)
void preprocess(){
    for(int x=2;x<=N;x++){
        for(int u=x;u<=N;u +=x){
            divs[u].push_back(x);   
        }
    }
}
class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        preprocess();
        unordered_map<int,int> dd;
        for(int &x:nums){
            for(int y:divs[x]){
                if(dd.count(y)) dd[y] =  gcd(dd[y],x);
                else dd[y] = x;
            }
        }
        int res = 0;
        for(auto &x:dd){
            res += (x.first == x.second);
        }
        return res;
    }
};
