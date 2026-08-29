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

int pow (int a, int b) {
    int res = 1;
    while (b)
        if (b & 1)
            res = int (res * 1ll * a),  --b;
        else
            a = int (a * 1ll * a),  b >>= 1;
    return res;
}


const int mxA = 1e5;
int spf[mxA + 1];

void init() {
    for (int i = 2; i <= mxA; i++) spf[i] = i;
    for (int i = 2; i * i <= mxA; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= mxA; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

int sederhanain(int nums, int k){
    int res = 1;
    while(nums > 1){
        int curFac = spf[nums];
        int cnt = 0;
        while(nums % curFac == 0){
            nums/=curFac;
            cnt++;
        }
        cnt %= k;
        res *= pow(curFac,cnt);
    }
    return res;
}
pair<ll, ll> get_val_and_need(int num, int k) {
    ll val = 1;
    ll need = 1;
    bool overflow = false;

    while (num > 1) {
        int p = spf[num];
        int cnt = 0;
        while (num % p == 0) {
            cnt++;
            num /= p;
        }
        cnt %= k;
        
        if (cnt > 0) {
            for (int j = 0; j < cnt; j++) val *= p;
            
            int req = k - cnt;
            for (int j = 0; j < req; j++) {
                need *= p;
                if (need > mxA) {
                    overflow = true;
                }
            }
        }
    }

    if (overflow) need = -1; 
    return {val, need};
}
void solve(){
    int n, k;
    if (!(cin >> n >> k)) return;

    map<ll, int> freq;
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        auto [val, need] = get_val_and_need(x, k);

        if (need != -1 && freq.count(need)) {
            ans += freq[need];
        }

        freq[val]++;
    }

    cout << ans << "\n";
}
int main() {
    GK();
    init();
    solve();

    return 0;
}
