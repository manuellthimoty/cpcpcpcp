#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// void solve(){
//     ll n ; cin >> n ;
//     vector <ll> a(2*n);
//     for(int i = 0 ; i < 2*n ; i++){
//         cin >> a[i];
//     }
//     vector <ll> unique_arr(2*n);
//     for(int i = 0 ; i < 2*n ; i++){
//         unique_arr[i] = a[i];
//     }
//     sort(unique_arr.begin(),unique_arr.end());

//     auto last_unique = unique(unique_arr.begin(),unique_arr.end());
//     unique_arr.erase(last_unique,unique_arr.end());
//     vector <ll> f(*max_element(unique_arr.begin(),unique_arr.end()),0);
//     // skearnag unique arr sudah berisi nilai nilai yang 
//     for(auto x : a){
//         f[x]++;
//     }
//     ll hitung_genap = 0;
//     for(auto x : unique_arr){
//         if(f[x] %2 == 0){
//             hitung_genap++;
//         }
//     }
//     cout << hitung_genap + unique_arr.size() << endl;
// }

void solve(){
    ll n;
    cin >> n;

    vector<ll> a(2*n);
    for(ll &x : a) cin >> x;

    // hitung frekuensi pakai map
    unordered_map<ll, ll> freq;
    for (auto x : a) freq[x]++;

    ll hitung_genap = 0;
    for (auto &p : freq) {
        if (p.second % 2 == 0) hitung_genap++;
    }
    if(hitung_genap==freq.size()){
        if(n%2 == 0){
            if(freq.size()%2 ==1){
                cout << 2*(freq.size()-1) << endl;
            }
            else{
                cout << 2*(freq.size()) << endl;
            }
        }
        else{
            if(freq.size() %2 == 1){
                cout << 2*(freq.size()) << endl;
            }
            else{
                cout << 2*(freq.size()-1) << endl;
            }
        }
        return;
    }
    cout << hitung_genap + freq.size() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; cin >> t;
    while(t--){
        solve();
    }
}