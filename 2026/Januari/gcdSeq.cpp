#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
ll gcd(ll a, ll b){
    if(b == 0) return a;
    if(a == 0) return b;
    if(a == 1 || b == 1) return 1;
    return gcd(b, a % b);
}
void solve() {
    ll n ; cin >> n;
    vector<ll> a(n+1,0);
    for(ll i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    vector <ll> gcdFirst(n,0);
    for(ll i = 1 ; i <= n-1 ; i++ ){
        gcdFirst[i] = gcd(a[i],a[i+1]);
    }
    vector <ll> gcdSecond(n-1,0);
    for(ll i = 1 ; i <= n-2 ; i++){
        gcdSecond[i] = gcd(a[i],a[i+2]);
    }
    vector <bool> isOks(n,true);
    vector <bool> isOksLeft(n,false);
    isOksLeft[0] = true;
    for(ll i = n-2 ; i >= 1 ; i--){
        if(gcdFirst[i] <= gcdFirst[i+1] && isOks[i+1]){
            isOks[i] = true;
        }
        else{
            isOks[i] = false;
        }
    }

    for(ll i = 1 ; i <= n -2 ; i++){
        if(gcdFirst[i] >= gcdFirst[i-1] && isOksLeft[i-1]){
            isOksLeft[i] = true;
        }
        else isOksLeft[i] = false;
    }
    bool isSorted = true;
    for(ll i = 1 ;i <= n-1 ; i++){
        if(!isOks[i]){
            isSorted = false;
            break;
        }
    }
    bool ans = false;
    if(isSorted){
        ans = true;
    }
    for(ll i =  1; i<= n-2 ; i++){
        if(i == 1){
            if(isOks[i+2] && gcdSecond[i] <= gcdFirst[i+2]){
                ans = true;
                // return;
            }
            continue;
        }
        if(i == n-2){
            if(isOksLeft[i-1] && gcdSecond[i] >= gcdFirst[i-1] 
            ){
                ans = true;
                // return;
            }
            continue;
        }
        if(gcdSecond[i] >= gcdFirst[i-1] && gcdSecond[i] <= gcdFirst[i+2] &&
        isOksLeft[i-1] && isOks[i+2] ){
            ans = true;
            // return;
        }
    }
    if(!ans){
        bool ujung1 = true;
        if(isOks[1] == false){   
            for(ll i = 2; i <= n-2; i++){
                if(!isOks[i]){
                    ujung1 = false;
                    break;
                }
            }
        }
        bool ujung2 = true;
        if(!isOksLeft[n-1]){
            for(ll i = n-2 ; i>= 1 ; i--){
                if(!isOksLeft[i]){
                    ujung2 = false;
                    break;
                }
            }
        }
        if(ujung1 || ujung2) ans = true;
    }
    // for(auto x : gcdFirst) cout << x << " ";
    // cout << endl;
    // for(auto x : gcdSecond) cout << x << " ";
    // cout << endl;

    // for(auto x : isOks) cout << x << " ";
    // cout << endl;
    // for(auto x : isOksLeft) cout << x << " ";
    // cout << endl;

    
    if(!ans) NO;
    if(ans) YES;
    
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