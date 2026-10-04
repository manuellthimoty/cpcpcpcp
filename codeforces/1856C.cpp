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
vector<int> a;
int n;
int k;
bool check(ll x){
    bool oks = false;
    for(int i = 0 ; i < n ; i++){
        ll cnt = 0;
        ll curTarget  = x;
        bool possible = false;
        for(int j = i ; j < n ; j++){
            if(a[j] >= curTarget){
                possible = true;
                break;
            }
            cnt += curTarget - a[j];
            curTarget--;
        }
        if(possible && cnt <= k){
            return true;
        }
    }
    return false;
}

void solve(){
    cin >> n >> k;
    // vector<int> a(n);
    a.resize(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    ll low = 0;
    ll high = 1e12;
    ll best = 0;
    while(low <= high){
        ll mid = low + (high - low)/2;
        if(check(mid)){
            low = mid+1;
            best = max(best,mid);
        }
        else high = mid-1;
    }
    cout << best << endl;
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
