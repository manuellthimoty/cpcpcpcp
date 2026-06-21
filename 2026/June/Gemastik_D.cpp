#include <bits/stdc++.h>
using namespace std;

long long x[200005], y[200005], c[200005], dist, gcd, arah, fpb, n, q, cnt[200005], res, a;
bool aktif[200005];
string s;

map<pair<long long, long long>, set<pair<long long, int>>> mp;

main()
{
    cin >> n >> q;
    cin >> s;
    for (int i = 0; i < n; i++){
        cin >> x[i] >> y[i] >> c[i];
        dist = x[i] * x[i] + y[i] * y[i];
        fpb = __gcd(abs(x[i]), abs(y[i]));
        pair<long long, long long>arah = {x[i]/fpb, y[i]/fpb};
        if (s[i] == '1'){
            aktif[i] = true;
            mp[arah].insert({dist, i});
        }
        else {
            aktif[i] = false;
        }
    }

    for (auto i : mp){
        if (!i.second.empty()){
            int j = i.second.begin()->second;
            cnt[c[j]]++;
            if (cnt[c[j]] == 1){
                res++;
            }
        }
    }

    while (q--){

        cin >> a;
        a--;
        dist = x[a] * x[a] + y[a] * y[a];
        fpb = __gcd(abs(x[a]), abs(y[a]));

        pair<long long, long long>arah = {x[a]/fpb, y[a]/fpb};

        if (!mp[arah].empty()){
            int j = mp[arah].begin()->second;
            cnt[c[j]]--;
            if (cnt[c[j]] == 0){
                res--;
            }
        }

        if (aktif[a]){
            mp[arah].erase({dist, a});
            aktif[a] = false;
        }
        else {
            mp[arah].insert({dist, a});
            aktif[a] = true;
        }

        if (!mp[arah].empty()){
            int j = mp[arah].begin()->second;
            cnt[c[j]]++;
            if (cnt[c[j]] == 1){
                res++;
            }
        }

        cout << res << endl;
    }

}