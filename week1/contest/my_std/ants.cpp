#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6+5;
const int LEN = 1e9+1;
int A[N], d[N];
struct Node{
	int id, pos;
	bool operator<(const Node &b){return pos<b.pos;}		
};
vector<Node> vL, vR;
bool vis[N];

signed main(){
    freopen("ants.in", "r", stdin);
    freopen("ants.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	int n, L, R; cin >> n >> L >> R;
	for (int i=1; i<=n; ++i) cin >> A[i];
	for (int i=1; i<=n; ++i) cin >> d[i];
	for (int i=1; i<=n; ++i) {
		if (0==d[i]){
			vL.push_back(Node{i, A[i]}), vR.push_back(Node{i, LEN+A[i]});
			vL.push_back(Node{i, 2*LEN+A[i]}), vR.push_back(Node{i, 2*LEN+LEN+A[i]});
		}else{
			vL.push_back(Node{i, 2*LEN-A[i]}), vR.push_back(Node{i, LEN-A[i]});
			vL.push_back(Node{i, 2*LEN+2*LEN-A[i]}), vR.push_back(Node{i, 2*LEN+LEN-A[i]});
		}
	}
	sort(vL.begin(), vL.end()); sort(vR.begin(), vR.end());
	
	int mn=min(L, R);
	int ans=0;
	if (mn>=n) ans+=2*LEN*(mn/n), L-=mn/n*n, R-=mn/n*n;
	
	int pL=0, pR=0;
	int mx=0;
	while (pL<vL.size() && pR<vR.size()){
		if (vL[pL].pos<=vR[pR].pos){
			if (!vis[vL[pL].id]){
				if (L>0) --L;
				else mx=max(mx, vL[pL].pos), vis[vL[pL].id]=true;
			}
			++pL;
		}else{
			if (!vis[vR[pR].id]){
				if (R>0) --R;
				else mx=max(mx, vR[pR].pos), vis[vR[pR].id]=true;
			}
			++pR;
		}
	}
	
	while (pL<vL.size()){
		if (!vis[vL[pL].id]){
			if (L>0) --L;
			else mx=max(mx, vL[pL].pos), vis[vL[pL].id]=true;
		}
		++pL;
	}
	while (pR<vR.size()){
		if (!vis[vR[pR].id]){
			if (R>0) --R;
			else mx=max(mx, vR[pR].pos), vis[vR[pR].id]=true;
		}
		++pR;
	}
	
	cout << ans+mx << '\n';
	return 0;	
}
