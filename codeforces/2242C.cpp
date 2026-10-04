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
    ll n,k ; cin >> n >> k;
    map<ll,ll> freq;
    for(int i = 0 ; i <n ; i++){
        ll x ; cin >> x;
        freq[x]++;
    }
    vector<ll> cntFreq(n+1,0);
    ll maxFreq = 0;
    for(auto const& [val,f] : freq){
        cntFreq[f]++;
        maxFreq = max(maxFreq,f);
    }
    vector<ll> M(n+2,0);
    ll curr = 0;
    for(ll i = n ; i >= 1 ; i--){
        curr += cntFreq[i];
        M[i] = curr;
    }
    ll ans =0;
    ll currentN = n;
    for(ll step = 1 ; step <= maxFreq ; step++){
        ll currM = M[step];
        bool isLastInBlock = (step == maxFreq) || (M[step + 1] != currM);
        
        if(isLastInBlock) {
            if(currM == 0){
                if(currentN == k) ans++;
            }
            else{
                if(k >= currentN && (k - currentN) % currM == 0){
                    ans++;
                }
            }
        }
        
        currentN -= currM;
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
