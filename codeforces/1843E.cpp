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

struct Segment{
    int a;
    int l;
    int r;
};

bool check(int M, const vector<int>& queries, const vector<Segment>& segments) {
    vector<int> current_q(queries.begin(), queries.begin() + M);
    sort(current_q.begin(), current_q.end());
    current_q.erase(unique(current_q.begin(), current_q.end()), current_q.end());
    for (const auto& seg : segments) {
        auto left = lower_bound(current_q.begin(), current_q.end(), seg.l);
        auto right = upper_bound(current_q.begin(), current_q.end(), seg.r);
        ll count = max(0LL, (ll)(right - left));
        if (seg.a + 2LL * count > 0) {
            return true;
        }
    }
    return false;
}
void solve(){
    int n,m ; cin >> n >> m;
    vector<int> qr;
    vector<Segment> seg;
    for(int i = 0 ; i < m ; i++){
        int l,r; cin >> l >> r;
        Segment ne = {l-r-1,l,r};
        seg.push_back(ne);
    }
    int q; cin >> q;
    for(int i = 0 ; i < q ; i++){
        int x; cin >> x;
        qr.push_back(x);
    }
    int low = 1;
    int high = q;
    int ans = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(check(mid,qr,seg)){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
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
