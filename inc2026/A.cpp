#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n ; cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    int mx = a[0];
    for(int i = 1; i < n ; i++) mx = max(mx,a[i]);
    cout << mx;
    // vector<vector<int>> a(n,vector<int>(n,0));
}
