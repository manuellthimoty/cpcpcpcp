#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // your code
    int x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    cin >> x5 >> y5 >> x6 >> y6;
    //Pengecekan jika ada blok yang ngecover semua;
    if(x3<=x1 && y3 <=y1 && x4>=x2 && y4>=y2){
        cout << "NO";
    }
    else if(x5<=x1 && y5 <=y1 && x6>=x2 && y6>=y2){
        cout << "NO";
    }
    else{
        //Tidak ada yang mengcover semua;
        //Bagi 2 kasus, cover atas bawah, dan kanan kiri
        // Cover atas bawah
        if(x3<=x1 && y3>y1 && x4>=x2 && y4 >=y2){
            //harus ada yang cover di bawah
            if(x5<=x1 && x6 >= x2 && y5<=y1 && y6 >=y3){
                cout << "NO";
            }
            else{
                cout << "YES";
            }
        }
        else if(x5<=x1 && y5>y1 && x6>=x2 && y6 >=y2){
            if(x3<=x1 && x4 >= x2 && y3<=y1 && y4 >=y5){
                cout << "NO";
            }
            else{
                cout << "YES";
            }
        }
        //Cover kiri kanan
        else if(x3<=x1 && y3 <=y1 && x4 > x1 && y4>=y2){
            //Harus ada cover di kanan
            if(x5<=x4 && y5 <= y1 && x6 >=x2 && y6>=y2){
                cout << "NO";
            }
            else{
                cout << "YES";
            }
        }
        else if(x5<=x1 && y5 <=y1 && x6 > x1 && y6>=y2){
            if(x3<=x6 && y3 <= y1 && x4 >=x2 && y4>=y2){
                cout <<"NO";
            }
            else{
                cout << "YES";
            }
        }
        else{
            cout << "YES";
        }
    }
}
