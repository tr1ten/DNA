// credits:  https://codeforces.com/blog/entry/18051
#include <bits/stdc++.h>

using namespace std;
const int N = 1e5;  // limit for array size
int n;  // array size, near power of two
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}
int combine(int left,int right){return left+right;}


void update(int p, const int value) {
  for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
}

int query(int l, int r) {
  int resl, resr;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) resl = combine(resl, t[l++]); // l&1 mean l is right child, parent not included so shift to parent right
    if (r&1) resr = combine(t[--r], resr); // 
  }
  return combine(resl, resr);
}
// todo lazy progation
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", t + n + i); // update last level with acutal values
  build(); // build up the tree
  update(0, 1);
  printf("%d\n", query(1, 2)); // 1 index
  return 0;
}