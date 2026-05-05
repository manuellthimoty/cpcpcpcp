#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define YES cout << "YA" << endl;
#define NO cout << "TIDAK" << endl;
#define vll vector<ll>
#define vint vector<int>
#define input(a,l,r) for(int i = l ; i < r ; i++) cin >> a[i];
#define REP(i,l,r) for(int i = l ; i < r ; i++)
#define REPLL(i,l,r) for(ll i = l ; i < r ; i++)

void solve(){
    int n,l ; cin >> n >> l;
    vector<int> B(n+1,0);
    for(int i = 1; i <= n ; i++){
        cin >> B[i];
    }
    vector<int> D(l+1),M(l+1);
    for(int i = 1 ; i <= l ; i++){
        cin >> D[i] >> M[i];
    }
    vector<int> pref(n+1,0);
    pref[1] = B[1];
    for(int i =2 ; i <= n ; i++) pref[i] = pref[i-1] + B[i];

    vector<int> days;
    for(int i = 1 ; i <= l ; i++){
        int nums = pref[M[i]-1] + D[i];
        days.push_back(nums);
    }
    sort(days.begin(),days.end());
    for(int i = 0 ; i < days.size() - 1 ; i++){
        if(days[i+1] - days[i] == 2){
            YES
            return;
        }
    }
    NO
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
