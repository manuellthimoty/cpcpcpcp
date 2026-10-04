    #include <bits/stdc++.h>
    using namespace std;
    using ll = long long;


    ll maxSubarraySum(vector<ll> &arr) {
        
        // Stores the result (maximum sum found so far)
        ll res = arr[0];           
        
        // Maximum sum of subarray ending at current position
        ll maxEnding = arr[0];     

        for (ll i = 1; i < arr.size(); i++) {
            
            // Either extend the previous subarray or start 
            // new from current element
            maxEnding = max(arr[i], maxEnding + arr[i]);

            // Update result if the new subarray sum is larger
            res = max(res, maxEnding);
        }
        return res;
    }


    void solve(){
        ll n, k ; cin >> n >> k;
        vector <ll> a(n),b(n);
        for(ll i = 0 ; i < n ; i++){
            cin >> a[i];
        }
        for(ll i = 0 ; i < n ; i++){
            cin >> b[i];
        }
        if(k%2 == 0){
            cout << maxSubarraySum(a) << endl;
            return ;
        }
        vector<ll> leftEnd(n);
        ll cur = LLONG_MIN;
        for(int i=0;i<n;i++){
            if(i==0) cur = a[i];
            else cur = max(a[i], cur + a[i]);
            leftEnd[i] = cur;
        }

        // Precompute max subarray sum starting at each index (rightStart)
        vector<ll> rightStart(n);
        for(int i=n-1;i>=0;i--){
            if(i==n-1) cur = a[i];
            else cur = max(a[i], cur + a[i]);
            rightStart[i] = cur;
        }
        ll base = maxSubarraySum(a);
        ll best = base; // at least original

        for(int i=0;i<n;i++){
            ll leftContrib = 0;
            if(i-1 >= 0) leftContrib = max(0LL, leftEnd[i-1]);
            ll rightContrib = 0;
            if(i+1 < n) rightContrib = max(0LL, rightStart[i+1]);

            ll candidate = (a[i] + b[i]) + leftContrib + rightContrib;
            best = max(best, candidate);
        }
        cout << best << endl;
    }


    int main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int t; cin >> t;
        while(t--){
            solve();
        }
    }
