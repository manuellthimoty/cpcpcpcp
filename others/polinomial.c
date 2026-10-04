#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    long long y[N];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &y[i]);
    }

    int degree = 0;
    int last_sign = 0;      // -1 turun, 0 datar, +1 naik
    int first_sign_set = 0; // tanda pertama sudah diset atau belum

    for (int i = 1; i < N; i++) {
        long long d = y[i] - y[i - 1];
        int sign = (d > 0) ? 1 : (d < 0) ? -1 : 0;

        if (!first_sign_set) {
            last_sign = sign;
            first_sign_set = 1;
            continue;
        }

        // Jika arah berubah, selalu hitung perubahan
        if (sign != last_sign) {
            degree++;
            // Kalau dari nonzero ke 0 atau sebaliknya, hitung tambahan lagi
            if (sign == 0 || last_sign == 0)
                degree++;
            last_sign = sign;
        }
    }

    if (!first_sign_set || (degree == 0 && last_sign == 0))
        printf("0\n");
    else
        printf("%d\n", degree);
    return 0;
}
