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
const int N = 1e6 + 10, Len = 1e9 + 1;
int n, A, B, a[N], d[N];
queue<int> L, R;
signed main() {
    freopen("ants.in", "r", stdin);
    freopen("ants.out", "w", stdout);
    n = read(), A = read(), B = read();
    For(i, 1, n) a[i] = read();
    For(i, 1, n) d[i] = read();
    int o = min(A, B) / n;
    int ans = o * (2 * Len);
    A -= o * n, B -= o * n;
    For(i, 1, n) if (d[i] == 0) L.push(a[i]);
    Rof(i, n, 1) if (d[i] == 1) R.push(Len - a[i]);
    int t = 0;
    while (L.size() + R.size()) {
        if (R.empty() || (!L.empty() && L.front() < R.front())) {
            t = L.front(), L.pop();
            if (A)
                R.push(t + Len), A--;
        } else {
            t = R.front(), R.pop();
            if (B)
                L.push(t + Len), B--;
        }
    }
    printf("%lld\n", ans + t);
    return 0;
}
