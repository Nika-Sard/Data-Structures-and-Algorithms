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
 
/*#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 */

template <class T> istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v) is >> x;
    return is;
}
template <class T> ostream& operator<<(ostream& os, const vector<T>& v) {
    auto sep = "";
    for (const auto& x : v) os << x << " ";
    return os;
}

const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int INF = 1e7;

void solve() {
    int w, f;
    cin >> w >> f;
    int n, sum = 0;
    cin >> n;
    vi a(n + 1);
    f(1, n + 1, 1){
    	cin >> a[i];
    	sum += a[i];
	}
	sort(a.begin() + 1, a.end());
	vector<bool> dp(sum + 1, 0);
	dp[0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = sum; j >= 0; j--){
			if(j - a[i] >= 0) dp[j] = dp[j] || dp[j - a[i]];
		}
	}
    
    int ans = INF;
   	for(int i = sum; i >= 0; i--){
   		int t = i / w + (i % w != 0);
   		int t2 = i / f + (i % f != 0);
   		if(dp[i]){
   			if(t * f >= sum - i) ans = min(ans, t);	
   			if(t2 * w >= sum - i) ans = min(ans, t2);	
		}
	}
	cout << ans << en;
}

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
	cin >> t;
    while(t--)solve();
    return 0;
}
