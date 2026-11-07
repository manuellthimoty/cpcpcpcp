#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll n,k; cin >> n >> k;
	if(k == n-1){
		for(int i = 0 ; i < n ; i++) cout << 0 << " ";
		return 0;
	}
	// 
	// a1 ak sum/n
    ll p = 10 * n;
	vector<int> ans(n+1,10);
	ll sisa = p - 10 * k;
	for(int i = k+1 ; i <= n ; i++){
		ans[i] = 1;
		sisa--;
	}
	if(sisa > 0){
		ans[n] += sisa;
	}
	for(int i = 1; i <= n ; i++) cout << ans[i] << " ";
	// vector<double> pref(n+1,0);
	// cout << endl;
	// for(int i = 1 ; i <= n ; i++) pref[i] = pref[i-1] + ans[i];
	// for(int t = 1;  t <= n -1 ; t++){
	// 	double kiri = pref[t]/t;
	// 	double kanan = (pref[n] - pref[t])/(n-t);
	// 	cout << "KIRI : " << kiri << " KANAN : " << kanan << endl;
	// }
}
