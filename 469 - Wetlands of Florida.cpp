#include <bits/stdc++.h>
using namespace std;
#define int      long long
const int N = 100;
vector<string> g;
bool visited[N][N];
vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}, { -1, -1}, { -1, 1}, {1, -1}, {1, 1}};
int n, m, ans, _;

bool isValid(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m && !visited[i][j] && g[i][j] == 'W';
}

void dfs(int i, int j) {
    visited[i][j] = 1;
    ans++;
    for (auto &[x, y] : moves) {
        int child_i = i + x;
        int child_j = j + y;
        if (isValid(child_i, child_j)) dfs(child_i, child_j);
    }
}

void solve(int test)
{
    g.clear();
    string s;
    while (getline(cin, s) && s[0] != '\0') {
        if (s[0] == 'L' || s[0] == 'W') g.push_back(s);
        else {
            memset(visited, 0, sizeof visited);
            n = g.size();
            m = g[0].size();
            istringstream ss(s);
            string temp;

            bool flag = true;
            int x, y;
            while (ss >> temp) {
                if (flag) {
                    x = stoll(temp);
                    flag = false;
                }
                else y = stoll(temp);
            }

            ans = 0;
            dfs(x - 1, y - 1);
            cout << ans << '\n';
        }
    }
    if (_ != test) cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int test = 1;
    cin >> test;
    string s; getline(cin, s);
    cin.ignore();
    for (_ = 1; _ <= test; _++)
    {
        solve(test);
    }
    return 0;
}
