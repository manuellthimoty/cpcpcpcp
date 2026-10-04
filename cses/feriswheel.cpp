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
    int n,x ;  cin >> n >> x;
    vector<int> p(n);
    for(int i = 0 ; i < n ; i++) cin >> p[i];
    sort(p.begin(),p.end());
    reverse(p.begin(),p.end());
    int count = 0;
    int cur  = 0;
    int ans = 0;
    vector<bool> done(n,false);
    while(count < n){
        while(cur < n && done[cur]) cur++;
        if(cur >= n) break;

        done[cur] = true;
        count++;

        int sisa = x - p[cur];

        int start = cur+1;
        int end = n-1;
        int best = -1;

        while(start <= end){
            int mid = start + (end- start)/2;
            if(p[mid] > sisa){
                start = mid +1;
            }
            else{
                best = mid;
                end = mid - 1;
            }
        }

        if(best != -1){
            while(best < n && done[best]) best++;
            if(best < n&& p[best] <= sisa){
                done[best] = true;
                count++;
            }
        }
        ans++;
    }
    cout << ans << endl;
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
