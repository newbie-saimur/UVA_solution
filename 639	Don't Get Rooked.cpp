#include <bits/stdc++.h>
using namespace std;
#define int      long long
int _;

vector<string> g(4);
bool taken[4][4];
int cnt, n;

bool isValid(int x, int y) {
    return x >= 0 and y >= 0 and x < n and y < n;
}

bool canPlace(int x, int y) {
    if (isValid(x, y)) {
        if (g[x][y] == 'X') return false;

        int xx = x, yy = y;

        while (isValid(x, y)) {
            if (taken[x][y]) return false;
            if (g[x][y] == 'X') break;
            x--;
        }

        while (isValid(xx, yy)) {
            if (taken[xx][yy]) return false;
            if (g[xx][yy] == 'X') break;
            yy--;
        }

        return true;
    }
    return false;
}

void calculate(int x, int y, int temp) {
    if (y == n) {
        x++; y = 0;
    }
    cnt = max(cnt, temp);
    if (x >= n) return;
    for (int i = x; i < n; i++) {
        for (int j = y; j < n; j++) {
            if (canPlace(i, j)) {
                taken[i][j] = 1;
                calculate(i, j + 1, temp + 1);
                taken[i][j] = 0;
                calculate(i, j + 1, temp);
            }
        }
        y = 0;
    }
}

void solve()
{
    memset(taken, 0, sizeof taken);
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) cin >> g[i];
        cnt = 0;
        calculate(0, 0, 0);
        cout << cnt << '\n';
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
