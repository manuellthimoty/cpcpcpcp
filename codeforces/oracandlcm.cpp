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
ll power(ll a, ll b){
    ll res = 1;
    while (b > 0) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n ; cin >> n;
    vint a(n); for(int i = 0 ; i < n ; i++) cin >> a[i];
    vector<int> allprime;
    int mx = *max_element(a.begin(),a.end());

    //sieve
    vector<bool> is_prime(mx+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= mx; i++) {
        if (is_prime[i] && (long long)i * i <= mx) {
            for (int j = i * i; j <= mx; j += i)
                is_prime[j] = false;
        }
    }
    for(int i = 2; i<= mx ; i++){
        if(is_prime[i]) allprime.push_back(i);
    }
    vector<vector<pair<int,int>>> factz(n);
    for(int i = 0 ; i <n ; i++){
        int cur = a[i];
        for(auto x : allprime){
            if(x* x > cur) break;
            int pangkat = 0;
            while(cur % x == 0){
                cur = cur / x;
                pangkat++;
                if(cur == 1) break;
            }
            if(pangkat > 0)factz[i].push_back(make_pair(x,pangkat));
        }
        if(cur > 1){
            factz[i].push_back(make_pair(cur,1));
        }
    }
    // for(int i = 0 ; i < n ; i++){
    //     for(auto res : factz[i]){
    //         cout << res.first << " " << res.second << " ";
    //     }
    //     cout << endl;
    // }
    map<int,vector<int>> listprimefacts;
    for(int i = 0 ; i < n ; i++){
        for(auto res : factz[i]){
            int p = res.first; int pangkat = res.second;
            listprimefacts[p].push_back(pangkat);
        }
    }
    ll ans = 1;
    for(auto res : listprimefacts){
        if(res.second.size() < n-1){
            continue;
        }
        else{
            sort(res.second.begin(),res.second.end());
            int choose = 0;
            if(res.second.size() == n) choose = res.second[1];
            else if(res.second.size() == n-1) choose = res.second[0];
            ans *= power(res.first,choose);

        }
    }
    cout << ans << endl;
    



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
