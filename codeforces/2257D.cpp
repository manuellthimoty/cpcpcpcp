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
    ll S,q; cin >> S >> q;
    vector<pair<ll,ll>> facts;
    
    for(ll i = 1; i * i <= S ; i++){
        if(S % i == 0){
            facts.push_back({i, S/i});
            if(i * i != S){
                facts.push_back({S/i, i});
            }
        }
    }
    sort(facts.begin(), facts.end()); 

    map<ll,ll> pref;
    pref[1] = S;
    for(int i = 1 ; i < (ll) facts.size() ; i++){
        ll curr = facts[i].first;
        ll before = facts[i-1].first;
        pref[curr] = pref[before] + (curr - before) * facts[i].second;
    }

    auto get_area_sampai = [&](ll target_x) {
        if (target_x == 0) return 0LL;
        ll low = 0;
        ll high = facts.size() - 1; 
        int idx_left = 0;
        bool adaNext = true;
        
        while(low <= high){
            ll mid = low + (high-low)/2;
            if(facts[mid].first == target_x){
                adaNext = false;
                idx_left = mid;
                break;
            }
            else if(facts[mid].first < target_x){
                idx_left = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        if(adaNext){
            ll left_fact = facts[idx_left].first;
            return pref[left_fact] + (target_x - left_fact) * facts[idx_left+1].second;
        }
        return pref[target_x];
    };

    while(q--){
        ll x,y; cin >> x >> y;
        ll x_bound = min(x,S);
        ll y_bound = min(y,S);

        ll ans = get_area_sampai(x_bound);

        ll low1 = 0;
        ll high1 = facts.size() - 1;
        ll found_idx = -1;
        
        while(low1 <= high1){
            ll mid = low1 + (high1-low1)/2;
            ll currfa = facts[mid].second;
            
            if(currfa > y_bound){ 
                found_idx = mid;
                low1 = mid + 1; 
            }
            else{
                high1 = mid - 1;
            }
        }

        if(found_idx != -1) {
            ll x_val = facts[found_idx].first;
            ll w = min(x_bound, x_val);
            ans -= get_area_sampai(w);
            ans += w * y_bound;
        }
        
        cout << ans << '\n';
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
