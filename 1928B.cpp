    //CF1928B
    #include <bits/stdc++.h>
    using namespace std;

    const int N = 2e5 + 10;
    int T, n, a[N];

    int main(){
        scanf("%d", &T);
        while(T--){
            scanf("%d", &n);
            for(int i = 1; i <= n; ++ i){
                scanf("%d", &a[i]);
            }
            sort(a + 1, a + n + 1);
            int m = unique(a + 1, a + n + 1) - a - 1;
            int ans = 0;
            for(int i = 1, j = 1; i <= m; ++ i){
                while(a[i] - a[j] >= n) ++ j;
                ans = max(ans, i-j+1);
            }
            printf("%d\n", ans);
        }
        return 0;
    }