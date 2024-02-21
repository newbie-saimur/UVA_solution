#include <bits/stdc++.h>
using namespace std;
#define int    long long
int _;

bool grid[501][501];

void solve()
{
    int w, h, n;
    while (cin >> w >> h >> n && w) {
        int total = 0;
        for (int i = 0; i < n; i++) {
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            if (x2 < x1) swap(x2, x1);
            if (y2 < y1) swap(y2, y1);
            for (int j = y1 - 1; j < y2; j++) {
                for (int k = x1 - 1; k < x2; k++) {
                    grid[j][k] = true;
                }
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (!grid[i][j]) total++;
                else grid[i][j] = false;
            }
        }
        if (total == 0) cout << "There is no empty spots.\n";
        else if (total == 1) cout << "There is one empty spot.\n";
        else cout << "There are " << total << " empty spots.\n";
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
