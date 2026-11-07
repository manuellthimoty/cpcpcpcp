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


void printArr(vector<vector<ll>>& arr){
    int n = arr.size();
    int m = arr[0].size();
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < m ; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void solve(){
    int n ; cin >> n;
    int q; cin >> q;
    vector<pair<ll,ll>> recs(n);
    int mxh = 0;
    int mxw = 0;
    for(int i = 0 ;i < n ; i++){
        int h,w; cin >> h >> w;
        recs[i] = {h,w};
        mxh = max(mxh,h);
        mxw = max(mxw,w);
    }
    mxh = 1000;
    mxw = 1000;
    vector<vector<ll>> blocks(mxh+1,vector<ll>(mxw+1,0));
    for(auto r : recs){
        int h = r.first;
        int w = r.second;
        blocks[h][w] += h * w;
    }

    vector<vector<ll>> pref(mxh+1,vector<ll> (mxw+1,0));
    for (int i = 0; i < mxh+1; i++) {
        for (int j = 0; j < mxw+1; j++) {

            pref[i][j] = blocks[i][j];

            if (i > 0)
                pref[i][j] += pref[i - 1][j];

            if (j > 0)
                pref[i][j] += pref[i][j - 1];
            if (i > 0 && j > 0)
                pref[i][j] -= pref[i - 1][j - 1];
        }
    }
    while(q--){
        int hs,ws,hb,wb; cin >> hs >> ws >> hb >> wb;
        
        ll ans = pref[hb-1][wb-1]-pref[hb-1][ws]-pref[hs][wb-1]+pref[hs][ws];
        cout << ans << '\n';
    }
    // printArr(blocks);
    // cout << endl;
    // printArr(pref);
    
    

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
