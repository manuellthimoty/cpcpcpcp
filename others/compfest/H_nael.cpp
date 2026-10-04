#include <bits/stdc++.h>
using namespace std;
template <typename T>
void _debug(const char *name, T &&value)
{
    cerr << name << " = " << value << endl;
}
template <typename T, typename... Args>
void _debug(const char *names, T &&value, Args &&...args)
{
    const char *comma = strchr(names, ',');
    cerr.write(names, comma - names) << " = " << value << " | ";
    _debug(comma + 1, args...);
}

#define debug(...) _debug(#__VA_ARGS__, __VA_ARGS__)
#define ll long long
#define REP(i, n) for (int i = 0; i < n; i++)
#define RREP(i, n) for (int i = n - 1; i >= 0; i--)
#define mod 1000000007

void solve()
{
    int n;
    cin >> n;
    // cout << i << ": ";
    bool isPrime = true;
    ll total = n * (n + 1) / 2;
    int x, y;
    for (int j = 1; j <= n / 2; j++)
    {
        if (total % j == 0 && (total / j) <= (2026))
        {
            cout << j << " " << total / j << "\n";
            isPrime = false;
            x = j;
            y = total / j;
            break;
        }
    }
    if (isPrime)
        cout << "-1" << '\n';
    else
    {
        int counter = 0;
        for (int i = n; i > 0; i--)
        {
            for (int j = i; j > 0; j--)
            {
                cout << i << " ";
                counter++;
                if (counter == y)
                {
                    counter = 0;
                    cout << '\n';
                }
            }
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test = 1;
    // cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}