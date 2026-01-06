#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool is_power_of_2(ll n) {
    if (n <= 0) {
        return false;
    }
    return (n & (n - 1)) == 0;
}
bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i *i<=n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}
void solve() {
    ll n ; cin >> n ;
    if(n == 1){
        cout << "FastestFinger" << endl;
        return;
    }
    if(n==2){
        cout << "Ashishgup" << endl;
        return;
    }
    if(n % 2 == 1){
        cout << "Ashishgup" << endl;
        return;
    }
    else{
        if(is_power_of_2(n)){
            cout << "FastestFinger" <<endl;
            return;
        }
        ll highesttwo = n - (n & (n-1));
        ll odd = n/highesttwo;
        if(highesttwo == 2){
            if(isPrime(odd)){
                cout << "FastestFinger" << endl;
                return;
            }
            else{
                cout << "Ashishgup" << endl;
                return;
            }
        }
        else{
            cout << "Ashishgup" << endl;
            return;
        }
    }

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