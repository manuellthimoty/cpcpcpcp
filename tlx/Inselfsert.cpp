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

bool check(string s, ll m){
    ll cur = s[0] - '0';
    cur %= m;
    for(int i = 1; i < s.size() ; i++){
        int curdig = s[i] - '0';
        cur = cur * 10 + curdig;
        cur %= m;
    }
    return cur == 0;
}

int main() {
    GK();

    string s; cin >> s;
    int n = s.size();
    ll m ; cin >> m;
    ll k ; cin >> k;
    vector<ll> pref(n);
    vector<ll> pow10(1000005);
    pow10[0] = 1;
    for(int i = 1; i < 1000005 ; i++){
        pow10[i] = 10 * pow10[i-1];
        pow10[i] %= m;
    }
    pref[0] = (s[0] - '0') * pow10[n-1];
    pref[0] %= m;
    for(int i = 1; i < n ; i++){
        ll curr = (s[i]-'0') * pow10[n-1-i];
        curr %= m;
        pref[i] = pref[i-1] + curr;
        pref[i] %= m;
    }
    vector<bool> bisa(k+1,false);
    for(int x = 1; x <= k ; x++){
        ll mostleft = x * pow10[n];
        mostleft %= m;
        mostleft += pref[n-1];
        mostleft %= m;
        if(mostleft == 0){
            bisa[x] = true;
            continue;
        }
        for(int taruh = 0 ; taruh < n-1 ; taruh++){
            ll left = pref[taruh];
            ll final = left;
            final *= 10;
            final %= m;
            ll mid = x * pow10[n-1-taruh];
            
            mid %= m;
            final += mid;
            final %= m;
            ll right = pref[n-1] - pref[taruh];
            right += m;
            right %= m;
            final += right;
            final %= m;
            if(final == 0){
                bisa[x] = true;
            }
        }
        ll mostright = pref[n-1];
        mostright *= 10;
        mostright %= m;
        mostright += x;
        mostright %= m;
        if(mostright == 0){
            bisa[x] = true;
        }
    }
    int ans = 0;
    for(int i = 1; i  <= k ; i++){
        ans += bisa[i];
    }
    cout << ans;


    return 0;
}
