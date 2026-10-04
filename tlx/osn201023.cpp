#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {

    // Everything divides 0
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // If both numbers are equal
    if (a == b)
        return a;

    // If a is greater
    if (a > b)
      return gcd(a - b, b);


	// If b is greater
    return gcd(a, b - a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n ; cin >> n ; 
    vector <int> pangkat(100000);
    int res; cin >> res;
    for(int i = 1 ; i < n ; i++){
        int d ; cin >> d;
        res = (res * d)/(gcd(res,d));
    }
    cout << res << endl;
    return 0;
}