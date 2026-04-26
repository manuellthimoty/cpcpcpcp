#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define vll vector<ll>
#define vint vector<int>
#define input(a,l,r) for(int i = l ; i < r ; i++) cin >> a[i];
#define REP(i,l,r) for(int i = l ; i < r ; i++)
#define REPLL(i,l,r) for(ll i = l ; i < r ; i++)

ll get2s(ll n){
    ll count = 0;
    while(n % 2 == 0){
        n = n/2;
        count++;
    }
    return count;
}


void solve(){
    ll n ; cin >> n;
    vector<ll> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    for(int i = 0 ; i < n ; i++){
        a[i] = get2s(a[i]);
    }
    
    stack<ll> s;
    for(int i = 0; i < n; i++) {
        ll current = a[i];
        while(!s.empty() && s.top() == current) {
            s.pop();
            current ++; 
        }
        s.push(current);
    }
    if(s.size() <= 1) {
        cout << "YA";
    }
    else cout << "TIDAK";
}int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
