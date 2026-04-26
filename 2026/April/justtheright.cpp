#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n; 
    cin >> n;
    int M = 1e9+7;
    vector<ll> count_less_even(n + 2, 0); 
    vector<ll> count_less_odd(n + 2, 0);  
    vector<ll> count_great_even(n + 2, 0); 
    vector<ll> count_great_odd(n + 2, 0); 

    int evens_so_far = 0, odds_so_far = 0;
    for(int i = 1; i <= n; i++){
        count_less_even[i] = evens_so_far; // Simpan dulu
        count_less_odd[i] = odds_so_far;   // Simpan dulu
        
        if(i % 2 == 0) evens_so_far++;
        else odds_so_far++;
    }

    evens_so_far = 0; odds_so_far = 0;
    for(int i = n; i >= 1; i--){
        count_great_even[i] = evens_so_far; 
        count_great_odd[i] = odds_so_far;   
        
        if(i % 2 == 0) evens_so_far++;
        else odds_so_far++;
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        if(i % 2 == 0){
            // Kasus 1: (a genap, b genap, c genap)
            ans += (count_less_even[i] * count_great_even[i]) % M;
            
            // Kasus 3: (a ganjil, b genap, c ganjil)
            ans += (count_less_odd[i] * count_great_odd[i]) % M;
        } 
        else {
            // Kasus 2: (a genap, b ganjil, c ganjil)
            ans += (count_less_even[i] * count_great_odd[i]) % M;
            
            // Kasus 4: (a ganjil, b ganjil, c genap)
            ans += (count_less_odd[i] * count_great_even[i]) % M;
        }
    }
    
    cout << ans % M<< endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if(cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}