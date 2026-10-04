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
int gcd(int a,int b){
    if(a == 0) return b;
    if(b == 0) return a;
    return gcd(b,a%b);
}

int lcm(int a, int b){return (a/gcd(a,b)) * b;}
void solve(){
    int n; cin >> n;
    
    vector<int> a(n);
    vector<int> b(n);
    input(a,0,n);
    input(b,0,n);
    for(int i = 1; i < n - 1; i++){
        int left = gcd(a[i-1],a[i]);
        int right = gcd(a[i],a[i+1]);
        int set = lcm(left,right);
        if(set!= a[i] && set <= b[i] && gcd(a[i-1],set) == left && gcd(set,a[i+1]) == right){
            a[i] = set;
        }
    }
    // cek untuk a[0]
    int setfirst = gcd(a[0],a[1]);
    if(setfirst < b[0]){
        a[0] = setfirst;
    }
    int setlast = gcd(a[n-2],a[n-1]);
    if(setlast < b[n-1]){
        a[n-1] = setlast;
    }
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        if(a[i] != b[i]) ans++;
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
