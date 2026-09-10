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

// 1011        00010111

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    string s; s.resize(n); cin >> s;
    // pair<type,cnt>
    deque<pair<int,int>> dq;
    
    bool streak0 = false;
    bool streak1 = false;
    int cntstreak0 = 0;
    int cntstreak1 = 0;

    int total0 = 0;
    int total1 = 0;
    for(int i = 0 ; i < n ; i++){
        if(a[i] == 0){
            if(streak0){

            }
        }
    } 
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
