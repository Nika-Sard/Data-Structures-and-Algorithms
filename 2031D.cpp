#include <bits/stdc++.h>
#define ss second
#define ff first
#define en '\n'
#define pb push_back
#define int long long
#define pii pair <int,int>
#define vi vector <int>
#define f(st, x, d) for(int i = st; i < x; i += d)
#define carray(x) for(auto k : x) cout << k << ' ';
#define all(x) begin(x), end(x) 
using namespace std;
 
const int mod = 1e9 + 7;
const int N = 50023;
const int INF = 1e9;

void solve() {
	int n;
	cin >> n;
	vi a(n + 1), mx(n + 1), dp(n + 1);
	vector<pair<int,int>> mn(n + 1); 
	mx[0] = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		mx[i] = max(mx[i - 1], a[i]);
		dp[i] = a[i];
	}
	mn[n] = {a[n], n};
	dp[n] = mx[n];
	for(int i = n - 1; i >= 1; i--){
		mn[i] = min(mn[i + 1], {a[i + 1], i + 1});
	}
	for(int i = n - 1; i >= 1; i--){
		if(mx[i] <= mn[i + 1].ff){
			dp[i] = mx[i];
			continue;
		}
		dp[i] = max(mx[i], dp[mn[i + 1].ss]);
	}
	for(int i = 1; i <= n; i++) cout << dp[i] << ' ';
	cout << en;
}

int32_t main() {
   	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
 
