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
    ll n,s ; cin >> n >> s;
    vector<pair<ll,pair<ll,ll>>> val(n);
    for(int i = 0 ; i < n ; i++){
        ll a,b; cin >> a >> b;
        val[i] = {a,{b,i+1}};
    }
    sort(val.begin(),val.end());
    if(s < val[0].first){
        cout << "TIDAK" << endl;

        return;
    }

    vector<ll> pref(n);
    vector<ll> prefB(n);
    prefB[0] = val[0].second.first;
    pref[0] = val[0].first;
    for(int i = 1; i < n ; i++){
        pref[i] = pref[i-1] + val[i].first;
        prefB[i] = prefB[i-1] + val[i].second.first;
    }
    if(s > prefB[n-1]){
        cout << "TIDAK" << endl;
        return;
    }
    vector<ll> prefK(n);
    prefK[0] = val[0].second.first - val[0].first;
    for(int i = 1; i < n ; i++){
        prefK[i] = prefK[i-1] + val[i].second.first - val[i].first;
    }
    ll low = 0;
    ll high = n-1;
    ll best = -1;
    // cari i shg pref[i] <= s dan maks
    while(low <= high){
        ll mid = low + (high - low)/2;
        if(pref[mid] > s){
            high = mid-1;
        }
        else if(pref[mid] == s){
            best = mid;
            break;
        }
        else{
            best = max(best, mid);
            low = mid+1;
        }
    }
    ll sisa = s - pref[best];
    // cout << sisa << endl;
    // cout << prefK[best] << endl;
    if(sisa > prefK[best]){
        // cout << "!" << endl;
        cout << "TIDAK" << endl;
        return;
    }
    int cur = 0;
    vector<ll> tambah(best+1,0);
    while(sisa > 0){
        ll curTambah = min(val[cur].second.first - val[cur].first,sisa);
        sisa -= curTambah;
        tambah[cur] = curTambah;
        cur++;
    }
    for(auto a : val){
        cout << a.second.second << " " << a.first << " " << a.second.first << endl;
    }
    cout << "YA" << endl;
    cout << best + 1<< endl;
    vector<pair<ll,ll>> ans;
    for(int i = 0 ; i <= best ; i++){
        ans.push_back({val[i].second.second,val[i].first + tambah[i]});
        // cout << val[i].second.second << " " << val[i].first + tambah[i] << endl;
    }
    sort(ans.begin(),ans.end());
    for(auto a : ans){
        cout << a.first << " " << a.second << endl;
    }


    
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
