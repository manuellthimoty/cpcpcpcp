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
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i =1 ; i <= n ; i++) cin >> a[i];
    int id = -1;
    int mx = -1;
    for(int i =1 ; i < n ; i++){
        int selisih = abs(a[i] - a[i+1]);
        if(selisih > mx){
            mx = selisih;
            id = i;
        }
    }
    vector<int> pref(n+1); // pref[i] = max until index i (a[i-1] - a[i])
    pref[2] = abs(a[1] - a[2]);
    for(int i = 3; i <= n ; i++){
        pref[i] = max(pref[i-1],abs(a[i-1]-a[i]));
    }
    vector<int> suf(n+2);
    for(int i = n-1 ; i >= 1 ; i--){
        suf[i] = max(suf[i+1],abs(a[i]-a[i+1]));
    }

    int curmx = 0;
    int ans = pref[n];

    for(int i = id ; i >= 1 ; i--){
        if(i < id){
            curmx = max(curmx,2*abs(a[i+1]-a[i]));
        }
        int leftmx = pref[i-1];
        int rightmx = suf[id+1];
        int midmx = 0;
        if(i > 1){
            midmx = abs(a[i-1] - 2*a[id]);
        }
        int midmx2 = abs(2*a[i] - a[id+1]);
        ans = min(ans,max({curmx,leftmx,rightmx,midmx,midmx2}));
    }

    curmx = 0;

    for(int i = id+1 ; i <= n ; i++){
        if(i > id+1){
            curmx = max(curmx,2*abs(a[i]-a[i-1]));
        }

        int leftmx = pref[id];
        int rightmx = suf[i+1];

        int midmx = abs(a[id] - 2*a[i]);

        int midmx2 = 0;
        if(i < n){
            midmx2 = abs(2*a[id+1] - a[i+1]);
        }
        ans = min(ans,max({curmx,leftmx,rightmx,midmx,midmx2}));
    }
    cout << ans << '\n';
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
