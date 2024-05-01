#include <bits/stdc++.h>
using namespace std;
#define int      long long
int _;

void solve()
{
    int n, m;
    while (cin >> n >> m) {
        map<int, vector<int>> mp;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            mp[x].push_back(i);
        }
        while (m--) {
            int x, y; cin >> x >> y;
            if (mp[y].size() < x) cout << 0 << '\n';
            else cout << mp[y][x - 1] << '\n';
        }
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
