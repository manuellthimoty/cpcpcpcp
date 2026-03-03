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

void solve(){
    int n,m,k ; cin >> n >> m >> k;
    vll a(n),b(m);
    input(a,0,n);
    input(b,0,m);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int count = 0;
    int i = 0, j = 0;
    while(i < n && j < m){
        if(abs(a[i] - b[j]) <= k){
            count++;
            i++;
            j++;
        }else if(a[i] < b[j] - k){
            i++;
        }else{
            j++;
        }
    }
    cout << count << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
