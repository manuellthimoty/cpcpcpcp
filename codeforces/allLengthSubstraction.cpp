#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n ; cin >> n;
    vector<int> a(n+1,0);
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    map<int,int> index;
    vector<bool> visited(n+1);
    visited[0] = true;
    int sum = 0;
    for(int i = 1 ; i <= n ; i++){
        index[a[i]] = i;
        sum += a[i];
    }

    int leftIndex = index[n];
    int rightIndex = leftIndex+1;
    int curValue = n;
    a[leftIndex] -= 0;
    leftIndex--;
    curValue --;
    bool ans = true;
    while(ans){
        bool found = false;
        if(a[leftIndex] == curValue && leftIndex >=1){
            a[leftIndex] = 0;
            curValue--;
            leftIndex--;
            found = true;
        }
        if(a[rightIndex] == curValue && rightIndex <= n){
            a[rightIndex] = 0;
            rightIndex ++;
            curValue--;
            found = true;
        }
        if(!found){
            if (leftIndex == 0 && rightIndex == n+1){
                break;
            } 
            else ans = false;
        }

    }
    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;
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