#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long r, x, y, x2, y2;
    if(!(cin >> r >> x >> y >> x2 >> y2)) return 0;
    long double dx = (long double)(x2 - x);
    long double dy = (long double)(y2 - y);
    long double dist = sqrtl(dx*dx + dy*dy);
    if (dist < 1e-15L) {
        cout << 0 << '\n';
        return 0;
    }
    long double step_len = 2.0L * r;
    long long ans = (long long) ceill(dist / step_len - 1e-15L);
    cout << ans << '\n';
    return 0;
}
