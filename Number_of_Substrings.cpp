#include<bits/stdc++.h>
using namespace std;
const int MAX_S = 5*(1e6)+5;
int tr[26][MAX_S];
int root,nn;
int count(int &p=root){
    if(!p) return 0;
    int cnt = 1;
    for(int i=0;i<26;i++) cnt += count(tr[i][p]);
    return cnt;
}

int countDistinctSubstrings(string &s)
{
    root = ++nn;
    for(int i=0;i<s.size();i++) {
        int r = root;
        for(int j=i;j<s.size();j++) {
            int ch = s[j]-'a';
            if(!tr[ch][r]) tr[ch][r]=++nn;
            r = tr[ch][r];
        }
    }
    return count();
}

int main(){
    string s;
    cin >> s;
    cout << countDistinctSubstrings(s)-1 << endl;
    return 0;
}