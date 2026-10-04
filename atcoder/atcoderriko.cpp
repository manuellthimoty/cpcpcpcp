
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int64> A(N);
    int64 S = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        S += A[i];
    }

    sort(A.begin(), A.end());

    int64 maxA = A.back();

    vector<int64> candidates;

    // Cari semua divisor S
    for (int64 d = 1; d * d <= S; d++) {
        if (S % d == 0) {
            candidates.push_back(d);
            if (d * d != S)
                candidates.push_back(S / d);
        }
    }

    vector<int64> answer;

    for (int64 L : candidates) {

        if (L < maxA) continue;

        int64 k = S / L;
        if (k > N) continue;

        int l = 0, r = N - 1;
        bool ok = true;

        while (l <= r) {
            if (A[r] > L) {
                ok = false;
                break;
            }

            if (A[r] == L) {
                r--;
            } else {
                if (A[l] + A[r] == L) {
                    l++;
                    r--;
                } else {
                    ok = false;
                    break;
                }
            }
        }

        if (ok) answer.push_back(L);
    }

    sort(answer.begin(), answer.end());

    for (auto L : answer)
        cout << L << "\n";

    return 0;
}