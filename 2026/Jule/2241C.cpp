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
    string s; s.resize(n);
    cin >> s;
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    // 101010 -> 1
    // 0101010 -> 
    // 10101
    // 01010
    // 010
    // 10
    // 1111100000
    int cnt1 = 0;
    int cnt0 = 0;
    int first = s[0] - '0';
    int cur_streak = 0;
    if(first == 1) cur_streak = 1;
    if(first == 1) cnt1++;
    else cnt0++;
    for(int i = 1 ; i < n ; i++){
        int cur = s[i] - '0';
        if(cur == cur_streak) continue;
        else{
            cur_streak = cur;
            if(cur == 1) cnt1++;
            else cnt0++;
        }
    }
    if(cnt1 == 1 && cnt0 == 1){
        cout << 2 << endl;
    }
    else cout << 1 << endl;
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
