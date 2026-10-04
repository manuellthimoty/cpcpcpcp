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
const int MAXA = 1e6+ 5;
int spf[MAXA];
int parent_node[MAXA];

void sieve() {
    for (int i = 1; i < MAXA; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i < MAXA; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXA; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

int findSet(int v){
    if(v == parent_node[v])return v;
    return findSet(parent_node[v]);
}

void unionSet(int a, int b){
    a = findSet(a);
    b = findSet(b);
    if(a != b){
        parent_node[b] = a;
    }
}
void solve(){
    int n ; cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    vector<int> f(1e6+1);
    for(auto x : a) f[x]++;
    for(int i = 1 ; i < MAXA ; i++){
        parent_node[i] = i;
    }
    for (int i = 0; i < n; i++) {
        int val = a[i];
        if (val == 1) continue;

        int first_prime = -1;
        while (val > 1) {
            int p = spf[val];
            if (first_prime == -1) {
                first_prime = p;
            } else {
                unionSet(first_prime, p);
            }
            
            while (val % p == 0) {
                val /= p;
            }
        }
    }

    vector<int> components(MAXA,0);
    for(int i = 0 ; i < n ; i++){
        int cur = a[i];
        if(cur == 1) continue;

        int root = findSet(spf[a[i]]);
        components[root]++;
    }
    ll ans = 0;
    for(int i = 1; i < MAXA ; i++){
        if(components[i] <= 1) continue;
        ll k = components[i];
        ans += (k * (k-1))/2;
    }
    cout << ans << endl;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    int t=1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
