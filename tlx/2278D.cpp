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

void solve(){
    int n ; cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n ; i++){
        cin >> a[i];
    }
    sort(a.begin()+1,a.end());
    if(n % 2 == 0){
        ll sumpos = 0;
        ll sumneg = 0;
        for(int i = 1 ; i <= n/2 ; i++){
            sumneg += a[i];
        }
        for(int i = n/2 +1 ; i<= n ; i++){
            sumpos += a[i];
        }
        cout << sumpos - sumneg << " " << a[n] - a[1] << endl;
    }
    else{
        ll sumpos = 0;
        ll sumneg = 0;
        for(int i = 1 ; i <= n/2 ; i++){
            sumneg += a[i];
        }
        for(int i = n/2 +2 ; i<= n ; i++){
            sumpos += a[i];
        }
        cout << sumpos - sumneg << " " << a[n] - a[1] << endl;
    }
}
int main() {
    GK();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
