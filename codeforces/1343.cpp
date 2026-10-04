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
    int n,k ; cin >> n >> k;
    vector<int> a(n+1);
    for(int i = 1; i <= n ; i++) cin >> a[i];
    vector<pair<int,int>> seg;
    for(int i = 1; i <= n/2 ; i++){
        int left = a[i];
        int right = a[n-i+1];
        int mn = min(1+right,1+left);
        int mx = max(k+left,k+right);
        mx++;
        seg.push_back({mn,1});
        seg.push_back({mx,-1});

        int sum = left + right;
        seg.push_back({sum, 1});
        seg.push_back({sum + 1, -1});
    }
    sort(seg.begin(),seg.end());
    int mn = n;
    int cur_c = 0;
    for(int i = 0 ; i <seg.size() ;){
        int curr = seg[i].first;
        while(i < seg.size() && seg[i].first == curr){
            cur_c += seg[i].second;
            i++;
        }
        int skor = n - cur_c;
        mn = min(mn,skor);
    }
    cout << mn << endl;
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
