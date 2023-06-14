void update(int BIT[],int x,int val,int N) { ++x;  while(x<=N)  {  BIT[x]+=val;BIT[x] %=MOD; x+=(x&-x);  } }
LL query(int BIT[],int x) {  ++x;  LL res=0;  while(x>0)  {  res+=BIT[x];res%=MOD;  x-=(x&-x);  } return res; } 
LL range(int bit[],int a,int b){ return (query(bit,b) - query(bit,a-1) + MOD)%MOD;}