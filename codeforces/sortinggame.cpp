    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;

    void solve(){
        int n ; cin >> n;
        string s; s.resize(n); cin >>s;
        int count1 = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == 1) count1++;
        }
        string sorted = s;
        sort(sorted.begin(),sorted.end());
        // for(int i = 0 ; i < n - count1 ; i++){
        //     sorted += '0';
        // }
        // for(int i = 0 ; i < count1; i++){
        //     sorted += '1';
        // }
        // cout << sorted << endl;
        if(sorted == s) cout << "Bob" << endl;
        else{
            vector<int> choose;
            for(int i = 0 ; i < n ; i++){
                if(s[i] != sorted[i]){
                    choose.push_back(i);
                }
            }
            cout << "Alice" << endl;
            cout << choose.size() << endl;
            for(auto x : choose){
                cout << x+1 << " ";
            }
            cout << endl;

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
