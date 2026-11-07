#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string konversiKeBiner(int angka){
    if (angka == 0) {
        return "0";
    }
    string biner;
    while (angka > 0) {
        if (angka % 2 == 1) {
            biner += '1';
        } else {
            biner += '0';
        }
        angka /= 2;
    }
    reverse(biner.begin(), biner.end());
    return biner;
}

int hitungNomorBit(int angka, int nomorBit){
    if(nomorBit < 0 || nomorBit > 1 || angka < 0) return -1;
    
    string biner = konversiKeBiner(angka);
    int jumlahBit = 0;
    for(char bit : biner){
        if(bit - '0' == nomorBit){
            jumlahBit++;
        }
    }
    return jumlahBit;
}
int main() {
    // Some testcases
    int hasil = hitungNomorBit(13, 0);
    cout << (hasil != -1 ? to_string(hasil) : "null") << '\n';

    hasil = hitungNomorBit(13,1);
    cout << (hasil != -1 ? to_string(hasil) : "null") << '\n';

    hasil = hitungNomorBit(13,2);
    cout << (hasil != -1 ? to_string(hasil) : "null") << '\n';
    return 0;
}
