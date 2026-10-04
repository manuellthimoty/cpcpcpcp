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
typedef unsigned long long ull;


void solve(){
    ll n ; cin >> n;
    ll m ; cin >> m ;
    string bits_n = bitset<64>(n).to_string();
    ll ones = 0;
    ll zeros = 0;
    for(auto s : bits_n){
        if(s == '0') zeros++;
        else ones++;
    }
    // vector<int> pref(60);
    // vector<int> suff(60);
    // pref[0] = (bits_n[0] == '1') ? 1 : 0;
    // suff[59] = (bits_n[59] == '1') ? 1 : 0;

    // for(int i = 1 ; i < 64 ; i++){
    //    pref[i] = (bits_n[i] == '1') ? pref[i-1] + 1: pref[0]; 
    // }
    // for(int i = 58 ; i >= 0 ; i--){
    //     suff[i] = (bits_n[i] == '1') ? suff[i] = suff[i+1] + 1 : suff[i];
    // }
    ll need = m - ones;
    if (need == 0) {
        for (int i = 62; i >= 0; i--) {
            if (bits_n[i] == '0' && bits_n[i+1] == '1') {
                bits_n[i] = '1';
                bits_n[i+1] = '0';
                int ones_right = 0;
                for (int j = i + 2; j < 64; j++) {
                    if (bits_n[j] == '1') {
                        ones_right++;
                        bits_n[j] = '0';
                    }
                }
                for (int j = 59; j >= 64 - ones_right; j--) {
                    bits_n[j] = '1';
                }
                break;
            }
        }
        ull ans = stoull(bits_n, nullptr, 2);
        cout << ans << endl;
    }
    else if(need > 0){
        for(int i = bits_n.size() -1 ; i >= 0 ;i--){
            if(need == 0){
                break;
            }
            if(bits_n[i] == '0'){
                bits_n[i] = '1';
                need--;
            }
        }
        ull ans = stoull(bits_n,nullptr,2);
        cout << ans << endl;
    }
    else{
        for (int i = 63; i >= 0; i--) {
            if (bits_n[i] == '0') {
                int prefix_ones = 0;
                for (int j = 0; j < i; j++) {
                    if (bits_n[j] == '1') prefix_ones++;
                }
                int newNeed = m - (prefix_ones + 1); 
                int space_right = 63 - i;
                if (newNeed >= 0 && newNeed <= space_right) {
                    string copy_bits = bits_n;
                    copy_bits[i] = '1';
                    for (int j = i + 1; j < 64; j++) {
                        copy_bits[j] = '0';
                    }
                    for (int j = 63; j >= 64 - newNeed; j--) {
                        copy_bits[j] = '1';
                    }
                    ull ans = stoull(copy_bits, nullptr, 2);
                    cout << ans << endl;
                    break; 
                }
            }
        }
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
