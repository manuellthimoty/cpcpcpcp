#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n; 
    cin >> n;

    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    vector<bool> visited(n+1, false);

    for(int i = 1; i <= n; i++){
        if(visited[i]) continue;

        vector<int> idx;
        vector<int> val;

        int cur = i;
        while(cur <= n){
            visited[cur] = true;
            idx.push_back(cur);
            val.push_back(a[cur]);
            cur *= 2;
        }

        sort(idx.begin(), idx.end());
        sort(val.begin(), val.end());

        for(int j = 0; j < idx.size(); j++){
            if(idx[j] != val[j]){
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
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
