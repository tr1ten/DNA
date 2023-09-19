// credits:  https://codeforces.com/blog/entry/18051
// i hate segment tree so so bad
#include <bits/stdc++.h>

using namespace std;
const int N = 1e2;  // limit for array size
int n;  // array size, near power of two, define it in main
int t[2 * N]; // 0 index
// iterative segment tree

int combine(int left,int right){return max(left,right);} // donot forget to change this for min query
void build() {  // build the tree; fill from last secnod layer
    for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
}


void update(int p, const int value) {
  for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
}

int query(int l, int r) { // [l,r) important
  int resl=0, resr=0; // fk take care of this, if min query then set it to INF
   for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) resl = combine(resl, t[l++]); // l&1 mean l is right child, parent not included so shift to parent right
    if (r&1) resr = combine(t[--r], resr); // 
  }
  return combine(resl, resr);
}

void init(int n){
  for (int i = 0; i < n; ++i) t[n + i]=0;
  build();
}
// todo lazy progation
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
  build(); // fill other layers
  // update(0, 101);
  printf("%d\n", query(0, 3));
  return 0;
}