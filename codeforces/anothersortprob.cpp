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
    vector<int> a(n+1);
    for(int i = 1; i <= n ; i++) cin >> a[i];
    vector<int> diff(n+1);
    if(n == 1 || n == 2){
        YES
        return;
    }
    diff[0] = 0;
    diff[1] = a[1];
    for(int i = 2; i <= n ; i++){
        diff[i] = a[i] - a[i-1];
    }
    int k = 0;
    for(int i = 2; i <= n ; i++){
        if(diff[i] < 0){
            k = max(k,abs(diff[i]));
        }
    }
    vector<bool> done(n+1,false);
    for(int i = 2 ; i <= n ; i++){
        if(diff[i] < 0){
            done[i] = true;
            a[i] += k;
        }
    }
    bool sorted = true;
    for(int i = 1 ; i <= n-1 ; i++){
        if(a[i] > a[i+1]){
            sorted = false;
            break;
        }
    }
    if(sorted){
        YES
        return;
    }
    for(int i = 2; i <= n ; i++){
        if(a[i] < a[i-1]){
            if(!done[i]){
                a[i] +=k;
                done[i] = true;
            }
            else{
                NO
                return;
            }
        }
    }
    YES
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
