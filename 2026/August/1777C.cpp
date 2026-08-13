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
    int n, m ; cin >> n >> m;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    n = a.size();

    vector<int> freq(m + 1, 0);
    int covered = 0;
    int ans = 2e9;
    int L = 0;

    for(int R = 0 ; R < n ; R++){
        int valR = a[R];
        
        for(int j = 1 ; j * j <= valR ; j++){
            if(valR % j == 0){
                if(j <= m){
                    if(freq[j] == 0) covered++;
                    freq[j]++;
                }
                int pasangannya = valR / j;
                if(pasangannya != j && pasangannya <= m){
                    if(freq[pasangannya] == 0) covered++;
                    freq[pasangannya]++;
                }
            }
        }

        while(covered == m){
            ans = min(ans, a[R] - a[L]); // Simpan jawaban terbaik

            int valL = a[L];
            for(int j = 1 ; j * j <= valL ; j++){
                if(valL % j == 0){
                    if(j <= m){
                        freq[j]--;
                        if(freq[j] == 0) covered--;
                    }
                    int pasangannya = valL / j;
                    if(pasangannya != j && pasangannya <= m){
                        freq[pasangannya]--;
                        if(freq[pasangannya] == 0) covered--;
                    }
                }
            }
            L++;
        }
    }

    if(ans == 2e9) cout << -1 << "\n";
    else cout << ans << "\n";
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
