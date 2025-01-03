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
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
*/
int N = 100005;
vector <vector<int>> divv(N + 1);
void solve() {
	int n, ans = 0;
	cin >> n;
	vector <int> a(n);
	f(0, n, 1)cin >> a[i];
	
	sort(a.begin(), a.end());
	vector <int> cntDiv(N, 0), temp(N, 0);
	int remaining = n;
	for(auto k : a){
		
		remaining--;
		
		for(auto p : divv[k]){
			int val = cntDiv[p] - temp[p];
			for(auto l : divv[p]) temp[l] += val;
			ans += val * remaining * p;
		}
		
		for(auto p : divv[k]){
			for(auto l : divv[p]) temp[l] = 0;
		}
		
		for(auto i : divv[k]) cntDiv[i]++;
	}
	
	cout << ans << en;
}

int32_t main() {
//	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    for(int i = 1; i < N; i++){
    	for(int j = i; j < N; j += i) divv[j].pb(i);
	}
	f(1, N + 1, 1)sort(divv[i].rbegin(), divv[i].rend());
	cin >> t;
    while(t--)solve();
    return 0;
}
