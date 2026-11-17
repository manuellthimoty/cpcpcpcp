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


struct Point {
    ll x, y;
};
ll luas2(const vector<Point>& a) {
    int n = a.size();
    __int128 ans = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        ans += (__int128)a[i].x * a[j].y;
        ans -= (__int128)a[i].y * a[j].x;
    }
    if (ans < 0) ans = -ans;
    return ans;
}

int main() {
    GK();

    int n,k; cin >> n >> k;
    vector<Point> points(n+1);
    for(int i = 1 ; i < n+1 ; i++){
        ll x,y; cin >> x >> y;
        points[i] = {x,y};
    }
    vector<ll> pref(n+5,0);
    pref[3] = luas2({points[1],points[2],points[3]});
    for(int i = 4 ; i <= n ; i++){
        pref[i] = pref[i-1] + luas2({points[1],points[i-1],points[i]});
    }
     ll S = LLONG_MAX;
    auto hitungLuas = [&](int i1,int i2){
        ll maxS = max({pref[i1],pref[i2]-pref[i1],pref[n]-pref[i2]});
        ll minS = min({pref[i1],pref[i2]-pref[i1],pref[n]-pref[i2]});
        return maxS - minS;
    };
    for(int i = 3; i <= n-2 ; i++){
        int low = i;
        int high = n;
        ll target = pref[i] + (pref[n] - pref[i])/2;
        ll left = pref[i];
        auto it = lower_bound(pref.begin()+i+1,pref.begin()+n,target);
        auto id = it - pref.begin();
        if(id-1 > i) S = min(S,hitungLuas(i,id-1));
        if(id-2 > i) S = min(S,hitungLuas(i,id-2));
        if(id < n) S = min(S,hitungLuas(i,id));
        if(id +1 < n && id + 1 > i) S = min(S,hitungLuas(i,id+1));
        if(id +2 < n && id + 2 > i) S = min(S,hitungLuas(i,id+2));
    }
    // l1 l2
    // pref[l2] - pref[l1] = pref[n] - pref[l2]
    // 2*pref[l2] = pref[l1] + pref[n]
    // pref[l2] = pref
    if(S % 2 == 0){
        cout << S/2;
    }
    else{
        long double ans = S/2 + 0.5;
        cout << fixed << setprecision(7) <<  ans ;
    }


    return 0;
}
