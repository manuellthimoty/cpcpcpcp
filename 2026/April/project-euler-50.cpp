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

int n=1e6;
vector<bool> is_prime(n+1, true);
void build_sieve() {
    is_prime[0] = false; is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}
bool findPair(int a[], int n, int x) {
    int kiri = 0;
    int kanan = 1;

    while (kanan < n && kiri < n) {
        int diff = a[kanan] - a[kiri];

        if (diff == x && kiri != kanan) {
            cout << "Ditemukan: i = " << kanan << ", j = " << kiri << endl;
            return true;
        }
        else if (diff < x) {
            kanan++;
        }
        else {
            kiri++;
        }

        // Pastikan pointer tidak menunjuk elemen yang sama jika x != 0
        if (kiri == kanan) kanan++;
    }

    return false;
}
void solve() {
    vector<int> primes;
    for(int i = 2; i <= n; i++) {
        if(is_prime[i]) primes.push_back(i);
    }

    int len = primes.size();
    vector<ll> pref(len + 1, 0);
    for(int i = 0; i < len; i++) pref[i+1] = pref[i] + primes[i];

    ll ans = 0;
    int mxlen = 0;

    // i adalah titik awal deret prima
    for(int i = 0; i < len; i++) {
        // j adalah titik akhir deret
        // Kita mulai j dari yang memberikan panjang lebih besar dari mxlen
        for(int j = i + mxlen + 1; j <= len; j++) {
            ll sum = pref[j] - pref[i];
            
            if(sum > n) break; // Optimasi paling penting!

            if(is_prime[sum]) {
                mxlen = j - i;
                ans = sum;
            }
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    build_sieve();

    int t=1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
