#include <bits/stdc++.h>
#define sc second
#define ff first
#define en '\n'
#define pb push_back
#define int long long
#define pii pair <int,int>
#define all(x) begin(x), end(x) 
using namespace std;
 
/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
*/
vector <int> sum, dif;
int n;

int right_binary(int pos, int val){
	int l = pos + 1, r = n;
	int ans = r;
	if(pos == n)return -1;
	while(l <= r){
		int mid = (l + r) / 2;
		if(sum[mid] - sum[pos] > val && dif[mid] - dif[pos + 1] >= 1){
			ans = mid;
			r = mid - 1;
		}else l = mid + 1;
	}
	if(sum[ans] - sum[pos] <= val || dif[ans] - dif[pos + 1] < 1){
		return -1;
	}
	return ans - pos;
}

int left_binary(int pos, int val){
	int l = 1, r = pos - 1;
	int ans = 1;
	if(pos == 1)return -1;
	while(l <= r){
		int mid = (l + r) / 2;
		if(sum[pos - 1] - sum[mid - 1] > val && dif[pos - 1] - dif[mid] >= 1){
			ans = mid;
			l = mid + 1;
		}else r = mid - 1;
	}
	if(sum[pos - 1] - sum[ans - 1] <= val || dif[pos - 1] - dif[ans] < 1){
		return -1;
	}
	return pos - ans;
}

void solve(){
	cin >> n;
	int a[n + 1];
	sum.clear(); dif.clear();
	sum.resize(n + 1); dif.resize(n + 1);
	for(int i = 1; i <= n; i++)cin >> a[i];
	
	a[0] = 0; sum[0] = 0; dif[0] = 0;
	for(int i = 1; i <= n; i++){
		sum[i] = a[i] + sum[i - 1];
		dif[i] = dif[i - 1];
		if(a[i] != a[i - 1])dif[i]++;
	}
	
	for(int i = 1; i <= n; i++){
		if(a[i] < a[i - 1] || (i != n && a[i] < a[i + 1])) {
			cout << "1 "; continue;
		}
		int second1 = left_binary(i, a[i]);
		int second2 = right_binary(i, a[i]);
		if(second2 == -1 || second1 == -1){
			cout << max(second1, second2) << ' ';
		}else cout << min(second1, second2) << ' ';
	}
	
	cout << en;
	
}
 
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
	cin >> t;
    while(t--)solve();
    return 0;
}
