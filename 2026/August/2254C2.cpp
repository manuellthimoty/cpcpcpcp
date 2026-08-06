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
    int n; 
    cin >> n;
    string a, b; 
    cin >> a >> b;
    
    int fa_odd_0 = 0, fa_even_0 = 0, fa_odd_1 = 0, fa_even_1 = 0;
    int fb_odd_0 = 0, fb_even_0 = 0, fb_odd_1 = 0, fb_even_1 = 0;
    
    for(int i = 0 ; i < n ; i++){
        int cur_par = (i+1) % 2;
        if(cur_par == 0){
            if(a[i] == '1') fa_even_1++;
            else fa_even_0++;
        }
        else{
            if(a[i] == '1') fa_odd_1++;
            else fa_odd_0++; 
        }
    }
    for(int i = 0 ; i < n ; i++){
        int cur_par = (i+1) % 2;
        if(cur_par == 0){
            if(b[i] == '1') fb_even_1++;
            else fb_even_0++;
        }
        else{
            if(b[i] == '1') fb_odd_1++;
            else fb_odd_0++;
        }
    }
    if(!(fa_odd_0 == fb_odd_0 && fa_even_0 == fb_even_0 && fa_odd_1 == fb_odd_1 && fa_even_1 == fb_even_1)){
        cout << -1 << endl;
        return;
    }
    vint a_odd, a_even, b_odd, b_even;
    for(int i = 0 ; i < n ; i++){
        if(a[i] == '1'){
            if(i % 2 == 0) a_even.push_back(i);
            else a_odd.push_back(i);
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(b[i] == '1'){
            if(i % 2 == 0) b_even.push_back(i);
            else b_odd.push_back(i);
        }
    }
    ll ans = 0;
    for(int i = 0; i < a_odd.size(); i++){
        ans += abs(a_odd[i] - b_odd[i]) / 2;
    }
    for(int i = 0; i < a_even.size(); i++){
        ans += abs(a_even[i] - b_even[i]) / 2;
    }
    
    cout << ans << "\n";
    
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
