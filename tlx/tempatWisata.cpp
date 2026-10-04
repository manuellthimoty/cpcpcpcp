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
/*4 5
2 3
1 2
3 4
5 5
*/
// [1,2], [2,3],[3,4],[5,5]

// misal 2 blok Ai Bi dan Aj Bj 'terhubung'  jika :
// Jika Ai > Aj, maka haruslah Bj >= Ai
// Jika Ai < Aj, haruslah Bi >= Aj

// sort berdasarkan A shg A[i] <= A[i+1]
// maka untuk setiap i kita jari Aj > Ai sehingga Aj <= Bi dengan j semaksimum mungkin maka banyaknya ans += j - i
// definisikan array diff[i] = a[i] - a[i-1]
// kita punya a[i] = diff[0] + diff[1] + .. + diff[i]
// misal kita mau ubah nilai di indeks l hingga r supaya + k, maka
// maka diff[l] = k
// diff[r+1] -=k
void solve(){
    int n,m ; cin >> n >> m;
    vector<pair<int,pair<int,int>>> t(n);
    for(int i = 0 ; i < n ; i++){
        int a,b; cin >> a >> b;
        t[i] = {a,{b,i}};
    }
    ll ans = 0;
    sort(t.begin(),t.end());
    vector<int> diff(n+1,0);
    vector<int> cnt(n,0);
    for(int i = 0 ; i < n ; i++){
        int low = i;
        int high = n-1;
        ll idxmax = i;
        int threshold = t[i].second.first;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(t[mid].first > threshold){
                high = mid-1;
            }
            else{
                low = mid+1;
                idxmax = max(idxmax,(ll)mid);
            }
        }
        ans += idxmax - i;
        cnt[i] = idxmax - i;
        if(idxmax >= i){
            // maka semua di i+1,i+2,...,idxmax harus ditambah +1
            diff[i+1] ++;
            diff[idxmax+1] -- ;
        }
    }
    vector<int> final(n);
    vector<int> pref(n+1);
    pref[0] = 0;
    for(int i = 1; i <= n ; i++){
        pref[i] = pref[i-1] + diff[i]; // pref[i] = tambahan[i]
    }
    for(int i = 0 ; i < n ; i++){
        int curidx = t[i].second.second;
        final[curidx] = cnt[i] + pref[i];
    }
    for(int i = 0 ; i < n ; i++){
        cout << final[i] << endl;
    }
    // cout << ans << endl;
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
