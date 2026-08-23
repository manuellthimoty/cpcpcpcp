#include <bits/stdc++.h>
using namespace std;

long long t, n, h, w;

main()
{
    t = 1;
    // cin >> t;
    while (t--){
        cin >> n;
        if (n % 2 == 0){
            h = n / 2;
            w = n + 1;
        }
        else {
            h = (n + 1) / 2;
            w = n;
        }
        while (h % 2 == 0 && (w * 2 <= 2026)){
            h /= 2;
            w *= 2;
        }
        while (h % 3 == 0 && (w * 3 <= 2026)){
            h /= 3;
            w *= 3;
        }
        while (h % 5 == 0 && (w * 5 <= 2026)){
            h /= 5;
            w *= 5;
        }
        if ((h > 5) && (h * w) > 2026){
            cout << "-1" << endl;
        }
        else {
            int res = n, k = n;
            if ((h * w) <= 2026){
                cout << (h * w) << " " << 1 << endl;
                for (int i = 0; i < w * h; i++){
                    cout << res;
                    k--;
                    if (k == 0){
                        res--;
                        k = res;
                    }
                    if (i != ((h*w)-1)){
                        cout << " ";
                    }
                    cout << endl;
                }      
            }
            else {
                cout << h << " " << w;
                for (int i = 0; i < w; i++){
                    for (int j = 0; j < h; j++){
                        cout << res;
                        k--;
                        if (k == 0){
                            res--;
                            k = res;
                        }
                        if (j != (h-1)){
                            cout << " ";
                        }
                    }
                    cout << endl;
                }
            }
        }
    }
}
