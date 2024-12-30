#include <bits/stdc++.h>

#define N 500010
#define ENDL putchar('\n')

using namespace std;

int t, n;
int a[N];
int b[N];
int sta[N], top;

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

int main() {
    freopen("add.in", "r", stdin);
    freopen("add.out", "w", stdout);

    t = read();

    while (t--) {
        n = read();
        top = 0;
        for (int i = 1; i <= n; ++i) {
            a[i] = read();
            b[i] = a[i];
        }
        sort(b + 1, b + 1 + n);
        int mex = 0;
        for (int i = 1; i <= n; ++i)
            if (b[i] == mex)
                ++mex;
        if (mex == n) {
            puts("No");
            continue;
        }
        for (int i = 1; i <= n; ++i)
            if (a[i] == mex + 1)
                sta[++top] = i;
        if (top == 1 || top == 0) {
            puts("Yes");
            continue;
        }
        int cnt = 0;
        for (int i = 1; i < sta[1]; ++i) b[++cnt] = a[i];
        for (int i = sta[top] + 1; i <= n; ++i) b[++cnt] = a[i];
        sort(b + 1, b + 1 + cnt);
        int mex2 = 0;
        for (int i = 1; i <= cnt; ++i)
            if (b[i] == mex2)
                ++mex2;
        if (mex2 == mex)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}