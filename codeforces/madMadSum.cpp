#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll n; cin >> n;
    vector<ll> a(n);
    for(ll i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    map<ll,ll> freq;
    vector<ll> mad(n,0);
    freq[a[0]] =1 ;
    mad[0] = 0;
    ll maxVal = 0;
    for(ll i = 1 ; i < n ; i++){
        freq[a[i]] ++ ;
        if(freq[a[i]] >=2){
            if(a[i] > maxVal){
                mad[i] = a[i];
                maxVal = a[i];
                continue;
            }
        }
        mad[i] = mad[i-1];
    }
    // cout << mad[0];
    ll sum = 0;
    map<ll,ll> freqMad;


    for(auto x : a) sum+=x;
    for(auto x : mad) sum+= x;
    vector<ll> newMad(n,0);
    ll maxVal2 = 0;
    newMad[0] = 0;
    if(n > 1){
        newMad[1] = 0;
        freqMad[mad[1]] = 1;
        for(ll i = 2 ; i < n ; i++){
            freqMad[mad[i]] ++;
            if(freqMad[mad[i]] >=2){
                if(mad[i] > maxVal2){
                    newMad[i] = mad[i];
                    maxVal2 = newMad[i];
                    continue;
                }
            }
            newMad[i] = newMad[i-1];
        }
    }

    for(ll i = 0 ; i < n ; i++){
        sum+= newMad[i] * (n-i);s
    }
    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}