#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<char,ll> freq;
    string s; cin >> s;
    int n = s.length();
    ll total = 0;
    for(int i = 0 ; i < n ; i++){
        freq[s[i]] ++;
        total++;
    }
    
    ll totalVowel = freq['A'] + freq['E'] + freq['I'] + freq['U'] + freq['O'];
    ll countNG = min(freq['N'],freq['G']);
    ll totalConsonant = total - totalVowel;
    if(totalConsonant <= 1){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 3*min(totalVowel,totalConsonant/2);
    for(ll i = 0 ; i <= freq['Y'] ; i++){
        for(int j = 0 ; j <= countNG ; j++){
            // i merupakan jumlah Y yang tercatat sebagai vowel
            // maka, freq['Y'] - i adalah jumlah Y yang tercatata sebagai konsonan;
            ll curAns = 0;
            ll curVowel = totalVowel + i;
            ll curConsonant = totalConsonant - i;
            ll curNGPair = j;
            curConsonant -= 2*j;
            if(curConsonant < 0) continue;
            ll countPairWithNG = min(curNGPair/2,curVowel);
            ll sisaNGPair = curNGPair - 2 * countPairWithNG;
            ll sisaVowel = curVowel - countPairWithNG;
            curAns = 5 * countPairWithNG;
            ans = max(ans,curAns);
            if(sisaVowel == 0) continue;
            if(sisaNGPair == 0){
                curAns += 3 * min(sisaVowel,curConsonant/2);
            }
            if(sisaNGPair == 1){
                curConsonant++;
                curAns += 3 * min(sisaVowel,curConsonant/2) + 1;
            }
            ans = max(ans,curAns);

        }
    }
    cout << ans << endl;

    

    return 0;
}