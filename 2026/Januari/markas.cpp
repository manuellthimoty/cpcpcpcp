#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long get_min_cost(int count, int space_left, int space_right) {
    if (count == 1) return 0; 

    int needed = count - 1;
    int l_ideal = needed / 2;
    int l_take = min(l_ideal, space_left);

    int r_take = needed - l_take;

    if (r_take > space_right) {
        int overshoot = r_take - space_right;
        r_take = space_right;
        l_take += overshoot;
    }
    long long cost = 2LL * max(l_take, r_take) + min(l_take, r_take);
    
    return cost;
}

void solve() {
    int n, k;
    long long m; 
    cin >> n >> m >> k;

    int space_left = k - 1;
    int space_right = n - k;

    int ans = 1;

    for (int target = 2; target <= n; target++) {
        long long cost = get_min_cost(target, space_left, space_right);

        if (cost <= m + 1) {
            ans = target;
        } else {
            break;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}