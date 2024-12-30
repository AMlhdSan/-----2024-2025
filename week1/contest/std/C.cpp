#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn], pre[maxn];
int main() {
    freopen("build.in", "r", stdin);
    freopen("build.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        set<pair<int, int>> s;
        for (int i = 1; i <= n; i++) a[i] = i;
        for (int i = 1; i <= m; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            if (x > y)
                swap(x, y);
            a[x] = max(a[x], y);
            s.insert(make_pair(x, y));
        }
        int ans = 0;
        a[1] = n;
        for (int x = 1, i = 2; i <= n; i++) {
            if (a[x] >= i)
                ans += (s.find(make_pair(x, i)) == s.end()), pre[i] = x, x = i;
            else
                x = pre[x], i--;
        }
        printf("%d\n", ans);
    }
    return 0;
}
