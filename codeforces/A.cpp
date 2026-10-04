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
vector<int> x;
vector<int> p;
vector<pair<int,int>> m;
vector<ll> pref;

int n;
bool check(ll r, ll k){
    ll total = 0;
    int left = 0;
    int right = 0;
    ll cur = 0;
    while(left < n && right < n){
        if(m[right].first - m[left].first > 2LL * r){
            cur -= m[left].second;
            left++;
        }
        else{
            cur += m[right].second;
            if(cur >= k) return true;
            right++;
        }
    }
    return false;
}

void solve(){
    // int n;
    cin >> n;
    ll k ; cin >> k;
    m.resize(n);
    pref.resize(n);
    ll tot = 0;
    for(int i = 0 ; i < n ; i++){
        int x,y ; cin >> x >> y;
        tot += y;
        m[i] = {x,y};
    }
    if(tot < k){
        cout << -1 << endl;
        return;
    }
    sort(m.begin(),m.end());
    pref[0] = m[0].second;
    for(int i = 1;  i < n ; i++){
        pref[i] = pref[i-1] + m[i].second;
    }
    int low = 0;
    int high = 1e9;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(check(mid,k)){
            high = mid-1;
        }
        else low = mid+1;
    }
    cout << low << endl;
    
    
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
