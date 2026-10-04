#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define vll vector<ll>;
#define vint vector<int>;
#define input(a,l,r) for(int i = l ; i < r ; i++) cin >> a[i];
#define REP(i,l,r) for(int i = l ; i < r ; i++)
#define REPLL(i,l,r) for(ll i = l ; i < r ; i++)

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n), b(n);
    vector<int> count(n + 1, 0); // Untuk menghitung frekuensi angka 1 sampai n
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        count[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        count[b[i]]++;
    }
    
    // 1. Cek kondisi Mustahil (-1)
    // Jika ada angka yang total frekuensinya ganjil, maka tidak mungkin dibagi dua rata
    for (int i = 1; i <= n; i++) {
        if (count[i] % 2 != 0) {
            cout << -1 << "\n";
            return;
        }
    }
    
    // 2. Bangun Graf
    // adj[u] menyimpan pasangan {node_tujuan, index_edge}
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < n; i++) {
        adj[a[i]].push_back({b[i], i});
        adj[b[i]].push_back({a[i], i});
    }
    
    vector<bool> used_edge(n, false);
    vector<int> swaps;
    
    // 3. DFS untuk mencari Eulerian Circuit
    auto dfs = [&](auto& self, int u) -> void {
        while (!adj[u].empty()) {
            auto [v, idx] = adj[u].back();
            adj[u].pop_back(); // Hapus edge agar prosesnya O(N)
            
            if (used_edge[idx]) continue; // Jika edge ini sudah dilewati, lewati
            
            used_edge[idx] = true;
            
            // Kita berjalan dari u ke v. 
            // Artinya kita mendedikasikan 'u' untuk array 'a' dan 'v' untuk array 'b'.
            // Cek apakah di posisi aslinya sudah sesuai (a[idx] == u dan b[idx] == v)?
            // Jika tidak, berarti aslinya terbalik, jadi kita harus swap!
            if (a[idx] != u || b[idx] != v) {
                swaps.push_back(idx);
            }
            
            self(self, v); // Lanjutkan perjalanan dari v
        }
    };
    
    // 4. Jalankan DFS dari setiap node yang memiliki edge
    // (Karena graf bisa terputus / disconnected components)
    for (int i = 1; i <= n; i++) {
        dfs(dfs, i);
    }
    
    // 5. Cetak Hasil
    cout << swaps.size() << "\n";
    for (int i = 0; i < swaps.size(); i++) {
        // Ingat soal meminta 1-based index (1 <= i <= n)
        cout << swaps[i] + 1 << (i == swaps.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Optimasi I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}