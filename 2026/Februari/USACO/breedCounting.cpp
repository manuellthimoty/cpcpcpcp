#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("bcount.in", "r", stdin);
    int n,q; cin >> n >> q;
    vector<int> a(n+1,0);
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    vector<int> countone(n+1,0);
    vector<int> counttwo(n+1,0);
    vector<int> countthree(n+1,0);
    for(int i = 1 ; i <= n ; i++){
        countone[i] = countone[i-1];
        counttwo[i] = counttwo[i-1];
        countthree[i] = countthree[i-1];
        if(a[i] == 1) countone[i]++;
        if(a[i] == 2) counttwo[i]++;
        if(a[i] == 3) countthree[i]++;
    }
    freopen("bcount.out", "w", stdout);
    for(int i = 0 ; i < q ; i++){
        int a,b ; cin >> a >> b;
        int first = countone[b] - countone[a-1];
        int second = counttwo[b] - counttwo[a-1];
        int third = countthree[b] - countthree[a-1];
        cout << first << " " << second << " " << third;
        cout << endl;
    }


    return 0;
}