#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

template <class T>
inline void read(T &x) {
    x = 0;
    char c = getchar();
    bool f = 0;
    for (; !isdigit(c); c = getchar()) f ^= c == '-';
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    x = f ? -x : x;
}

template <class T>
inline void write(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    T y = 1;
    int len = 1;
    for (; y <= x / 10; y *= 10) ++len;
    for (; len; --len, x %= y, y /= 10) putchar(x / y + 48);
}

const int MAXN = 20;
int n, m;
LL k, ans, a[MAXN + 5][MAXN + 5];
map<LL, LL> cnt[MAXN + 5];

void dfs1(int x, int y, LL val) {//表示当前到点 (x,y)，路径异或和为 val 
    if (x + y == (n + m) / 2 + 1) {
        ++cnt[x][val];//统计 (1,1) -> (x,y) 异或和为 val 的路径数 
        return;
    }
    if (x < n) dfs1(x + 1, y, val ^ a[x + 1][y]);
    if (y < m) dfs1(x, y + 1, val ^ a[x][y + 1]);
}

void dfs2(int x, int y, LL val) {
    if (x + y == (n + m) / 2 + 1) {//搜到对角线就停止
        ans += cnt[x][k ^ val ^ a[x][y]];
        //这里异或 a[x][y] 是因为第二次到这个点多异或了 (x,y) 一次，
        //而第一次到 (x,y) 时已经异或过了，再异或一次相当于只保留一次异或 
        return;
    }
    if (x > 1) dfs2(x - 1, y, val ^ a[x - 1][y]);
    if (y > 1) dfs2(x, y - 1, val ^ a[x][y - 1]);
}

int main() {
    read(n), read(m), read(k);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            read(a[i][j]);
    dfs1(1, 1, a[1][1]);
    dfs2(n, m, a[n][m]);
    write(ans);
    putchar('\n');
    return 0;
}