int a[N],in[N],out[N];
int t=0;
int ans;
int n; 
struct Segment{
    int sum=0,mx_pref=0;
} segm[8*N]; // 0 index
Segment combine(Segment left,Segment right){
    Segment res;
    res.sum = (left.sum + right.sum);
    res.mx_pref = max(left.mx_pref,left.sum+right.mx_pref);
    return res;
}

// child- 2*x+1,2*x+2 (0 coz index)
// add x to [l...r]
void update(int node,int left,int right,int i,int value){
    if(left==i && right==i) {
            segm[node].sum = value;
            segm[node].mx_pref = max(0LL,value);
        }
    else{
        int mid = (left+right)/2;
        if(i<=mid) update(2*node+1,left,mid,i,value);
        else update(2*node+2,mid+1,right,i,value);
        segm[node] = combine(segm[2*node+1] , segm[2*node+2]);
    }
    
}

Segment query(int node,int left,int right,int l,int r){
    if(left>=l && right<=r) {return segm[node];}
    int mid = (left+right)/2;
    Segment res;
    if(l<=mid) res = combine(res,query(2*node+1,left,mid,l,r));
    if(r>mid) res = combine(res,query(2*node+2,mid+1,right,l,r));

    return res;
}
// everything is zero indexed
void update(int i,int x){
    update(0,0,n-1,i,x);
}
Segment query(int l,int r){
    return query(0,0,n-1,l,r);
}

void dfs(int u){
    in[u] = t++;
    for(auto v:g[u]){
        dfs(v);
    }
    out[u] = t++;
}
vi pending[N];
void dfs2(int u){
    for(auto v:g[u]){
        dfs2(v);
    }
    while (pending[a[u]].size() && in[pending[a[u]].back()]>in[u])
    {
        update(in[pending[a[u]].back()],0);
        update(out[pending[a[u]].back()],0);
        pending[a[u]].pop_back();
    }
    update(in[u],1);
    update(out[u],-1);
    pending[a[u]].push_back(u);
    int mx1=0,mx2=0;
    for(auto v:g[u]){
        int mx=query(in[v],out[v]).mx_pref;
        if(mx>mx1) {
            mx2 = mx1;
            mx1 = mx;
        }
        else if(mx2<mx){
            mx2 = mx;
        }
    }
    // cout << u << " " << mx1 << " " << mx2 << endl;
    ans = max(ans,(mx1+1)*(mx2+1));
}
void testcase(){   
    int m;
    cin >> m;
    rep(i,0,m) {g[i].clear();pending[i+1].clear();}
    rep(i,1,m){
        int v;
        cin >> v;
        v--;
        g[v].push_back(i);
    }
    tkv(a,m);
    ans = 0;
    t=0;    
    dfs(0);
    n = t;
    rep(i,0,n) update(i,0);
    dfs2(0);
    put(ans);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);      
    int T=1;
    cin>>T;
    while(T--) testcase();

    return 0;
}
