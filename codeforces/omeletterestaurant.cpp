#include <bits/stdc++.h>
using namespace std;


void solve(){
    int N, D;
    cin >> N >> D;

    vector<long long> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    queue<pair<int, long long>> q; 
    for (int i = 0; i < N; i++) {
        int day = i + 1;
        q.push({day, A[i]});
        long long need = B[i];
        while (need > 0) {
            auto &front = q.front();
            if (front.second <= need) {
                need -= front.second;
                q.pop();
            } else {
                front.second -= need;
                need = 0;
            }
        }

        while (!q.empty() && day - q.front().first + 1 >= D) {
            q.pop();
        }
    }

    long long answer = 0;
    while (!q.empty()) {
        answer += q.front().second;
        q.pop();
    }

    cout << answer << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 3;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}