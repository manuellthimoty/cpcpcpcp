#include <bits/stdc++.h>
using namespace std;

class Klasemen{
    private:
        vector<string> teams;
        map<string,int> points;
    public:
        Klasemen(const vector<string>& teams) {
            for (const string& team : teams) {
                points[team] = 0;
            }
        }

        void catatPermainan(const string& klubKandang, const string& klubTandang, const string& skor) {
            if (!points.count(klubKandang) || !points.count(klubTandang)) {
                cout << "Pencatatan tidak valid: klub tidak terdaftar!" << '\n';
                return;
            }
            if (klubKandang == klubTandang) {
                cout << "Pencatatan tidak valid: kedua klub harus berbeda!" << '\n';
                return;
            }
            int skorKandang = 0;
            int skorTandang = 0;
            bool ketemuPembatas = false;

            if (skor.empty() || skor.front() == ':' || skor.back() == ':') {
                cout << "Format skor tidak valid!" << '\n';
                return;
            }

            for (char karakter : skor) {
                if (karakter == ':' && !ketemuPembatas) {
                    ketemuPembatas = true;
                    continue;
                }

                if (karakter < '0' || karakter > '9') {
                    cout << "Format skor tidak valid!" << '\n';
                    return;
                }

                if (!ketemuPembatas) {
                    skorKandang = skorKandang * 10 + (karakter - '0');
                } else {
                    skorTandang = skorTandang * 10 + (karakter - '0');
                }
            }

            if (!ketemuPembatas) {
                cout << "Format skor tidak valid!" << '\n';
                return;
            }
            if (skorKandang == skorTandang) {
                points[klubKandang]++;
                points[klubTandang]++;
            } else if (skorKandang > skorTandang) {
                points[klubKandang] += 3;
            } else {
                points[klubTandang] += 3;
            }
        }


        vector<pair<string, int>> cetakKlasemen() const {
            vector<pair<string, int>> klasemen(points.begin(), points.end());
            sort(klasemen.begin(), klasemen.end(),
                [](const auto& a, const auto& b) {
                    if (a.second != b.second) {
                        return a.second > b.second;
                    }
                    return a.first < b.first;
                });

            return klasemen;
        }

        string ambilPeringkat(int nomorPeringkat) const {
            if (nomorPeringkat < 1 ||
                nomorPeringkat > (int)(points.size())) {
                return "";
            }
            const auto klasemen = cetakKlasemen();
            return klasemen[nomorPeringkat - 1].first;
        }


};


int main() {
    // testcases
    Klasemen klasemen({"Liverpool", "Chelsea", "Arsenal"});
    klasemen.catatPermainan("Arsenal", "Liverpool", "2:1");
    klasemen.catatPermainan("Arsenal", "Chelsea", "1:1");
    klasemen.catatPermainan("Chelsea", "Arsenal", "0:3");
    klasemen.catatPermainan("Chelsea", "Liverpool", "3:2");
    klasemen.catatPermainan("Liverpool", "Arsenal", "2:2");
    klasemen.catatPermainan("Liverpool", "Chelsea", "0:0");

    const auto hasil = klasemen.cetakKlasemen();
    cout << "[";
    for (int i = 0; i < (int)(hasil.size()); i++) {
        if (i > 0) cout << ", ";
        cout << "'" << hasil[i].first << "' => " << hasil[i].second;
    }
    cout << "]\n";

    cout << "Peringkat 2: " << klasemen.ambilPeringkat(2) << '\n';

    return 0;

}
