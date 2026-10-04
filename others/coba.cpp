#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n; 
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> banyak(n, 0);
    map<int, int> freq; // Menyimpan frekuensi angka yang sudah dilewati
    
    for(int i = 0; i < n; i++) {
        banyak[i] = freq[i]; 
        
        // Tambahkan elemen saat ini ke map frekuensi
        freq[a[i]]++; 
    }
    
    for(int i = 0; i < n; i++) {
        cout << i << " : " << banyak[i] << endl; 
    }
    
    return 0;
}