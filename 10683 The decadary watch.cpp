#include <bits/stdc++.h>
using namespace std;
#define int    long long
int _;

void solve()
{
    string s;
    while (cin >> s) {
        int hour = 10 * (s[0] - '0') + (s[1] - '0');
        int min = 10 * (s[2] - '0') + (s[3] - '0');
        int sec = 10 * (s[4] - '0') + (s[5] - '0');
        int cc = 10 * (s[6] - '0') + (s[7] - '0');

        int total = cc * 10 + sec * 1000 + min * 60000 + hour * 3600000;

        hour = total / 8640000;
        total %= 8640000;
        min = total / 86400;
        total %= 86400;
        sec = total / 864;
        total %= 864;
        cc = total * 100 / 864;
        printf("%01lld%02lld%02lld%02lld\n", hour, min, sec, cc);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int test = 1;
    //cin>>test;
    for (_ = 1; _ <= test; _++)
    {
        solve();
    }
    return 0;
}
