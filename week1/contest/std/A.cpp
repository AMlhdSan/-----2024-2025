#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using uint = unsigned int;

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg, x.ed
#define si(x) int(x.size())
#ifdef LOCAL
#define dmp(x) cerr << __LINE__ << " " << #x << " " << x << endl
#else
#define dmp(x) void(0)
#endif

template <class t, class u>
bool chmax(t& a, u b) {
    if (a < b) {
        a = b;
        return true;
    } else
        return false;
}
template <class t, class u>
bool chmin(t& a, u b) {
    if (b < a) {
        a = b;
        return true;
    } else
        return false;
}

template <class t>
using vc = vector<t>;
template <class t>
using vvc = vc<vc<t>>;

using P = pair<int, int>;
using vi = vc<int>;

void solve() {
    int n;
    cin >> n;
    vc<int> A(n);
    set<int> st;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        st.insert(A[i]);
    }
    int m = 0;
    while (st.find(m) != st.end()) m++;
    int l = n, r = -1;
    for (int i = 0; i < n; i++) {
        if (A[i] == m + 1) {
            l = min(l, i);
            r = max(r, i);
        }
    }
    bool up;
    if (l <= r) {
        vc<int> use(m);
        for (int i = 0; i < n; i++) {
            if (i < l || r < i) {
                if (A[i] < m)
                    use[A[i]] = 1;
            }
        }
        int c = 0;
        for (int i = 0; i < m; i++) c += use[i];
        up = (c == m);
    } else {
        vc<int> use(m);
        for (int i = 0; i < n; i++) {
            if (A[i] < m)
                use[A[i]] = 1;
        }
        int c = 0;
        for (int i = 0; i < m; i++) c += use[i];
        up = !(c == n);
    }
    cout << (up ? "Yes" : "No") << endl;
}
int main() {
    freopen("add.in", "r", stdin);
    freopen("add.out", "w", stdout);
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int T;
    cin >> T;
    while (T--) solve();
}
