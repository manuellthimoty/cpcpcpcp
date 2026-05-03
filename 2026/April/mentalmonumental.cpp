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

bool can(ll n,ll k){
    //apakah tdpt bilangan m shg n = k mod m, dan m > k
    // syarat : m | n-k
    if(n == k) return true;
    ll cek = n - k;
    if(n % cek == k) return true;
}

void solve(){
    int n ; cin >> n;
    vector<int> a(n);
    input(a,0,n);
    sort(a.begin(),a.end());
    int max = 0;
    for(int i = 0 ; i < n ; i++){
        if(can(a[i],max)){
            max++;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
