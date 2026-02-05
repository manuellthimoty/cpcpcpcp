#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl

void solve() {
    string a,b ; cin >> a >> b;
    stack<char> reduceA;
    ll sizeA = a.size();
    ll sizeB = b.size();
    for(ll i = sizeA-1 ; i>= 0;i--){
        if(!reduceA.empty() &&  reduceA.top() == 'P' && a[i] == 'N'){
            continue;
        }
        else{
            reduceA.push(a[i]);
        }
    }
    stack<char> reduceB;
    for(ll i = sizeB-1 ; i >= 0 ; i--){
        if(!reduceB.empty() &&  reduceB.top() == 'P' && b[i] == 'N'){
            continue;            
        }
        else{
            reduceB.push(b[i]);
        }
    }
    ll lenA = reduceA.size();
    ll lenB = reduceB.size();
    if(lenA == lenB){
        while(!reduceA.empty()){
            if(reduceA.top() != reduceB.top()){
                NO;
                return;
            }
            reduceA.pop();
            reduceB.pop();
        }
        YES;
        return;
    }
    NO;
    return;
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