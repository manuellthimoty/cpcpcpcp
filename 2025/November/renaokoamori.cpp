#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n+1), b(n+1);

        int A0 = 0, B0 = 0;
        for (int i = 1; i <= n; i++) cin >> a[i], A0 ^= a[i];
        for (int i = 1; i <= n; i++) cin >> b[i], B0 ^= b[i];

        
        int lastDiff = -1;
        for (int i = 1; i <= n; i++) {
            if (a[i] != b[i]) lastDiff = i;
        }

        if (lastDiff == -1) {
            if (A0 > B0) cout << "Ajisai\n";
            else if (B0 > A0) cout << "Mai\n";
            else cout << "Tie\n";
            continue;
        }
        int K = A0 ^ B0; 
        if (K == 0) {
            
            cout << "Tie\n";
        } else {
            if (lastDiff % 2 == 1) cout << "Ajisai" <<endl;
            else {
                cout << "Mai\n";
            }
        }
    }
    return 0;
}
