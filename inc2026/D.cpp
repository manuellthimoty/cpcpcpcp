#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll n ; cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n ; i++) cin >> a[i];
    int cnt = 0;
    for(int i = 1; i <= n ; i++){
        if(a[i] <= n){
            if(a[i] != i || 2 * i <= n){
                cout << "Draw";
                return 0;

            }
            cnt++;
        }
    }
    if(cnt % 2 == 1){
        cout << "Fausta";
    }
    else cout << "Tresno";
}
