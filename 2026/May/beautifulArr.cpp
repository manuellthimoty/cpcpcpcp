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
    ll n ; cin >> n;
    ll k ; cin >> k;
    vector<ll> a(n+1);
    for(ll i = 1 ; i <= n ; i++) cin >> a[i];
    sort(a.begin(),a.end());
    map<ll,vector<ll>> md;
    for(ll i = 1 ; i <= n ; i++){
        ll m = a[i] % k;
        md[m].push_back(a[i]);
    }
    ll cntganjil = 0;
    for(auto m : md){
        if(m.second.size() % 2 == 1){
            cntganjil++;
        }
    }
    if(cntganjil > 1){
        cout << - 1<< endl;
        return;
    }
    for(auto m : md){
        // cout << "sort";
        sort(m.second.begin(), m.second.end());
    }

    
    ll ans = 0;
    for(auto m : md){
        ll curSize = m.second.size();
        // if(curSize % 2 == 1){
        //     vector<pair<ll, pair<ll, ll>>> diff;
        //     for(int i = 1 ; i < curSize ; i++){
        //         diff.push_back({m.second[i] - m.second[i-1],{i,i-1}});
        //     }
        //     sort(diff.begin(),diff.end());
        //     // for(auto d : diff) cout << d.first << " ";
        //     vector<bool> checked(curSize,false);
        //     for(auto d : diff){
        //         if(!checked[d.second.first] && !checked[d.second.second]){
        //             checked[d.second.first] = true;
        //             checked[d.second.second] = true;
        //             ans += d.first/k;
        //             // cout << "HEHE" << endl;
        //             // cout << d.first << " ";
        //         }
        //     }
        // }
        if(curSize % 2 == 1){
            if(curSize == 1) continue; // Langsung skip jika hanya 1 elemen (cost 0)
            
            int p_size = curSize / 2;
            vector<ll> pref(p_size + 1, 0), suff(p_size + 1, 0);
            
            // Hitung prefix sum pasangan dari kiri ke kanan
            for(int i = 0; i < p_size; i++) {
                pref[i + 1] = pref[i] + (m.second[2 * i + 1] - m.second[2 * i]) / k;
            }
            
            // Hitung suffix sum pasangan dari kanan ke kiri
            for(int i = p_size - 1; i >= 0; i--) {
                suff[i] = suff[i + 1] + (m.second[2 * i + 2] - m.second[2 * i + 1]) / k;
            }
            
            ll min_diff = 2e18; // Angka besar sebagai inisialisasi minimal
            // Coba hapus setiap index genap i = 0, 2, 4...
            for(int i = 0; i <= p_size; i++) {
                min_diff = min(min_diff, pref[i] + suff[i]);
            }
            ans += min_diff;
        }
        else{
            for(ll i = 0 ; i < curSize ; i+=2){
            if(i + 1 < curSize){
                ll tmbh = (m.second[i+1] - m.second[i])/k;
                ans += tmbh;
            }
        }
    }
    }
    cout << ans << endl;
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
