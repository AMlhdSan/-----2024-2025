#include <bits/stdc++.h>
#define For(i, a, b) for (int i = (a), i##END = (b); i <= i##END; i++)
#define Rof(i, b, a) for (int i = (b), i##END = (a); i >= i##END; i--)
#define go(u) for (int i = head[u]; i; i = nxt[i])
#define int long long
using namespace std;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
const int N = 2e5 + 10;
int n, a[N], dp[N];
#define pi pair<int, int>
#define fi first
#define se second
set<pi> s;
signed main() {
    freopen("bigwin.in", "r", stdin);
    freopen("bigwin.out", "w", stdout);
    n = read();
    For(i, 1, n) a[i] = read() + a[i - 1];
    s.insert(pi(a[0], 0));
    s.insert(pi(-1e18, -1e18));
    For(i, 1, n) {
        dp[i] = dp[i - 1];
        auto it = --s.lower_bound(pi(a[i] + 1, -1e18));
        if (it != s.end())
            dp[i] = max(dp[i], i + it->se);
        it++;
        if (it->fi == a[i] && it->se >= dp[i] - i)
            continue;
        if (it != s.begin() && prev(it)->se >= dp[i] - i)
            continue;
        it = s.insert(pi(a[i], dp[i] - i)).fi;
        while (next(it) != s.end() && next(it)->se <= it->se) s.erase(next(it));
    }
    cout << dp[n] << endl;
    return 0;
}
