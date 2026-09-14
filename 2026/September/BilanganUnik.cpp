#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define vll vector<ll>
#define vint vector<int>
#define input(a,l,r) for(int i = l ; i < r ; i++) cin >> a[i];
#define REP(i,l,r) for(int i = l ; i < r ; i++)
#define REPLL(i,l,r) for(ll i = l ; i < r ; i++)
#define GK() ios::sync_with_stdio(false);cin.tie(nullptr)

int compute(int n){
    int ans = 1;
    while(n > 0){
        ans *= (n % 10);
        n = n/10;
    }
    return ans;
}

bool checkValid(ll n){
    ll tempN = n;
    while(tempN % 2 == 0) tempN /= 2;
    while(tempN % 3 == 0) tempN /= 3;
    while(tempN % 5 == 0) tempN /= 5;
    while(tempN % 7 == 0) tempN /= 7;
    return tempN == 1;

}

int main() {
    ll A; cin >> A;
    ll B ; cin >> B ;
    if(!checkValid(B)){
        cout << -1;
        return 0;
    }
    if(B > 100000){
        vector<int> ans;
        ll tempB = B;
        
        for(int d = 9; d >= 2; d--){
            while(tempB % d == 0){
                ans.push_back(d);
                tempB /= d;
            }
        }   
        if(tempB != 1){
            cout << -1;
            return 0;
        }
        
        sort(ans.begin(), ans.end());
        for(auto x : ans) cout << x;
    }
    else{
        // B <= A <= 1e5
        // 
        for(int cur = A+1 ; cur <= 3e6 ; cur++){
            int curVal = compute(cur);
            if(curVal >0 && curVal % B == 0){
                cout << cur;
                return 0;
            }
        }
        cout << -1;
    }
    return 0;
}
