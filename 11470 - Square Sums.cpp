#include <bits/stdc++.h>
using namespace std;
#define int      long long
int _;

void solve()
{
    int n;
    while (cin >> n && n) {
        cout << "Case " << _ << ": ";
        int a[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        int sum = 0;
        for (int i = 0; i < (n + 1) / 2; i++) {
            for (int j = i; j < n - i ; j++) {
                sum += a[j][i] + a[j][n - i - 1];
            }
            for (int j = i + 1; j < n - (i + 1); j++) {
                sum += a[i][j] + a[n - i - 1][j];
            }
            if (i != (n + 1) / 2 - 1) cout << sum << ' ';
            else if (n & 1)cout << sum - a[n / 2][n / 2] << '\n';
            else cout << sum << '\n';
            sum = 0;
        }
        _++;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int test = 1;
    // cin >> test;
    for (_ = 1; _ <= test; _++)
    {
        solve();
    }
    return 0;
}
