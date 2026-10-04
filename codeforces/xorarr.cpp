#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    int p_prev = 0;
    int p_curr = 0;

    for (int i = 1; i <= n; i++) {
        if (i == r) {
            p_curr = l - 1;
        } else {
            p_curr = i;
        }

        int val = p_curr ^ p_prev;
        cout << val << (i == n ? "" : " ");
        p_prev = p_curr;
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}