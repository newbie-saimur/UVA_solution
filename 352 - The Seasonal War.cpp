#include <bits/stdc++.h>
using namespace std;
#define int      long long

const int N = 26;
vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}, { -1, 1}, { -1, -1}, {1, -1}, {1, 1}};
vector<string> g(N);
bool visited[N][N];
int n, _;

bool isValid(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < n;
}

void dfs(int i, int j) {
    visited[i][j] = true;
    for (auto [x, y] : moves) {
        int child_i = i + x;
        int child_j = j + y;
        if (!isValid(child_i, child_j)) continue;
        if (visited[child_i][child_j]) continue;
        if (g[child_i][child_j] == '1') dfs(child_i, child_j);
    }
}

void solve()
{
    while (cin >> n) {
        g.clear();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            cin >> g[i];
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && g[i][j] == '1') {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << "Image number " << _ << " contains " << cnt << " war eagles.\n";
        _++;
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
