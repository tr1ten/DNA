#include <bits/stdc++.h>
#define forn(i, l, r, k) for (int i = l; i <= r; i+= k)
#define fori(i, r, l, k) for (int i = r; i >= l; i-= k)
 
const int N = 300010;
const long long inf = 0x3f3f3f3f3f3f3f3f;
int t, n, a[N], nxt[N], r[N];
std::vector<int> ans;

int find(int x) { return r[x] == x ? x : r[x] = find(r[x]); }
void merge(int x, int y) { r[find(x)] = find(y); }
bool same_set(int x, int y) { return find(x) == find(y); }

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    forn(i, 0, n-1, 1)
      scanf("%d", &a[i]), nxt[i] = (i + 1)%n, r[i] = i;
    ans.clear();
    int c = 0;
    while (1) {
      int rc = find(c);
      printf("c = %d\n", c);
      if (std::__gcd(a[rc], a[nxt[rc]]) > 1) {
        if (same_set(rc, nxt[rc])) break;
        merge(rc, nxt[rc]);
        c = nxt[rc];
      } else {
        ans.push_back(nxt[rc] + 1);
        if ((int)ans.size() == n) break;
        c = nxt[rc] = nxt[nxt[rc]];
      }
    }
    printf("%d ", ans.size());
    for(auto &x : ans) printf("%d ", x);
    puts("");
  }
  return 0;
}