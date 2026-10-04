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


int main() {
    GK();

    int n ; cin >> n;
    vector<int> a(n+1);
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    map<int,int> cnt;
    bool flag = false;
    for(int i = 1 ; i < n ; i++){
        
        if(i > 1 && i < n && a[i+1] == a[i-1] && !flag) {
            flag = true;
            continue;
        }
        int cur = a[i] + a[i+1];
        cnt[cur]++;
        if(flag){
            flag = false;
        }
    }
    int ans = 0;
    for(auto x : cnt){
        ans = max(ans,x.second);
    }
    cout << ans;

    return 0;
}
