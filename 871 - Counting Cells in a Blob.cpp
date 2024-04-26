#include <bits/stdc++.h>
using namespace std;
#define int      long long

const int N = 26;
vector<string> g;
bool visited[N][N];
int _, max_size, n, m;
vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}, { -1, -1}, { -1, 1}, {1, -1}, {1, 1}};

bool isValid(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m && !visited[i][j] && g[i][j] == '1';
}

void dfs(int i, int j) {
    visited[i][j] = 1;
    max_size++;
    for (auto &[x, y] : moves) {
        int child_i = i + x;
        int child_j = j + y;
        if (isValid(child_i, child_j)) dfs(child_i, child_j);
    }
}

void solve(int test)
{
    string s;
    g.clear();
    memset(visited, 0, sizeof visited);
    while (getline(cin, s) && s[0] != '\0') {
        // cout << s << '\n';
        g.push_back(s);
    }
    if (!g.size()) {
        _--;
        return;
    }
    int ans = 0;
    n = g.size();
    m = g[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && g[i][j] == '1') {
                max_size = 0;
                dfs(i, j);
                ans = max(ans, max_size);
                max_size = 0;
            }
        }
    }

    cout << ans << '\n';
    if (_ != test) cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int test = 1;
    cin >> test;
    cin.ignore();
    for (_ = 1; _ <= test; _++)
    {
        solve(test);
    }
    return 0;
}
