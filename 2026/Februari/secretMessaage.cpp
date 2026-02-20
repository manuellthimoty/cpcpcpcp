#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string convertTakeFirst(const vector<bitset<26>>& ans) {
    string result;

    for (const auto& bs : ans) {
        int idx = bs._Find_first();   // cari bit pertama yang aktif
        
        if (idx < 26) {
            result += char('a' + idx);
        } else {
            // kalau kosong (seharusnya tidak terjadi kalau sudah dicek)
            result += '?';
        }
    }

    return result;
}

vector<bitset<26>> ans;


bool cek(const vector<string>& grid, int step, 
         vector<bitset<26>>& hasil) {

    int n = grid.size();
    int m = grid[0].size();

    hasil.clear();
    hasil.resize(step);

    for (int i = 0; i < step; i++) {
        bitset<26> current;
        current.set();

        for (int col = i; col < m; col += step) {
            bitset<26> columnSet;

            for (int row = 0; row < n; row++) {
                columnSet.set(grid[row][col] - 'a');
            }

            current &= columnSet;

            if (current.none()) {
                return false;
            }
        }

        hasil[i] = current;
    }
    return true;
}


void solve(){
    int n,k ; cin >> n >> k;
    int mnlen = 1e9;
    vector<string> input;
    for(int i = 0 ; i < k ; i++){
        string s ; cin >> s;
        input.push_back(s);
    }
    for(int i =  1 ; i * i <= n ; i++){
        if(n % i == 0){
            int cur = i;
            vector<bitset<26>> curres;
            if(cek(input,i,curres)){
                if(i < mnlen){
                    mnlen = i;
                    ans = curres;
                }
            }
            if(i != n/i){
                vector<bitset<26>> curres2;
                if(cek(input, n/i, curres2)){
                    if(n/i < mnlen){
                        mnlen = n/i;
                        ans = curres2;
                    }
                }
            }
        }
    }
    string final;
    
    string cu = convertTakeFirst(ans);
    for(int i = 0 ; i < n/mnlen ; i++){
        final += cu;
    }
    cout << final<< endl;
    // cout << mnlen << endl;
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
