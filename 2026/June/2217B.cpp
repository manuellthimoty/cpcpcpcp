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
    int n ; cin >> n;
    int k ; cin >> k;
    vector<int> a(n+2);
    for(int i = 1 ; i<= n ; i++) cin >> a[i];
    int special; cin >> special;
    if(n == 1){
        cout << 0 << endl;
        return;
    }
    int cur = 0;
    vector<int> cnt(n+2);
    bool reversed = false;
    if(a[special] == 1) reversed = true;

    if(reversed){
        for(int i = 1 ; i <= n ; i++){
            a[i]++;
            a[i] %= 2;
        }
    }
    for(int i = 1 ; i < special ; i++){
        if(a[i] == 0){
            //genap
            if(cur % 2 == 1) cur++;
            cnt[i] = cur;
        }
        else{
            // ganjil
            if(cur % 2 == 0) cur++;
            cnt[i] = cur;
        }
    }
    cur = 0;
    for(int i = n ; i > special ; i--){
        if(a[i] == 0){
            // genap
            if(cur % 2 == 1) cur++;
            cnt[i] = cur;

        }
        else{
            // ganjil
            if(cur % 2 == 0) cur++;
            cnt[i] = cur;
        }
    }
    
    if(special == 1){
        int cand = cnt[special+1];
        if(a[special] == 0){
            if(cand % 2 == 1) cand++;
            cout << cand << endl;
        }
        else{
            if(cand % 2 == 0) cand++;
            cout << cand << endl;
        }
        return;
    }
    if(special == n){
        int cand = cnt[special-1];
        if(a[special] == 0){
            if(cand % 2 == 1) cand++;
            cout << cand << endl;
        }
        else{
            if(cand % 2 == 0) cand++;
            cout << cand << endl;
        }
        return;
    }
    int cand1 = cnt[special-1];
    int cand2 = cnt[special+1];
    if(a[special] == 0){
        // cand harus genap
        cand1 = cand1 + cand1 % 2;
        cand2 = cand2 + cand2 % 2;
        cout << max(cand1,cand2) << endl;
    }
    else{
        // kandidat harus ganjil
        if(cand1 % 2 == 0) cand1++;
        if(cand2 % 2 == 0) cand2++;
        cout << max(cand1,cand2) << endl;
    }
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
