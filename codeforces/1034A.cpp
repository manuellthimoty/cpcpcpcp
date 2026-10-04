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

const int mxA = 15000000;
int spf[mxA + 1];
vector<int> primes;

void init() {
    for (int i = 2; i <= mxA; i++) spf[i] = i;
    for (int i = 2; i * i <= mxA; i++) {
        if (spf[i] == i) {
            // primes.push_back(i);
            for (int j = i * i; j <= mxA; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

int gcd(int a, int b){
    if(a == 0) return b;
    if(b == 0) return a;
    return gcd(b, a %b);
}

int main() {
    GK();
    init();
    int n ; cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    int d = a[0];
    bool oks = false;

    for(int i = 1 ; i < n ; i++){
        if(a[i] != a[0]){
            oks = true;
            break;
        }
    }

    if(!oks){
        cout << -1;
        return 0;
    }
    for(int i = 1 ; i < n ; i++){
        d = gcd(d,a[i]);
    }
    for(int i = 0 ; i < n ; i++){
        a[i] /= d;
    }
    map<int,int> cnt;
    for(int i = 0 ; i < n ; i++){
        int cur = a[i];
        while(cur > 1){
            int curPrime = spf[cur];
            cnt[curPrime]++;
            while(cur % curPrime == 0) cur /= curPrime;
        }
    }

    int mx = 0;
    for(auto d : cnt){
        mx = max(mx,d.second);
    }
    int ans = n - mx;
    cout << ans;

    return 0;
}
