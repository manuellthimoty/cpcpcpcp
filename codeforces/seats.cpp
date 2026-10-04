#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    // n = s.length();
    ll ans = 0;
    ll countOne = 0;
    for(auto c : s){
        if(c == '1') countOne++;
    }
    // Cari posisi '1' pertama dan terakhir
    int firstOne = -1;
    int lastOne = -1;
    
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            if(firstOne == -1) firstOne = i;
            lastOne = i;
        }
    }

    if (firstOne == -1) {
        cout << (n + 2) / 3 << endl;
        return;
    }

    ll leadingZeros = firstOne; 
    ans += leadingZeros / 3;
    if (leadingZeros % 3 == 2) ans++;


    ll countzero = 0;
    for (int i = firstOne + 1; i <= lastOne; i++) {
        if (s[i] == '0') {
            countzero++;
        } else {
            // Kita menemukan '1' penutup celah
            ans += countzero / 3; // Rumus tengah murni bagi 3
            countzero = 0;
        }
    }

    // C. Hitung Trailing Zeros (Nol setelah '1' terakhir)
    ll trailingZeros = n - 1 - lastOne;
    ans += trailingZeros / 3;
    ans+= countOne;
    if (trailingZeros % 3 == 2) ans++;

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}