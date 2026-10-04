#include <bits/stdc++.h>
using namespace std;

long long combinations(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n / 2) r = n - r;
    
    long long res = 1;
    for (int i = 0; i < r; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n ; cin >> n ; 
    if(n < 3){
        cout << 0 << endl;
        return 0;
    }
    cout << combinations(n, 3) << endl;
    
    return 0;
}