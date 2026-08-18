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


vector<int> a;
int n;
ll K;

vector<ll> pref;


bool check(ll d){
    for(int i = 0 ; i < n ; i++){
        // case 1 : L = a[i], R = a[i] + k
        ll l = a[i];
        ll r = l + d;

        ll costL = 1LL*  l * i - pref[i];

        int p = upper_bound(a.begin(), a.end(), r) - a.begin();
        ll costR = (pref[n] - pref[p]) - 1ll * (n - p) * r;
        if (costL + costR <= K) return true;

        r = a[i];
        l = r - d;

        costR = (pref[n] - pref[i + 1]) - 1ll * (n - i - 1) * r;
        p = lower_bound(a.begin(), a.end(), l) - a.begin();
		costL = 1ll * p * l - pref[p];
        if (costL + costR <= K) return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> K;
    a.resize(n);
    for(int i = 0 ;i < n ; i++) cin >> a[i];
    sort(a.begin(),a.end());
    ll low = 0;
    ll high = a[n-1] - a[0];
    ll ans = high;
    pref.resize(n+1,0);
    pref[0] = 0;
    for(int i = 0; i < n ; i++) pref[i+1] = pref[i] + a[i];
    
    while(low <= high){
        ll mid = low + (high-low)/2;
        if(check(mid)){
            ans = min(ans,mid);
            high = mid-1;
        }
        else low = mid+1;
    }
    cout << ans << '\n';


    return 0;
}
