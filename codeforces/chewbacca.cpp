#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x ; cin >> x;
    string n = to_string(x);
    int len = n.size();
    for(int i = 0 ; i < len ; i++){
        int curdig = n[i] - '0';
        int choose = curdig;
        if(i != 0){
            choose = min(curdig, 9 -curdig);
        }
        else{
            if(curdig != 9){
                choose = min(curdig,9-curdig);
            }
        }
        n[i] = '0' + choose;
    }
    cout << n << endl;
    return 0;
}