#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    ll n = s.size();
    unordered_map<char,ll> freq;
    for(ll i = 0 ; i < n ; i++){
        freq[s[i]]++;
    }
    ll countOdd = 0;
    vector <char> oddList;
    vector <char> evenList;
    ll totalEvenlen = 0;
    for(auto &f : freq ){
        if(f.second % 2 == 1){
            oddList.push_back(f.first);
            countOdd ++;
        }
        else{
            totalEvenlen += f.second;
            evenList.push_back(f.first);
        }
    }
    if(evenList.empty()){
        cout << countOdd <<endl;
        for(auto c : oddList){
            ll len = freq[c];
            string strAns(len,' ');
            for(ll i = 0 ; i < len ; i++){
                strAns[i] = c;
            }
            cout << strAns << endl;
        }
        return 0;
    }
    ll left = 0;
    ll right = totalEvenlen - 1;
    if(countOdd > 0){
        right += freq[oddList[0]];
    }
    ll i = 0;
    char curChar = evenList[0];
    ll freqCur = freq[curChar];
    string evenAns(right - left + 1, ' '); 
    while(left <= right){
        evenAns[left] = curChar;
        evenAns[right] = curChar;
        freqCur -= 2;
        if(freqCur <= 0){
            i++;
            if(i < (ll)evenList.size()){
                curChar = evenList[i];
                freqCur = freq[curChar];
            }
            else if(countOdd > 0){
                curChar = oddList[0];
                freqCur = freq[curChar];
            }
        }
        left++;
        right--;
    }
    if(countOdd == 0){
        countOdd = 1;
    }
    cout  << countOdd << endl;
    cout << evenAns << endl;
    if(countOdd > 1){
        for(ll i = 1; i < (ll)oddList.size() ; i++ ){
            char currentChar = oddList[i];
            string oddString(freq[currentChar],' ');
            for(ll j = 0 ; j < freq[currentChar] ; j++){
                oddString[j] = currentChar;
            }
            cout << oddString << endl;
        }
    }
    return 0;
}