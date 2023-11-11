#include<bits/stdc++.h>
#define endl '\n'
using namespace std; 
const int SZ = 262144; 
struct Segment 
{
    int sum=0;
    int suff0 = 0;
    int pref1 = 0;
}seg[2*SZ];
Segment combine(Segment left, Segment right)
{
    Segment res;
    res.sum = (left.sum + right.sum);
    int d = min(left.suff0,right.pref1);
    res.pref1 = left.pref1 ;
    res.suff0 = right.suff0;
    if(d==left.suff0) res.pref1 += right.pref1-d;
    if(d==right.pref1) res.suff0 += left.suff0 -d;
    res.sum +=d;
    return res;
    return res;
}
int update(int p, int value) 
{
    p += SZ;
    seg[p].suff0 = !value;
    seg[p].pref1 = value;
    for (; p > 1; p >>= 1)
    {
            seg[p>>1] = combine(seg[(p|1)^1], seg[p|1]);
    }
    return 0;
} 
Segment query(int l, int r) 
{ 
    Segment resL, resR; r++;
    for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
        if (l&1) resL = combine(resL,seg[l++]);
        if (r&1) resR = combine(seg[--r],resR);
    }
    return combine(resL,resR);
}
int solve()
{
    string s;
    cin>>s;
    int n = s.size();
    for(int i=0; i<n; i++)
    {
        update(i, s[i]-'0');
    }
    int q; cin>>q;
    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int pos;
            cin>>pos; pos--;
            update(pos, (s[pos]-'0')^1);
            s[pos] = '0' + ((s[pos]-'0')^1);
        }
        else
        {
            int l, r;
            cin>>l>>r;
            l--; r--;
            Segment ans = query(l, r);
            cout<<(r-l+1-2*ans.sum)<<endl;    
        }
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}