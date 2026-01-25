#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    long long total = n * (n + 1) / 2;

    if (total % 2 != 0) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    long long target = total / 2;
    vector<int> set1, set2;

    for (int i = n; i >= 1; i--) {
        if (i <= target) {
            set1.push_back(i);
            target -= i;
        } else {
            set2.push_back(i);
        }
    }

    cout << set1.size() << endl;
    for (int x : set1) cout << x << " ";
    cout << "\n";

    cout << set2.size() << endl;
    for (int x : set2) cout << x << " ";
    cout << "\n";

    return 0;
}
