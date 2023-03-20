#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

// useful defs
typedef vector<int> VI;
typedef long long LL; 
typedef pair<int,int> PI;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,arr) for (auto& a: (arr))
#define sz(x) (int)(x).size()
#define mk_vec(name,sz,value) VI name(sz,value)
#define mk_mat(name,n,m,value) vector<vector<int>> name(n, vector<int>(m, value))
#define contains(x) find(x) != string::npos
#define take_vec(vec,sz) FOR(i,0,sz) cin>>vec[i]
#define sort_vec(vec) sort(vec.begin(), vec.end())
const LL MOD = 1e9+7;
const LL INF = 1e10+5;


// driver code


class Segment
{
public:
    Segment *left;
    Segment *right;
    LL mn;
    int start;
    int end;

    Segment(int i,int j,int val){
        this->start = i;
        this->end = j;
        this->mn = val;
    }
     Segment(int i,int j,int s,Segment *l,Segment *r){
            start = i;
            end = j;
            left = l;
            right = r;
            mn = s;
        }
    // ~Segment(){
    //     delete left;
    //     delete right;
    // }
};

class SegmentTree
{
private: 
    Segment *root;
    LL recQuery(int i,int j,Segment *segment){
        if(segment==nullptr || i>j) return INF; // invalid
        if(segment->start==i && segment->end==j) return segment->mn;
        int mid = (segment->start+segment->end)/2;
        return min(recQuery(i,min(j,mid),segment->left),recQuery(max(i,mid+1),j,segment->right));
    }
    void recUpdate(Segment *segment,int i,int newVal){
        if(segment->start==i && segment->end==i) {
            segment->mn = newVal;
            return;
        }
        int mid = (segment->start+segment->end)/2;
        if(i<=mid) recUpdate(segment->left,i,newVal);
        else recUpdate(segment->right,i,newVal);
        segment->mn = min(segment->left->mn,segment->right->mn);
    }

public:
    Segment *build(int i,int j,VI &nums){
        if(i>j) return nullptr;
        if(i==j) return new Segment(i,j,nums[i]);
        int mid = (i+j)/2;
        Segment *left = build(i,mid,nums);
        Segment *right = build(mid+1,j,nums);
        return new Segment(i,j,min(left->mn,right->mn),left,right); // similar to sum 
    }
    SegmentTree(VI nums){
        root = build(0,nums.size()-1,nums);
    }
    int queryMin(int l,int r){
        return recQuery(l,r,root);
    }
    void update(int ind,int val){
        recUpdate(root,ind,val);
    }

    // ~SegmentTree(){
    //     delete root;
    // }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    cin >> m >> n;
    vector<int> nums(m);
    for (int x = 0; x < m; x++) {
        cin >> nums[x];
    }
    SegmentTree ft(nums);
    for (int i = 0; i < n; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            ft.update(b-1, c);
        } else {
            cout << ft.queryMin(b-1, c-1) << endl;
        }
    }
}