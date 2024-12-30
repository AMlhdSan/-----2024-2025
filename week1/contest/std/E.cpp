#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int T, n, m, len[N], ans[N], lst[N], l[N], pp[45][N], ppp[45][N];
vector<int> st[N];

int main() {
    freopen("cyc.in", "r", stdin);
    freopen("cyc.out", "w", stdout);
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) st[i] = {};
        for (int i = 1; i <= m; i++) {
            ans[i] = l[i] = 0;
            lst[i] = -1;
            for (int j = 1; j <= 40; j++) pp[j][i] = ppp[j][i] = 0;
        }
        for (int i = 1, c; i <= n; i++) {
            scanf("%d", &len[i]);
            for (int j = 1; j <= len[i]; j++) scanf("%d", &c), st[i].push_back(c);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < len[i]; j++) {
                int c = st[i][j];
                if (lst[c] != i - 1)
                    l[c] = i;
                lst[c] = i;
                for (int k = 1; k <= 40; k++)
                    if (pp[k][c] >= l[c] && (ppp[k][c] - j) % __gcd(k, len[i]))
                        l[c] = pp[k][c] + 1;
                ppp[len[i]][c] = j;
                pp[len[i]][c] = i;
                ans[c] = max(ans[c], i - l[c] + 1);
            }
        }
        for (int i = 1; i <= m; i++) printf("%d%c", ans[i], " \n"[i == m]);
    }
    return 0;
}
