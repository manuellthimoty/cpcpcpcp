// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// void solve(){
//     int n ; cin >> n ;
//     vector<ll> a(n);
//     for(int i = 0 ; i < n ; i){
//         cin >> a[i];
//     }

// }




// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t ; cin >> t ;
//     while(t--){ 
//         2 2 5 9 6 ;
//     }
// }
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

typedef long long ll;

// Fungsi untuk menghitung biaya minimum mengubah suatu array/segmen
// menjadi satu nilai yang optimal (median).
ll calculate_median_cost(const vector<ll>& segment) {
    if (segment.empty()) {
        return 0;
    }
    
    // Salin dan urutkan segmen
    vector<ll> sorted_segment = segment;
    sort(sorted_segment.begin(), sorted_segment.end());
    
    // Median adalah nilai optimal untuk meminimalkan sum(|X - a_i|)
    int n = sorted_segment.size();
    ll optimal_value = sorted_segment[n / 2]; // Ambil median bawah
    
    ll cost = 0;
    for (ll val : segment) {
        cost += abs(val - optimal_value);
    }
    return cost;
}

// Fungsi utama untuk menyelesaikan masalah
void solve() {
    int n;
    cin >> n;
    
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // --- KASUS 1: Array b terdiri dari SATU nilai X ---
    // Biaya optimal ditemukan dengan memilih X sebagai median dari seluruh array a.
    
    ll min_cost = calculate_median_cost(a);
    
    // --- KASUS 2: Array b terdiri dari DUA blok nilai X dan Y ---
    // Kita harus mencoba semua cara membagi array melingkar a menjadi dua segmen
    // (a_i, ..., a_{j-1}) dan (a_j, ..., a_{i-1}).
    
    // Untuk mempermudah perhitungan segmen melingkar, kita gandakan array a.
    vector<ll> a_doubled(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        a_doubled[i] = a[i % n];
    }
    
    // Kita iterasi semua kemungkinan titik potong *tunggal* (indeks j)
    // yang memisahkan segmen X dan Y. 
    // Segment X akan memiliki panjang k, Segment Y panjang n-k.
    
    // Kita harus mencoba semua kemungkinan pemisahan.
    // i: titik awal segmen X (0 sampai n-1)
    for (int i = 0; i < n; ++i) {
        // k: panjang segmen X (1 sampai n-1)
        for (int k = 1; k < n; ++k) { 
            // 1. Definisikan Segmen X: dimulai dari a[i], panjang k
            vector<ll> segment_x;
            for (int idx = i; idx < i + k; ++idx) {
                segment_x.push_back(a_doubled[idx]);
            }
            
            // 2. Definisikan Segmen Y: sisanya (panjang n-k), dimulai dari a[i+k]
            vector<ll> segment_y;
            for (int idx = i + k; idx < i + n; ++idx) {
                segment_y.push_back(a_doubled[idx]);
            }
            
            // 3. Hitung Biaya
            ll cost_x = calculate_median_cost(segment_x);
            ll cost_y = calculate_median_cost(segment_y);
            
            min_cost = min(min_cost, cost_x + cost_y);
        }
    }
    
    cout << min_cost << endl;
}

// Catatan: Main function untuk I/O test cases
int main() {
    // Optimasi I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}

/*
PENTING:
Kompleksitas dari solusi ini adalah O(t * n^3 log n) atau O(t * n^2 log n) 
karena loop O(n^2) di dalam solve() memanggil calculate_median_cost() O(n log n).
Dengan n hingga 2 * 10^5, ini akan menyebabkan Time Limit Exceeded (TLE).

Untuk mengatasi TLE, fungsi calculate_median_cost() harus ditingkatkan 
menjadi O(1) atau O(log n) per segmen menggunakan teknik Sliding Window Median 
dengan struktur data canggih (seperti dua heaps atau Persistent Segment Tree).
*/