#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long T;
    cin >> T;
    long long origin=T;
    vector<long long> result;
    while(T--){
        long long n,m;
        cin >> n >> m;
        vector<long long> a(n),b(m),c(m);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        for(int i=0;i<m;i++){
            cin >> b[i];
        }
        for(int i=0;i<m;i++){
            cin >> c[i];
        }
        priority_queue<long long> pq;
        for(long long x : a) pq.push(x);
        vector<pair<long long,long long>> paired(m);
        for(int i=0;i<m;i++){
            paired[i]={b[i],c[i]};  
        }
        long long count=0;
        sort(paired.begin(), paired.end());//Sekarang b_i dan c_i udah terurut menaik berdasarkan b_i
        //Kill yang c_i nya bukan 0 dulu,
        for(auto monster : paired){
            if(monster.second==0){
                continue;
            }
            long long hp=monster.first;
            long long bonus=monster.second;
            long long sword=pq.top();
            if(sword>=hp){
                pq.pop();
                pq.push(max(sword,bonus));
                count++;
            }
        }
        //Waktu ninjau yang 0, kerjakan dari minimum, jaci reverse pq
        vector<long long> temp;
        while (!pq.empty()) {
            temp.push_back(pq.top());
            pq.pop();
        }
        sort(temp.begin(), temp.end()); // kecil → besar
        queue<long long> new_pq;
        for (auto x : temp) {
            new_pq.push(x); // sekarang urutan dari kecil ke besar
        }


        // restore the priority_queue from the snapshot
        long long index=0;
        long long len=paired.size();
        while(!(new_pq.empty()) && index<=len){
            pair<long long,long long> monster = paired[index];
            if(monster.second!=0){
                index++;
                continue;
            }
            if(new_pq.front() >= monster.first){
                count++;
                index++;
            }
            else{
                new_pq.pop();
            }
        }
        result.push_back(count);
    }

    for(auto x : result){
        cout << x << endl;
    }
}




