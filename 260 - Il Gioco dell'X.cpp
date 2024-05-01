#include <bits/stdc++.h>
using namespace std;
#define int      long long
int _;
const int N = 205;
vector<string> g(N);
bool visited[N][N], vis[N];
int n;

vector<pair<int, int>> moves = {
    { -1, -1}, { -1, 0}, {0, -1}, {0, 1}, {1, 0}, {1, 1}
};

bool isValid(int i, int j) {
    return i >= 0 and j >= 0 and i < n and j < n and !visited[i][j] and g[i][j] == 'b';
}

void dfs(int i, int j) {
    visited[i][j] = true;
    vis[i] = true;
    for (auto [x, y] : moves) {
        if (isValid(i + x, j + y)) {
            dfs(i + x, j + y);
        }
    }
}

void solve()
{
    while (cin >> n && n) {
        cout << _ << " ";
        for (int i = 0; i < n; i++) cin >> g[i];
        bool found_B = false;
        for (int i = 0; i < n; i++) {
            if (g[0][i] == 'b' && !visited[0][i]) {
                memset(visited, 0, sizeof visited);
                memset(vis, 0, sizeof vis);
                dfs(0, i);
                int cnt = 0;
                for (int i = 0; i < n; i++) {
                    if (vis[i] == 1) cnt++;
                }
                if (cnt == n) {
                    cout << "B\n";
                    found_B = true;
                    break;
                }
            }
        }
        if (!found_B) cout << 'W' << '\n';
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
