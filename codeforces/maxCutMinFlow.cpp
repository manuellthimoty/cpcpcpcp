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
#define GK() ios::sync_with_stdio(false);cin.tie(nullptr)

int main() {
    GK();

    int n ; cin >> n;
    int b ; cin >> b;
    vector<int> x(n-1);
    for(int i = 0 ; i < n-1 ; i++) cin >> x[i];
    int cntpos = 0;
    int cntneg = 0;
    for(int i = 0 ; i < n-1 ; i++){
        if(x[i] >= 0) cntpos++;
        else cntneg++;
    }
    // cout << cntpos << endl;
    if(cntpos > 0){
        ll ans = b;
        for(int i = 0 ; i < n-1 ; i++){
            if(x[i] >= 0) ans += x[i];
        }
        cout << ans << endl;
    }
    else{
        int mn = abs(x[0]);
        for(int i = 1 ; i < n-1 ; i++) mn = min(mn,abs(x[i]));
        if(b < mn){
            cout << -1 << endl;
        }
        else cout << b - mn << endl;
    }

    return 0;
}
